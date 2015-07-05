// 构造函数的函数名与类名相同，无返回值，是成员函数
// 构造函数在对象创建时被系统自动调用，主要为类的成员变量进行初始化
// 构造函数可以重载、带默认参数、内联
// 如果用户不定义构造函数，系统默认给定一个，无参构造
// 有几个对象生成，就会有几个构造函数被调用

// 拷贝构造是一种特殊的构造，如果用户不给定，系统默认一个
// 用类的一个对象去初始化该类的另一个对象，自动调用拷贝构造
// 若函数的形参为类对象，调用函数时，实参赋值给形参，系统自动调用拷贝构造函数
// 当函数的返回值是类对象时，系统自动调用拷贝构造函数

// 析构函数是在对象的生存期结束时由系统自动调用
// 析构函数外形：函数名同类名，无形参，无返回类型，前面加~
// 有多少构造就会有多少析构与之对应

#include <iostream>
#include "gz.h"

void Clock::setTime(int h,int m,int s)
{

    hour = h;
	min = m;
	sec = s;

	k = 100;
}

#if 0
inline void Clock::showTime()
{
	cout<<hour<<":"<<min<<":"<<sec<<endl;
}
#endif

void fun(Clock p)     // 会调用拷贝构造
{
	cout<<"enter fun"<<endl;
	p.showTime(1);
}

void fun2(Clock &p2)  // 不会调用拷贝构造
{
	cout<<"enter fun"<<endl;
	p2.showTime(1);
}

int main()
{
    Clock t;       // 调用无参构造
	Clock t1(t);   // 调用拷贝构造
	t1.showTime();
	t.showTime();
	
	Clock t5;
	t5 = t;        // 此处没有调用拷贝构造
	t5.showTime();

    cout<<"----------------"<<endl;
	fun(t1);

	cout<<"----------------"<<endl;
	fun2(t1);
	
    cout<<"----------------"<<endl;
	Clock t2(1,2,3);   // 调用有参构造
	t2.showTime();

	cout<<"+++++++++++++++++++++++++++++++"<<endl;

    Clock *p1 = new Clock;   // 动态申请的方式创建对象，无参
	p1->showTime(1);

    Clock *p2 = new Clock(2,5);  // 有参
	p2->showTime(1);

    Clock *p3 = new Clock[3];    // 动态申请的方式创建对象，无参
	(p3+1)->showTime(1);

    delete p1;
	delete p2;
	delete []p3;
#if 0
	Clock t;
	t.setTime(10,20,30);
	t.showTime();

	t.setTime(10,20);
	t.showTime(2);

	Clock *p = new Clock;
	p->setTime(10,10,30);
	p->showTime(1);

	delete p;

	cout<<t.k<<endl;
#endif	
}


