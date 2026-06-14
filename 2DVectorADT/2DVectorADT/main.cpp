#include<iostream>
#include "2DVectorADT.h"
using namespace std;
int main()
{
	Vector2D v(2, 7);
	v.pushBack(5);
	v.pushBack(10);
	v.pushBack(15);
	v.pushBack(20);
	v.pushBack(70);
	v.pushBack(40);
	v.display();
	return 0;

	
	
}