#include "Polynomial.h"
#include<iostream>
using namespace std;
int main()
{
	Polynomial* p1 = new Polynomial(2);
	Polynomial* p2 = new Polynomial(2);
	p1->setCoefficient(2, 1);
	p1->setCoefficient(1, 2);
	p1->setCoefficient(0, 3);

	p2->setCoefficient(2, 2);
	p2->setCoefficient(1, 1);
	p2->setCoefficient(0, 1);

	cout << "Polynomial 1:\t";
	p1->display();
	cout << "\n";
	cout << "Polynomial 2:\t";
	p2->display();
	cout << "\n";

	Polynomial* sum = p1->add(*p2);
	Polynomial* diff = p1->sub(*p2);
	Polynomial* prod = p1->mul(*p2);
	Polynomial* der = p1->derivative();
	cout << "Addition:\t";
	sum->display();
	cout << "\n";

	cout << "Subtraction:\t";
	diff->display();
	cout << "\n";

	cout << "Multiplication:\t";
	prod->display();
	cout << "\n";

	cout << "Derivative:\t";
	der->display();
	cout << "\n";

	cout << "Evaluation at x=2:   " << p1->evaluate(2) << endl;
	return 0;

}