#! /usr/bin/env python
# -*- coding: utf-8 -*-

'''
class Student(object):

    def __init__(self):
        self.__student = {}

    def InputScore(self):
         name = raw_input("Stuent name:")

         while name != '':
            score = raw_input("Score = ")
            try:
                self.__student[name] = int(score)
            except Exception, e:#有问题执行此
                print "Invalid Score!"
            name = raw_input("Stuent name:")

    def display(self):

        for i in self.__student:#字典总是无序的
            print "Name:%s,Score:%d"%(i,self.__student[i])


if __name__ == "__main__":
    a = Student()
    a.InputScore()
    a.display()

'''
class c1 (object):

    def __init__(self):#显式调用才会调用此，于C++不同，C++隐式也会调用基类默认的构造函数
        print "c1!"

    def display(self):
        print "c1_print!"

class c2(c1):

    def __init__(self):
        print "c2!"
        c1.__init__(self)#显式调用c1的__init__函数

if __name__ == "__main__":
    c = c2()
    c.display()