// ���캯���ĺ�������������ͬ���޷���ֵ���ǳ�Ա����
// ���캯���ڶ��󴴽�ʱ��ϵͳ�Զ����ã���ҪΪ��ĳ�Ա�������г�ʼ��
// ���캯���������ء���Ĭ�ϲ���������
// ����û������幹�캯����ϵͳĬ�ϸ���һ�����޲ι���
// �м����������ɣ��ͻ��м������캯��������

// ����������һ������Ĺ��죬����û���������ϵͳĬ��һ��
// �����һ������ȥ��ʼ���������һ�������Զ����ÿ�������
// ���������β�Ϊ����󣬵��ú���ʱ��ʵ�θ�ֵ���βΣ�ϵͳ�Զ����ÿ������캯��
// �������ķ���ֵ�������ʱ��ϵͳ�Զ����ÿ������캯��

// �����������ڶ���������ڽ���ʱ��ϵͳ�Զ�����
// �����������Σ�������ͬ���������βΣ��޷������ͣ�ǰ���~
// �ж��ٹ���ͻ��ж���������֮��Ӧ

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

void fun(Clock p)     // ����ÿ�������
{
	cout<<"enter fun"<<endl;
	p.showTime(1);
}

void fun2(Clock &p2)  // ������ÿ�������
{
	cout<<"enter fun"<<endl;
	p2.showTime(1);
}

int main()
{
    Clock t;       // �����޲ι���
	Clock t1(t);   // ���ÿ�������
	t1.showTime();
	t.showTime();
	
	Clock t5;
	t5 = t;        // �˴�û�е��ÿ�������
	t5.showTime();

    cout<<"----------------"<<endl;
	fun(t1);

	cout<<"----------------"<<endl;
	fun2(t1);
	
    cout<<"----------------"<<endl;
	Clock t2(1,2,3);   // �����вι���
	t2.showTime();

	cout<<"+++++++++++++++++++++++++++++++"<<endl;

    Clock *p1 = new Clock;   // ��̬����ķ�ʽ���������޲�
	p1->showTime(1);

    Clock *p2 = new Clock(2,5);  // �в�
	p2->showTime(1);

    Clock *p3 = new Clock[3];    // ��̬����ķ�ʽ���������޲�
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


