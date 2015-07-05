#include <iostream>
#include  <math.h>

using namespace std;

class point				//声明point类
{
    private:
        int x, y;

    public:
        point(int i=0, int j=0)           //定义构造函数
        {
            x = i;
            y = j;
            cout<<"point构造函数被调用"<<endl;
        }	
        point(point &p);		//声明拷贝构造函数
        ~point()
        {
            cout<<"point析构函数被调用"<<endl;
        }
        int get_x()
        {
            return x;
        }
        int get_y()
        {
            return y;
        }
};

class distance			 //声明distance类（组合类）
{
    private:
        point  p1, p2;
        double dist;

    public:
        distance(point xp1, point xp2);   //声明组合类构造函数
        ~distance()			
        {
            cout<<"distance析构函数被调用"<<endl;
        }
        double get_dist()
        {
            return dist;
        }
};
