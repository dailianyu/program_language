#ifndef _FRIEND_H
#define _FRIEND_H

// 防头文件重复包含

#include <iostream>

using namespace std;

class Point
{
	public:

		Point();
		Point(int x,int y);
                
        Point(Point &p):k(9)
		{
			cout<<"copy gouzao"<<endl;
			x = p.x + 1;
			y = p.y + 2;
		}
                
        void setxy(int i,int j);

        void setxy (int i,int j) const;  // 常成员函数
	  
        friend float Dist(Point &a,Point &b);

		friend float Dist2(Point a,Point b);

		friend float Dist3(Point *a,Point *b);

		float Dist(Point &a,Point &b);

		const int k;  // 常成员变量

		static const int k2;      // 初始化以static方式为准，兼顾static和const特性

	private:
		int x, y;
};
#endif

