#include "zuhe1.h"

point::point(point &p)		//定义拷贝构造函数
{
    x = p.x;
    y = p.y;
    cout<<"point拷贝构造函数被调用"<<endl;
}

//定义组合类构造函数:
distance::distance(point xp1, point xp2): p1(xp1), p2(xp2)
{
    cout<<"distance构造函数被调用"<<endl;
    double x = double(p1.get_x() - p2.get_x());
    double y = double(p1.get_y() - p2.get_y());
    dist = sqrt(x*x + y*y);
}

void main( )
{
    point myp1(1, 1), myp2(4, 5);     //point构造函数被调用2次
    distance myd(myp1, myp2);  //point拷贝构造函数被调用4次
                                // distance构造函数被调用1次
    cout<<"the distance is:"<<myd.get_dist( )<<endl;
}

/*
程序运行结果为:
    point构造函数被调用
    point构造函数被调用
    point拷贝构造函数被调用
    point拷贝构造函数被调用
    point拷贝构造函数被调用
    point拷贝构造函数被调用
    distance构造函数被调用
    point析构函数被调用
    point析构函数被调用
    the distance is:5
    distance析构函数被调用
    point析构函数被调用
    point析构函数被调用
    point析构函数被调用
    point析构函数被调用
*/

