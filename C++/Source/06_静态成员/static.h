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
       	static void display();   // ��̬��Ա����

	private:
	    static int k;       // ��̬��Ա����  
		int hour,min,sec;   // ��Ա����(��Ա����)
};
