#include <iostream>

using namespace std;

struct A
{
};

class B
{
	public:
		B(){cout<<"Base wucan gouzao!!"<<endl;}
		B(int i)
		{
			//x = i;
			cout<<"Base youcan gouzao!!  x = "<<endl;
		}
		~B(){cout<<"Base xigou!! x="<<endl;}

	//	char (*p)[3];
	//	char c;
	private:
	//	int x;
		
	//	short d;
};

class Base
{
	public:
		Base(){cout<<"Base wucan gouzao!!"<<endl;}
		Base(int i)
		{
			x = i;
			cout<<"Base youcan gouzao!!  x = "<<x<<endl;
		}
		~Base(){cout<<"Base xigou!! x="<<x<<endl;}
	private:
		int x;
};

class Base2
{
	public:
		Base2(){cout<<"Base2 wucan gouzao!!"<<endl;}
		Base2(int i)
		{
			x = i;
			cout<<"Base2 youcan gouzao!!  x = "<<x<<endl;
		}
		~Base2(){cout<<"Base2 xigou!! x="<<x<<endl;}
	private:
		int x;
};

// 带内嵌对象的多继承构造顺序: 继承的、内嵌对象的、派上类
class Dog : public Base,private Base2
{
	public:
		Dog(){cout<<"Dog wucan gouzao!!"<<endl;}
		Dog(int i,int j);
		~Dog(){cout<<"Dog xigou!! x="<<x<<endl;}
	private:
		int x,y;
		Base p1,p2;
		Base2 p3,p4;
		Base *p5;        // 不会有构造
};


