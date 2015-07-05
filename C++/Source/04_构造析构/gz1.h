#include <iostream>

using namespace std;

class  point
{
    private:
        int  x, y;

    public:
    point(int  xx = 0, int yy = 0)		//定义构造函数
    {
        x = xx ;
        y = yy ;
        cout << "构造函数被调用"<< endl ;
    }
    point( point  &p ) ;			//声明拷贝构造函数
    ~point()					//定义析构函数
    { cout << "析构函数被调用"<<endl }
    int getx()  { return  x ;}
    int gety()  { return  y ;}
};

