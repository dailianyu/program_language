#include <iostream>

using namespace std;

class A
{
	public:
		A(int x)
		{
			i = x;
		}
		static void f(A a)
		{   
			A t4(10000);
			cout<<"i="<<a.i<<endl;   // ͨ���������˽�зǾ�̬��Ա����
			//cout<<"i="<<i<<endl;   // ����ֱ�ӷ��ʷǾ�̬��Ա����
			cout<<"i4="<<t4.i<<endl; // ͨ���������˽�зǾ�̬��Ա����
		}
		static void f1(A &a)
		{
			cout<<"i="<<a.i<<endl;
		}
		static void f2(A *a)
		{
			cout<<"i="<<a->i<<endl;
		}
	    void f3(A a)
		{   
			A t2(100);                // �ڳ�Ա�����п��Զ��屾�����
			cout<<"i="<<a.i<<endl;    // �����ڳ�Ա�����п��Է���˽�г�Ա
		    cout<<"i2="<<t2.i<<endl;  // �����ڳ�Ա�����п��Է���˽�г�Ա
			cout<<"i="<<i<<endl;
		}

	private:
		int i;
		//A j;                        // ���������������
};
