#include<iostream>
#include <math.h>
using namespace std;
class Complex
{
	double real;
	double imag;

public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(double r, double i)
	{
		real = r;
		imag = i;
	}
	Complex addTwoComplexNo(const Complex& n1) const
	{
		Complex c;
		c.real = real + n1.real;
		c.imag = imag + n1.imag;
		return c;
	}
	Complex subtractTwoComplexNo(const Complex& n1) const
	{
		Complex c;
		c.real = real - n1.real;
		c.imag = imag - n1.imag;
		return c;
	}
	Complex conjugate() const
	{
		Complex n;
		n.real = real;
		n.imag =  -imag;
		return n;
	}
	bool isEqual(const Complex& c)  const
	{
		return (real == c.real) && (imag == c.imag);
	}
	double modulus()
	{
		double m = sqrt(real * real + imag * imag);
		return m;
	}
	Complex operator+(const Complex& c) const
	{
		return addTwoComplexNo(c);
	}
	Complex operator-(const Complex& c) const
	{
		return subtractTwoComplexNo(c);
	}
	bool operator==(const Complex& c)
	{
		return isEqual(c);
	}
	Complex operator~()const
	{
		return conjugate();
	}
	void display()
	{
		cout << real;
		if (imag >= 0)
		{
			cout << " + " << imag << "i";
		}
		else
		{
			cout << " - " << -imag << "i";
		}
		
	}
};