// ³éÏóÀà¡¢´¿Ğéº¯Êı

#include <iostream>
#include "dt4.h"

using namespace std;

void fun(Human &s)
{
	s.marry();
}

void fun2(Human *s)
{
	s->marry();
}

int main()
{
	Human *p;
	Man m;
	WoMan w;	

	//p = new Human;  xx
	// Human h;  xx

	fun(m);
	fun(w);

	fun2(&m);
	fun2(&w);
}

