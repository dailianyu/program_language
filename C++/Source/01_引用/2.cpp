// 普通变量为形参，指针为形参，引用为形参的用法

#include <iostream>

using namespace std;

void swap1(int x,int y)
{
	int t;
	t = x;
	x = y;
	y = t;
}

void swap2(int *x,int *y)
{
	int t;    
	t = *x;
	*x = *y;
	*y = t;
}

void swap3(int &x,int &y)
{
	int t;
	t = x;
	x = y;
	y = t;
}

int main()
{
	int a = 10, b = 20;
    const int c = 100;

	char *p = (char *)malloc(100);
	free(p);

	char *p2 = new char[100];
	delete []p2;

	swap1(a,b);
	cout<<"a="<<a<<",b="<<b<<endl;     // 10,20

	swap2(&a,&b);
	cout<<"a2="<<a<<",b2="<<b<<endl;   // 20,10

	swap3(a,b);
	cout<<"a3="<<a<<",b3="<<b<<endl;   // 10,20
}
