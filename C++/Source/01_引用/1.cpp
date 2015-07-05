// 变量的引用、函数的形参带默认值的用法

#include <iostream>

using namespace std;

int fun(int x,int y,int z=100)
{
	return (x+y+z);
}

int main()
{
	int a;
	int &x=a;

	a = 10;
	cout<<"x="<<x<<endl;

	x = 20;
	cout<<"a="<<a<<endl;
#if 0   
	a = fun(1,2,3); // 6
	cout<<a<<endl;

	a = fun(1,2);   // 103
	cout<<a<<endl;
#endif
	return 0;
}
