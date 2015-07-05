// 重载: 函数的参数类型、个数、const可以作为区分重载的标志，函数的返回值不能作为重载标志
// const可以修饰函数、函数的形参，以及函数的返回值，但是只有修饰函数时，才能为重载的标志
// 调用时匹配参数类型

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
int fun(int x) const       // const 不能修饰非成员函数（此处编译报错）
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
	//fun(1);        // 此处不能区分重载，编译报错
	fun(1,2);
	fun(1.0f);
	fun('1');
}
