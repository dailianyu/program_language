#ifndef _FRIEND_H
#define _FRIEND_H

// ��ͷ�ļ��ظ�����

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

        void setxy (int i,int j) const;  // ����Ա����
	  
        friend float Dist(Point &a,Point &b);

		friend float Dist2(Point a,Point b);

		friend float Dist3(Point *a,Point *b);

		float Dist(Point &a,Point &b);

		const int k;  // ����Ա����

		static const int k2;      // ��ʼ����static��ʽΪ׼�����static��const����

	private:
		int x, y;
};
#endif

