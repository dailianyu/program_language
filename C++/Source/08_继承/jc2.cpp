// 1 ��������󱻴���ʱ�����ȵ��û���Ĺ��죬Ȼ���ٵ���������Ĺ���
// 2 ���캯���ĵ���˳�򣺻��๹�죨����ʱ�Ĵ����ң�����Ƕ����Ĺ��졢������Ĺ���
// 3 �������Ա�������������������������ʹ�û���ĳ�Ա(�ǻ���˽��)

#include <iostream>
#include "jc2.h"

// ��������вι��캯����������вκ�����ֵ
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

