// ����: �����Ĳ������͡�������const������Ϊ�������صı�־�������ķ���ֵ������Ϊ���ر�־
// const�������κ������������βΣ��Լ������ķ���ֵ������ֻ�����κ���ʱ������Ϊ���صı�־
// ����ʱƥ���������

#include <iostream>
using namespace std;

int fun(int x)
{
	cout<<"1111"<<endl;
}

int fun(int x,int y=11)
{
	cout<<"2222"<<endl;
}

int fun(char x)
{
	cout<<"3333"<<endl;
}
#if 0
int fun(int x) const       // const �������ηǳ�Ա�������˴����뱨��
{
	cout<<"4444"<<endl;
}
#endif
int fun(float x)
{
	cout<<"5555"<<endl;
}

int main()
{
	//fun(1);        // �˴������������أ����뱨��
	fun(1,2);
	fun(1.0f);
	fun('1');
}
