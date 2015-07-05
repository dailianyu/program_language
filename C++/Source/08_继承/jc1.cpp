// 1 一个公有派生类的对象在使用上可以被当作为基类的对象，反之则静止:
//                 ① 指向基类的指针也可以指向派生类
//                 ② 派生类的对象可以初始化基类的引用
//                 ③ 派生类的对象可以被赋值给基类对象
// 2 通过基类对象名、指针只能使用从基类继承的成员

#include <iostream>
#include "jc.h"

using namespace std;

// 指向基类的指针也可以指向派生类
void fun(B0 *p)
{
	p->display();
}

// 派生类的对象可以初始化基类的引用
void fun2(B0 &p)
{
	p.display();
}

// 派生类的对象可以被赋值给基类对象
void fun3(B0 p)
{
	p.display();
}

int main()
{
	B0 b0;
	B1 b1;
	B2 b2;
	B0 *q;

	q = &b0;
	fun(q);

    q = &b1;
	fun(q);

    q = &b2;
	fun(q);

	cout<<"------------"<<endl;

	fun2(b0);
	fun2(b1);
	fun2(b2);

	cout<<"------------"<<endl;

	fun3(b0);
	fun3(b1);
	fun3(b2);
}

