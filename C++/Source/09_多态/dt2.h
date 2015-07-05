#include <iostream>
using namespace std;

class Clock
{
	public:
		Clock();
		
		Clock(int h,int m,int s=20);	
		
		~Clock()
		{			
            cout<<"xigou!"<<hour<<endl;
		}

		Clock operator ++();  // 前置
		
		Clock operator ++(int); // 后置
		
		void showTime()
		{
			cout<<hour<<":"<<min<<":"<<sec<<endl;
		}

	private:
		int hour,min,sec;  // 成员变量(成员数据)
};
