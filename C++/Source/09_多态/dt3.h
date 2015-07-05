#include <iostream>
using namespace std;

class Human
{
	public:
		Human(){cout<<"Human gouzao!!!"<<endl;}
		virtual ~Human(){cout<<"Human xigou!!!"<<endl;}
		virtual void marry(){cout<<"Human marry!!!"<<endl;}
};

class Man : public Human
{
	public:
		Man(){cout<<"Man gouzao!!!"<<endl;}
		~Man(){cout<<"Man xigou!!!"<<endl;}
		void marry(){cout<<"Man marry!!!"<<endl;}
};

class WoMan : public Human
{
	public:
		WoMan(){cout<<"WoMan gouzao!!!"<<endl;}
		~WoMan(){cout<<"WoMan xigou!!!"<<endl;}
		void marry(){cout<<"WoMan marry!!!"<<endl;}
};


