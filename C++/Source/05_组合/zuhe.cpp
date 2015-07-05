// 类组合是先是大类中内嵌对象的构造，然后才是大类本身的构造
// 构造与析构的顺序相反(镜像对称)

#include <iostream>
#include "zuhe.h"

Part::Part()
{
	cout<<"Part wucan gouzao"<<endl;
	i = 0;
	j = 0;
}

Part::Part(int x,int y)
{
	cout<<"Part youcan gouzao: x+y="<<x+y<<endl;
	i = x;
	j = y;
}

Part::~Part()
{
    cout<<"Part xigou: i+j="<<i+j<<endl;
}

Whole::Whole()
{

	cout<<"Whole wucan gouzao"<<endl;
    i = 0;
	j = 0;
	k = 0;
}

Whole::Whole(int x,int y,int z):p1(x,y),p2(y,z)
{
	cout<<"Whole youcan gouzao: x+y+z="<<x+y+z<<endl;
	i = x;
	j = y;
	k = z;
}

Whole::~Whole()
{
	cout<<"Whole xigou: i+j+k="<<i+j+k<<endl;
}

int main()
{
    Whole w[4];
	Whole w2(2,4,7);
	cout<<"-----------------------"<<endl;
}

