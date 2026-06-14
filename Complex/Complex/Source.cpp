#include<iostream>
#include "Complex.h"
using namespace std;
int main()
{
	Complex c(2,5); 
	Complex d(1, 7);
	Complex t = c.addTwoComplexNo(d);
	/*cout << "Add two numbers "<< endl;
	cout << "(";
	c.display();
	cout << ")";
	cout << " + ";
	cout << "(";
	d.display();
	cout << ")";
	cout << " = ";
	t.display();
	cout << "\nConjugate of Complex Number \n";
	c.display();
	cout << " = ";
	Complex r = c.conjugate();
	r.display();*/

	Complex s = c.subtractTwoComplexNo(d);
	s.display();
	return 0;
}