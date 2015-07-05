#include <iostream>

using namespace std;

class A
{
    public:
		A(){cout<<"<1> A::A()"<<endl;}
		virtual ~A(){cout<<"<2> A::~A()"<<endl;}
		virtual void h(){cout<<"<3> A::h()"<<endl;}
	    void g(){cout<<"<4> A::g()"<<endl;}
		virtual void f(){h(); g();}
};

class B : public A
{
    public:
		B(){cout<<"<5> B::B()"<<endl;}
		virtual ~B(){cout<<"<6> B::~B()"<<endl;}
		virtual void h(){cout<<"<7> B::h()"<<endl;}
	    void g(){cout<<"<8> B::g()"<<endl;}
//		virtual void f(){h(); g();}
		virtual void k(){f(); h(); g();}
};

int main()
{
    B b;

	b.k();

	return 0;
}

