// 1 ��Ԫ�������������������ǳ�Ա����
// 2 ��Ԫ�������βο����Ƕ����������������á����ָ��
// 3 ����Ԫ�����ĺ��������ܹ�ͨ������������private��protected��Ա������ͨ����������
// 4 ����һ��A�࣬A����B�����Ԫ����A������г�Ա���ܷ���B���˽�г�Ա����Ԫ��ϵ�ǵ����
// --------------------------------------------------------------------------------------
// 1 ��ͨ�����ͳ���������ʱ����ͨ�������ȵ�����ͨ����
// 2 ��ͨ������û����ͨ����ʱ�����Ե��ó�����
// 3 ��ͨ�����ͳ���������ʱ��������ֻ�ܵ��ó�����
// 4 ���������Ա�����Ĺ�ϵ������Ա���������¶�������ݳ�Ա
// 5 ����Ա�����ĳ�ʼ�����⣺ֻҪ���ֹ��캯���ĵط�������Ҫ�ڹ��캯��������ð�ų�ʼ��
// 6 ����Ա�������ܱ���ֵ��ı䣬ֻ��������ֵ����ù��캯���й�
// 7 ��̬����Ա������ʼ��ʱ��static��ʽΪ׼�����static��const������

#include <iostream>
#include <math.h>
#include "friend.h"
#include "friend.h"

Point::Point():k(0)
{
	cout<<"wucan gouzao"<<endl;
    this->x = 0;
    this->y = 0;
}

Point::Point(int x,int y):k(10)
{
	cout<<"youcan gouzao"<<endl;
	this->x = x;
	this->y = y;
}

float Point::Dist(Point &a,Point &b)
{
	float dx,dy;
	
    dx = a.x - b.x;
	dy = a.y - b.y;
	
	return sqrt(dx*dx+dy*dy);
}

float Dist(Point &a,Point &b)  // �ǳ�Ա����
{
	float dx,dy;

	dx = a.x - b.x;
	dy = a.y - b.y;

	return sqrt(dx*dx+dy*dy);
}

float Dist2(Point a,Point b)  // �ǳ�Ա����
{
	float dx,dy;

	dx = a.x - b.x;
	dy = a.y - b.y;

	return sqrt(dx*dx+dy*dy);
}

float Dist3(Point *a,Point *b)  // �ǳ�Ա����
{
	float dx,dy;

	dx = a->x - b->x;
	dy = a->y - b->y;

	return sqrt(dx*dx+dy*dy);
}

#if 1
void Point::setxy(int i,int j)
{
	cout<<"putong"<<endl;
	x=i;
	y=j;
}
#endif

#if 1
void Point::setxy (int i,int j) const   //����Ա����
{
	cout<<"const"<<endl;

	//x=i+10;
	//y=j+10;
} 
#endif

const int Point::k2 = 100;

int main()
{
	const Point t4(1,1);   
	t4.setxy(4,5);
	
#if 0
    float d = Dist(t1,t2);
    cout<<d<<endl;

    d = Dist2(t1,t2);
    cout<<d<<endl;

	d = Dist3(&t1,&t2);
    cout<<d<<endl;

	cout<<t3.Dist(t1,t2)<<endl;
#endif
}

