#include <iostream>

using namespace std;

class Clock
{
	public:
		Clock()
		{			
            cout<<"wucan gouzao!"<<endl;
			hour = 0;
			min = 0;
			sec = 0;
		}
		
		Clock(int h,int m,int s=20)
		{
			cout<<"youcan gouzao!"<<endl;
			hour = h;
			min = m;
			sec = s;
		}
#if 1
		Clock(Clock &c)
		{			
            cout<<"copy gouzao!"<<endl;
			hour = c.hour+1;
			min = c.min+1;
			sec = c.sec+1;
		}
#endif
		~Clock()
		{			
            cout<<"xigou!"<<hour<<endl;
		}

        void setTime(int h,int m,int s=45);
		void showTime()       // 成员函数  内联
		{
			cout<<hour<<":"<<min<<":"<<sec<<endl;
		}

		void showTime(int a)  // 成员函数  内联
		{
			cout<<hour<<"+"<<min<<"+"<<sec<<endl;
		}
		
		int k;

	private:
		int hour,min,sec;     // 成员变量(成员数据)
};
