// ��̬��Ա�������������ⶨ��ͳ�ʼ���������������������������������ʹ�ù��еľ�̬��Ա����
// ��������������������������������ù��еľ�̬��Ա����
// ��̬��Ա����ֻ��ֱ���������ڸ���ľ�̬��Ա������̬��Ա��������̬�Ծ�̬��

#include <iostream>
#include "clock.h"

Clock::Clock()
{	
    cout<<"wucan gouzao!"<<endl;
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

Clock::Clock(Clock &c)
{	
    cout<<"copy gouzao!"<<endl;
	hour = c.hour+1;
	min = c.min+1;
	sec = c.sec+1;
}

void Clock::setTime(int h,int m,int s)
{
    hour = h;
	min = m;
	sec = s;
}

void Clock::display()
{
	cout<<k<<endl;
}

int Clock::k = 100;

void fun(Clock p)    // ����ÿ�������
{
	cout<<"enter fun"<<endl;
	p.showTime(1);
}

void fun2(Clock &p2) // ������ÿ�������
{
	cout<<"enter fun"<<endl;
	p2.showTime(1);
}

int main()
{
    Clock t;     // �����޲ι���
	cout<<"tk="<<t.getK()<<endl;
        
    t.setK(200) ;

	Clock t2;
	cout<<"t2k="<<t2.getK()<<endl;
	
    t2.setK(2000);
        
    cout<<"tk="<<t.getK()<<endl;

    t.display();
	Clock::display();

     //	cout<<"tk="<<Clock::k<<endl;
}


