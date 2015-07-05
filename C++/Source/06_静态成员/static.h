#include <iostream>
using namespace std;

class Clock
{
	public:
		Clock();
		Clock(int h,int m,int s=20);	
		Clock(Clock &c);
		~Clock()
		{	
            cout<<"xigou!"<<hour<<endl;
		}
        void setTime(int h,int m,int s=45);
        void showTime()
		{
			cout<<hour<<":"<<min<<":"<<sec<<endl;
		}
        void showTime(int a)
		{
			cout<<hour<<"+"<<min<<"+"<<sec<<endl;
		}
        void setK(int w){k = w;}
        int getK(){display();return k;}
       	static void display();   // 静态成员函数

	private:
	    static int k;       // 静态成员变量  
		int hour,min,sec;   // 成员变量(成员数据)
};
