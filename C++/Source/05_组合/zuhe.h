#include <iostream>
using namespace std;

class Part
{
	public:
		Part();
		Part(int x,int y);
        ~Part();
	
        private:
		int i,j;
};

class Whole
{
	public:
		Whole();
		Whole(int x,int y,int z);
        ~Whole();
	
        private:
		Part p2,p1;    // 会构造
		Part *p3;      // 不会构造
		int i,j,k;
};

