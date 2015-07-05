// 1 在本类中不能申明本类对象，在成员函数中可以定义本类对象
// 2 对象在成员函数中可以访问私有成员
// 3 静态成员函数可以通过对象访问所有的成员

#include <iostream>
#include "qx.h"

#if 0   // 类外代码不能通过对象访问私有成员
void fun(A b)
{
    A t3(1000);

	cout<<"i3="<<b.i<<endl;
	cout<<"i3="<<t3.i<<endl;
}
#endif

int main()
{
    A t(10);

	t.f(t);
	t.f1(t);
	t.f2(&t);
	t.f3(t);
	//fun(t);
	
	return 0;
}
