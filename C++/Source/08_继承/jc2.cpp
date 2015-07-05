// 1 派生类对象被创建时，首先调用基类的构造，然后再调用派生类的构造
// 2 构造函数的调用顺序：基类构造（申明时的从左到右）、内嵌对象的构造、派生类的构造
// 3 派生类成员函数可以用类名加域操作符来使用基类的成员(非基类私有)

#include <iostream>
#include "jc2.h"

// 派生类的有参构造函数给基类的有参函数赋值
Dog::Dog(int i,int j):Base(i),Base2(j),p1(i),p2(j),p3(i+j),p4(i-j)
{
	cout<<"Dog youcan gouzao"<<endl;
	x = i;
	y = j;
}

int main()
{
    //  Dog d;

	cout<<sizeof(class B)<<endl;
    cout<<sizeof(struct A)<<endl;

    //  Dog *p = new Dog[2];

    //  Dog a[2];
    //  delete []p;
}

