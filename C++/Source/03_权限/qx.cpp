// 1 �ڱ����в���������������ڳ�Ա�����п��Զ��屾�����
// 2 �����ڳ�Ա�����п��Է���˽�г�Ա
// 3 ��̬��Ա��������ͨ������������еĳ�Ա

#include <iostream>
#include "qx.h"

#if 0   // ������벻��ͨ���������˽�г�Ա
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
