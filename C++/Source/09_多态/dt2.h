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

		Clock operator ++();  // ǰ��
		
		Clock operator ++(int); // ����
		
		void showTime()
		{
			cout<<hour<<":"<<min<<":"<<sec<<endl;
		}

	private:
		int hour,min,sec;  // ��Ա����(��Ա����)
};
