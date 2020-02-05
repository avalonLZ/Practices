class ctes:
    def __init__(self, x=1, y=2):
        print "x=%d,y=%d" % (x, y)

    def __call__(self, *args, **kwargs):
        print args
        for i in args:
            print(i)

        print("call ok")

    @staticmethod
    def my_print(str):
        print "lz:%s" % str


def func():
    t=ctes(11,12)
    t(1,2,3,4)

def func1(l1, l2, **kargs):
    print l1,l2,kargs

info={"l1":"lz1", "l2":"lz2", "l3":"lz3", "l4":"lz4"}
info1={"l1":"lz1"}

func1(**info)
#func1(**info1)
def func2(l1,l2,l3,*args):
    print l1,l2,l3,args
info2=(1,2,3, {"lz":"123"})
func2(*info2)

t=ctes()
t.my_print("l456")
ctes.my_print('123lz')

'''
if __name__=='__main__':
    print "123"
    func()
    print "1111111111lz111111"
'''