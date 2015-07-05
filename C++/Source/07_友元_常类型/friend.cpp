// 1 友元函数在类中申明但不是成员函数
// 2 友元函数的形参可以是对象名、类对象的引用、类的指针
// 3 在友元函数的函数体内能够通过对象名访问private和protected成员（必须通过对象名）
// 4 若有一个A类，A类是B类的友元，则A类的所有成员都能访问B类的私有成员，友元关系是单向的
// --------------------------------------------------------------------------------------
// 1 普通函数和常函数重载时，普通对象优先调用普通函数
// 2 普通对象在没有普通函数时，可以调用常函数
// 3 普通函数和常函数重载时，常对象只能调用常函数
// 4 常函数与成员变量的关系：常成员函数不更新对象的数据成员
// 5 常成员变量的初始化问题：只要出现构造函数的地方，都需要在构造函数后面用冒号初始化
// 6 常成员变量不能被赋值或改变，只读。具体值与调用构造函数有关
// 7 静态常成员变量初始化时以static方式为准，兼顾static和const的特性

#include <iostream>
#include <math.h>
#include "friend.h"
#include "friend.h"

Point::Point():k(0)
{
	cout<<"wucan gouzao"<<endl;
    this->x = 0;
    this->y = 0;
}

Point::Point(int x,int y):k(10)
{
	cout<<"youcan gouzao"<<endl;
	this->x = x;
	this->y = y;
}

float Point::Dist(Point &a,Point &b)
{
	float dx,dy;
	
    dx = a.x - b.x;
	dy = a.y - b.y;
	
	return sqrt(dx*dx+dy*dy);
}

float Dist(Point &a,Point &b)  // 非成员函数
{
	float dx,dy;

	dx = a.x - b.x;
	dy = a.y - b.y;

	return sqrt(dx*dx+dy*dy);
}

float Dist2(Point a,Point b)  // 非成员函数
{
	float dx,dy;

	dx = a.x - b.x;
	dy = a.y - b.y;

	return sqrt(dx*dx+dy*dy);
}

float Dist3(Point *a,Point *b)  // 非成员函数
{
	float dx,dy;

	dx = a->x - b->x;
	dy = a->y - b->y;

	return sqrt(dx*dx+dy*dy);
}

#if 1
void Point::setxy(int i,int j)
{
	cout<<"putong"<<endl;
	x=i;
	y=j;
}
#endif

#if 1
void Point::setxy (int i,int j) const   //常成员函数
{
	cout<<"const"<<endl;

	//x=i+10;
	//y=j+10;
} 
#endif

const int Point::k2 = 100;

int main()
{
	const Point t4(1,1);   
	t4.setxy(4,5);
	
#if 0
    float d = Dist(t1,t2);
    cout<<d<<endl;

    d = Dist2(t1,t2);
    cout<<d<<endl;

	d = Dist3(&t1,&t2);
    cout<<d<<endl;

	cout<<t3.Dist(t1,t2)<<endl;
#endif
}

