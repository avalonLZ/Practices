class My_Exception(Exception):
    pass

def exception_test():
    print("123")
    raise Exception
    print("456")

exception_test()