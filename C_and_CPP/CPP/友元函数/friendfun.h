/*************************************************************************
	> File Name: friendfun.h
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 10:52:18 PM PDT
 ************************************************************************/

#ifndef _FRIENDFUN_H
#define _FRIENDFUN_H

class Friendfun
{
    private:
        std::string i;
    public:
        Friendfun();
        void fprint();
        friend void change(Friendfun &f);//友元函数声明
};

#endif
