#include <iostream>

using namespace std;

class B0
{
	public:
		 void display(){cout<<"B0"<<endl;}
		 B0(){}
		 B0(B0 &b){cout<<"B0 copy gouzao"<<endl;}
};

class B1:public B0
{
	public:
		void display(){cout<<"B1"<<endl;}
		B1(){}
		B1(B1 &b){cout<<"B1 copy gouzao"<<endl;}
};

class B2:public B1
{
	public:
		void display(){cout<<"B2"<<endl;}
		B2(){}
		B2(B2 &b){cout<<"B2 copy gouzao"<<endl;}
};



