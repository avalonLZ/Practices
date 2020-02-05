class Ops():
    def option_get(self, *args, **kwargs):
        print('exec option_get, INPUT args:%s, kwargs:%s' % (args, kwargs))
        return

    def option_create(self, *args, **kwargs):
        print('exec option_create, INPUT args:%s, kwargs:%s' % (args, kwargs))
        return

    def option_update(self, *args, **kwargs):
        print('option_update, INPUT args:%s, kwargs:%s' % (args, kwargs))
        return

    def option_delete(self, *args, **kwargs):
        print('option_delete, INPUT args:%s, kwargs:%s' % (args, kwargs))
        return

class Iface():
    def __init__(self, *args, **kwargs):

        if len(args) == 1:
            print('ok, args:%s' % (args))
        else:
            return

        self.__ops = Ops()

    def get(self, *args, **kwargs):
        return self.__ops.option_get(*args, **kwargs)

class Ethx(Ops):
    def option_get(self, *args, **kwargs):
        print('exec ethx option_get, INPUT args:%s, kwargs:%s' % (args, kwargs))

        for i in range(0, len(args)):
            print('index:%d, value:%s' % (i, args[i]))

        return

def main():
    iface = Iface(123)
    iface.get(11,22,33,44)

    ethx = Ethx()
    ethx.option_get(11,22,33,44)

main()