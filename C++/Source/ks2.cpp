#include <iostream>

using namespace std;

class A
{
    public:
		A(){cout<<"1"<<endl;}
		virtual ~A(){cout<<"2"<<endl;}
		virtual int add(int n){cout<<"1111"<<endl; return 0;}

	private:
		int num;
};

class B : public A
{
    public:
		B(int n):num(n){}
		virtual ~B(){}
		virtual int add(int n){cout<<"2222"<<endl; return num+=n;}

	private:
		int num;
};

class C : public A
{
    public:
		C(A &p,int n):a(p), num(n){cout<<"3"<<endl;}
		virtual ~C(){cout<<"4"<<endl;}
		virtual int add(int n){cout<<"3333"<<endl; return a.add(n+num);}

	private:
		A &a;
	    int num;
};

int main()
{
    B b(100);
	C c1(b,1), c2(c1,2);

	cout<<c2.add(50)<<endl;

	return 0;
}

