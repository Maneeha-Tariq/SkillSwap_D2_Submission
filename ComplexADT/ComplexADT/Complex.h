#include<iostream>
#include <math.h>
using namespace std;
class Complex
{
	double real;
	double imag;

public:
	Complex(double r = 0, double i = 0)
	{
		real = r;
		imag = i;
	}
	void set(double r, double i)
	{
		real = r;
		imag = i;
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
	Complex* add(Complex& other) 
	{
		Complex* c = new Complex;
		c->real = real + other.real;
		c->imag = imag + other.imag;
		return c;
	}
	Complex* sub(Complex& other) const
	{
		Complex* c = new Complex;
		c->real = real - other.real;
		c->imag = imag - other.imag;
		return c;
	}
	Complex* mul(Complex& other)
	{
		Complex* res = new Complex;
		res->real = (real * other.real) - (imag * other.imag);
		res->imag = (real * other.imag) + (imag * other.real);
		return res;
	}
	Complex* divide(Complex& other)
	{
		Complex* conj = other.conjugate();
		Complex* mu = mul(*conj);
		Complex* mu2 = other.mul(*conj);
		Complex* div = new Complex;
		div->real = mu->real / mu2->real;
		div->imag = mu->imag / mu2->real;
		return div;

	}
	Complex* conjugate() 
	{
		Complex* n= new Complex;
		n->real = real;
		n->imag = -imag;
		return n;
	}
	double magnitude()
	{
		double m = sqrt(real * real + imag * imag);
		return m;
	}
	static Complex** sortByMagnitude(Complex** arr,int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i+1; j < size; j++)
			{
				if (arr[i]->magnitude() > arr[j]->magnitude())
				{
					Complex* temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
	    }
		return arr;
	}
};