#include <iostream>

using namespace std;

class  point
{
    private:
        int  x, y;

    public:
    point(int  xx = 0, int yy = 0)		//���幹�캯��
    {
        x = xx ;
        y = yy ;
        cout << "���캯��������"<< endl ;
    }
    point( point  &p ) ;			//�����������캯��
    ~point()					//������������
    { cout << "��������������"<<endl }
    int getx()  { return  x ;}
    int gety()  { return  y ;}
};

