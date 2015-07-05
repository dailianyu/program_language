#include <iostream>

using namespace std;

class Complex
{
	public:
		Complex(double r=0.0, double i=0.0)
		{
			real = r;
			image = i;
		}
		void display()
		{
			cout<<"("<<real<<","<<image<<")"<<endl;
		}

	//	Complex operator + (Complex c);
	//	Complex operator - (Complex c);

        friend Complex operator + (Complex c1,Complex c2);
		friend Complex operator - (Complex c1,Complex c2);

	private:
		double real,image;
};

