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
		Part p2,p1;    // �ṹ��
		Part *p3;      // ���ṹ��
		int i,j,k;
};

