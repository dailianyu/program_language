// 双目运算符的重载

#include <iostream>
#include "dt1.h"

using namespace std;

//  a + b   ==>   a.operator+(b);    重载为成员函数
#if 0
Complex Complex::operator + (Complex c)
{
    double r,i;

	r = real + c.real;
	i = image + c.image;

	cout<<"mem:operator +"<<endl;

	return Complex(r,i);
}

Complex Complex::operator - (Complex c)
{
	double r,i;
	
	r = real - c.real;
	i = image - c.image;

	cout<<"mem:operator -"<<endl;

	return Complex(r,i);

}
#endif

/////////////////////////////////////////////////////////
//  friend   a+b ===> operator + (a,b)    重载为友元函数 

Complex operator + (Complex c1,Complex c2)
{
	Complex c;

	c.real = c1.real + c2.real;
	c.image = c1.image + c2.image;

	cout<<"friend:operator +"<<endl;

	return c;
}

Complex operator - (Complex c1,Complex c2)
{
 	Complex c;

	c.real = c1.real - c2.real;
	c.image = c1.image - c2.image;

	cout<<"friend:operator -"<<endl;

	return c;
}

int main()
{
	Complex a(1,2),b(2,3),c;

    c = a + b;
  //c = operator+(a,b);

	c.display();


   //c = a.operator -(b);
	c = a-b;

	c.display();
	
	return 0;
}



