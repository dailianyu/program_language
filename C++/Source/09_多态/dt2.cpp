// 单目运算符的重载

#include <iostream>
#include "dt2.h"

using namespace std;

Clock::Clock()
{	cout<<"wucan gouzao!"<<endl;
	hour = 0;
	min = 0;
	sec = 0;
}

Clock::Clock(int h,int m,int s)
{
	cout<<"youcan gouzao!"<<endl;
	hour = h;
	min = m;
	sec = s;
}

Clock Clock::operator ++()  // 前置 ++ i
{
	sec++;

	cout<<"qian zhi"<<endl;

	return *this;  // 加后
}
		
Clock Clock::operator ++(int) // 后置 i++
{
    Clock old = *this;

	this->sec++;

	cout<<"hou zhi "<<endl;

	return old;
}

int main()
{
	Clock c(10,10,10);

	(c++).showTime();
	
	c.showTime();

	(++c).showTime();

    c.showTime();
}


