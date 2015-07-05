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
			cout<<"i="<<a.i<<endl;   // 通过对象访问私有非静态成员变量
			//cout<<"i="<<i<<endl;   // 不能直接访问非静态成员变量
			cout<<"i4="<<t4.i<<endl; // 通过对象访问私有非静态成员变量
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
			A t2(100);                // 在成员函数中可以定义本类对象
			cout<<"i="<<a.i<<endl;    // 对象在成员函数中可以访问私有成员
		    cout<<"i2="<<t2.i<<endl;  // 对象在成员函数中可以访问私有成员
			cout<<"i="<<i<<endl;
		}

	private:
		int i;
		//A j;                        // 不能申明本类对象
};
