class Test_return():
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def t_print(self):
        print(self.a, self.b, self.c)

def test_return():

    #返回一个自定义的类
    return Test_return(11,22,33)

def main():
    t = test_return()
    t.t_print()
    t.c = 10
    t.t_print()
main()