/*eg,存在如下json格式的文件json.file
{
  "selected_ports": {
    "eno1": {
      "key": 63,
      "port": 19,
      "port_priority": 32768,
      "state": 61,
      "system": "a8:0c:ca:af:d2:73",
      "system_priority": 32768
    },
    "eno2": {
      "key": 63,
      "port": 22,
      "port_priority": 32768,
      "state": 61,
      "system": "a8:0c:ca:af:d2:73",
      "system_priority": 32768
    }
  }
}
*/

//获取某个json文件中的全部内容
//使用完成后记得需要用json_decref释放
json_t *json_load_file(void)
{
	json_error_t error;
	json_t *json_content;

	json_content = json_load_file("json.file", 0, &error);
	if(!g_lacp_upg.sel_ports_info)
		printf("Upgrading json load file failed, line:%d, err:%s\n", error.line, error.text);
	
	return json_content;
}

//销毁某个从json文件读取出的内容
void destroy_json(json_t *json_content)
{
	json_decref(json_content);
}

//key，value结构的json，遍历所有key和value
uint32_t foreach_count(json_t *json_content)
{
	const char *key;
	json_t *value;
	json_t *sel_ports;
	uint32_t count = 0;

	sel_ports = json_object_get(json_content, "selected_ports");
	if (!sel_ports)
		return count;

	json_object_foreach(sel_ports, key, value)
		count++;

	return count;
}

//判断某些key是否存在
bool key_is_exist(json_t *json_content, char *key)
{
	json_t *sel_port;
	json_t *sel_ports;

	sel_ports = json_object_get(json_content, "selected_ports");
	sel_port = json_object_get(sel_ports, key);
	if(!sel_port)
		return false;

	return true;
}

//获取key对应对应的value，并对其进行转换
struct info {
	uint16_t		system_priority;
	uint8_t			system[ETH_ALEN]; /* ID */
	uint16_t		key;
	uint16_t		port_priority;
	uint16_t		port; /* ID */
	uint8_t			state;
};
void transform_value(json_t *json_content, char *key)
{
	json_t *value;
	json_t *sel_port;
	json_t *sel_ports;
	const char *system_mac;
	struct info tmp_info;

	sel_ports = json_object_get(g_lacp_upg.sel_ports_info, "selected_ports");
	sel_port = json_object_get(sel_ports, key);

	value = json_object_get(sel_port, "key");
	tmp_info.key = htons(json_integer_value(value));

	value = json_object_get(sel_port, "port");
	tmp_info.port = htons(json_integer_value(value));

	value = json_object_get(sel_port, "port_priority");
	tmp_info.port_priority = htons(json_integer_value(value));

	value = json_object_get(sel_port, "state");
	tmp_info.state = json_integer_value(value);

	value = json_object_get(sel_port, "system_priority");
	tmp_info.system_priority = htons(json_integer_value(value));

	value = json_object_get(sel_port, "system");
	system_mac = json_string_value(value);
	sscanf(system_mac, "%2hhx:%2hhx:%2hhx:%2hhx:%2hhx:%2hhx",
			tmp_info.system, tmp_info.system + 1, tmp_info.system + 2,
			tmp_info.system + 3, tmp_info.system + 4, tmp_info.system + 5);

	printf("%s: Upgrading the partner info is: "
			"system_priority:%u, key:%u, port_priority:%u, "
			"port:%u, state:%u, "
			"system:%02x:%02x:%02x:%02x:%02x:%02x\n",
			ifname, ntohs(tmp_info.system_priority), ntohs(tmp_info.key),
			ntohs(tmp_info.port_priority), ntohs(tmp_info.port), tmp_info.state,
			tmp_info.system[0], tmp_info.system[1], tmp_info.system[2],
			tmp_info.system[3], tmp_info.system[4], tmp_info.system[5]);
}
