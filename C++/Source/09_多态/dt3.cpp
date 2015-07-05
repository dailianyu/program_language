// 静态绑定、动态绑定、虚函数

#include <iostream>
#include "dt3.h"

using namespace std;

void fun(Human &s)
{
	s.marry();
}

void fun2(Human *s)
{
	s->marry();
}

int main()
{
	Human h,*p;
	Man m;
	WoMan w;
#if 0	
	cout<<"1111111111"<<endl;
	h.marry();
	m.marry();
	w.marry();
	
	cout<<"2222222222"<<endl;
//	Human::marry();
//	Man::marry();
//	WoMan::marry();

	cout<<"3333333333"<<endl;

	fun(h);
	fun(m);
	fun(w);
	cout<<"444444444"<<endl;
	fun2(&h);
	fun2(&m);
	fun2(&w);
	cout<<"5555555555"<<endl;
#endif
//// 通过基类指针删除派生类对象
	Man *q =  new Man;
	p = q;

	delete p;
	cout<<"666666"<<endl;
}

