#include "gz1.h"

point::point(point &p) 		//定义拷贝构造函数
{
    x = p.x;
    y = p.y;
    cout << "拷贝构造函数被调用"<< endl;
}

void f(point p) 			//函数的形参是类的对象
{
    cout<<p.get_x()<<" "<<p.get_y()<<endl;
}

point g()
{
    point a(7, 33);
    return a; 				//函数的返回值是类的对象
}

void main()
{
    point a(15,  22); 	//构造函数被调用
    point b(a);		//拷贝构造函数被调用
    cout<<b.get_x()<<" "<<b.get_y()<<endl;
    f(b);     		//拷贝构造函数被调用，析构函数被调用
    b = g();    	//构造函数和拷贝构造函数各被调用一次，
                        //析构函数被调用两次
    cout<<b.get_x()<<" "<<b.get_y()<<endl;
} 				//析构函数被调用两次

/*
程序的运行结果为：
    构造函数被调用
    拷贝构造函数被调用
    15   22
    拷贝构造函数被调用
    15   22	
    析构函数被调用
    构造函数被调用
    拷贝构造函数被调用
    析构函数被调用
    析构函数被调用
    7    33
    析构函数被调用
    析构函数被调用
*/

