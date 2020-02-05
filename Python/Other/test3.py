
class Parents1():
    def __init__(self):
        self.__number = 1
        self.n = 1

    def p_print(self):
        print(self.__number, self.n)

class Child1(Parents1):
    def __init__(self):
        Parents1.__init__(self)
        self.__number \
            = 2
        self.n = 2
    def c_print(self):
        print(self.__number,
              self.n)

a = Child1()
a.p_print()
a.c_print()

