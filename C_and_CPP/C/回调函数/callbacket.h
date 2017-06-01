/*************************************************************************
	> File Name: callbacket.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 19时00分59秒
 ************************************************************************/

#ifndef _CALLBACKET_H
#define _CALLBACKET_H

/*定义一个回调函数类型*/
typedef unsigned char (*Call_Backet)(unsigned char, unsigned char);

/*申明一个回调函数*/
unsigned char (*Second)(unsigned char, unsigned char);

unsigned char First_Function(unsigned char a, unsigned char b);
#endif
