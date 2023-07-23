// SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause)
/* Copyright (c) 2022 Hengqi Chen */
#include <signal.h>
#include <unistd.h>
#include <linux/if_link.h>
#include "tc.skel.h"
#include <bpf/bpf.h>

#define MAX_INDEX 2
struct bpf_tc {
	struct bpf_tc_hook hook;
	struct bpf_tc_opts opts;
	bool created;
};
static struct bpf_tc g_bpf_tc[MAX_INDEX][MAX_INDEX];

static volatile sig_atomic_t exiting = 0;

static void sig_int(int signo)
{
	exiting = 1;
}

static int libbpf_print_fn(enum libbpf_print_level level, const char *format, va_list args)
{
	return vfprintf(stderr, format, args);
}

int main(int argc, char **argv)
{
	int i = 0;
	int err;
	__u32 curr_prog_id = 0;
	__u32 ifindex[MAX_INDEX] = {122,123};
	__u32 if_xdp[MAX_INDEX] = {0};

	libbpf_set_print(libbpf_print_fn);

	struct tc_bpf *skel;
	skel = tc_bpf__open_and_load();
	if (!skel) {
		fprintf(stderr, "Failed to open BPF skeleton\n");
		return 1;
	}

	__u32 key = 0;
	__u32 ac_ifindex = ifindex[0];
	//正式代码，需要init下map array
	bpf_map__update_elem(skel->maps.active_port, &key, sizeof(key), &ac_ifindex, sizeof(ac_ifindex), BPF_ANY);

	for (i = 0; i < MAX_INDEX; i++) {
		//XDP_FLAGS_UPDATE_IF_NOEXIST，驱动有实现ndo_bpf则在驱动处就执行，否则将在协议栈处执行
		bpf_xdp_attach(ifindex[i], bpf_program__fd(skel->progs.tc_ingress), XDP_FLAGS_UPDATE_IF_NOEXIST, NULL);
		struct bpf_prog_info info = {};
		__u32 info_len = sizeof(info);
		bpf_obj_get_info_by_fd(bpf_program__fd(skel->progs.tc_ingress), &info, &info_len);
		if_xdp[i] = info.id;

		memset(&g_bpf_tc[i][1], 0, sizeof(struct bpf_tc));
		g_bpf_tc[i][1].hook.sz = sizeof(struct bpf_tc_hook);
		g_bpf_tc[i][1].hook.ifindex = ifindex[i];
		g_bpf_tc[i][1].hook.attach_point = BPF_TC_EGRESS;
		err = bpf_tc_hook_create(&g_bpf_tc[i][1].hook);
		if (!err)
			g_bpf_tc[i][1].created = true;
		if (err && err != -EEXIST) {
			fprintf(stderr, "+++++++Failed to create TC hook: %d\n", err);
			goto cleanup;
		}


		g_bpf_tc[i][1].opts.sz = sizeof(struct bpf_tc_opts);
		g_bpf_tc[i][1].opts.handle = 1;
		g_bpf_tc[i][1].opts.priority = 1;
		g_bpf_tc[i][1].opts.prog_fd = bpf_program__fd(skel->progs.tc_egress);
		err = bpf_tc_attach(&g_bpf_tc[i][1].hook, &g_bpf_tc[i][1].opts);
		if (err) {
			fprintf(stderr, "+++++++Failed to attach TC: %d\n", err);
			goto cleanup;
		}
	}

	if (signal(SIGINT, sig_int) == SIG_ERR) {
		err = errno;
		fprintf(stderr, "Can't set signal handler: %s\n", strerror(errno));
		goto cleanup;
	}

	printf("Successfully started! Please run `sudo cat /sys/kernel/debug/tracing/trace_pipe` "
	       "to see output of the BPF program.\n");

	while (!exiting) {
		fprintf(stderr, ".");
		sleep(1);
	}

	for (i = 0; i < MAX_INDEX; i++) {
		bpf_xdp_query_id(ifindex[i], XDP_FLAGS_UPDATE_IF_NOEXIST, &curr_prog_id);
		if (if_xdp[i] == curr_prog_id) {
			bpf_xdp_detach(ifindex[i], XDP_FLAGS_UPDATE_IF_NOEXIST, NULL);
		}

		g_bpf_tc[i][1].opts.flags = g_bpf_tc[i][1].opts.prog_fd = g_bpf_tc[i][1].opts.prog_id = 0;
		err = bpf_tc_detach(&g_bpf_tc[i][1].hook, &g_bpf_tc[i][1].opts);
		if (err) {
			fprintf(stderr, "++++++Failed to detach TC: %d\n", err);
			goto cleanup;
		}
	}

cleanup:
	for (i = 0; i < MAX_INDEX; i++) {
		bpf_xdp_query_id(ifindex[i], XDP_FLAGS_UPDATE_IF_NOEXIST, &curr_prog_id);
		if (if_xdp[i] == curr_prog_id) {
			bpf_xdp_detach(ifindex[i], XDP_FLAGS_UPDATE_IF_NOEXIST, NULL);
		}

		if (g_bpf_tc[i][1].created) {
			bpf_tc_hook_destroy(&g_bpf_tc[i][1].hook);
		}
	}
	tc_bpf__destroy(skel);
	return -err;
}
