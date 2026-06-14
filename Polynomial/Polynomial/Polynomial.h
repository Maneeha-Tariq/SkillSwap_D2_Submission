#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <math.h>
#include<iostream>
using namespace std;
class Polynomial
{
	int* coefficients;
	int degree;
public:
	Polynomial(int deg)
	{
		degree = deg;
		coefficients = new int[degree + 1];
		for (int i = 0; i <= degree; i++)
		{
			coefficients[i] = 0;
		}
    } 
	void setCoefficient(int power, int value)
	{
		if (power >= 0 && power <= degree)
		{
			coefficients[power] = value;
		}
	}
	void display()
	{
		for (int i = degree; i >= 0; i--)
		{
			if (coefficients[i] > 0)
			{
				if (i != degree)
					cout << "+";
			}
			if (i == 0)
			{
				if (coefficients[i] > 0)
					cout << coefficients[i];
				else
					cout << "-" << (-1)*coefficients[i];
			}
			else if (i == 1)
			{
				if (coefficients[i] > 0)
				{
					if (coefficients[i] == 1)
						cout  << "x";
					else
						cout  << coefficients[i] << "x";
				}
				else
				{
					if (coefficients[i] == -1)
						cout << "-" << "x";
					else
						cout << "-" << (-1) * coefficients[i] << "x";
				}
			}
			else
			{
				if (coefficients[i] > 0)
				{
					if (coefficients[i] == 1)
						cout  << "x^" << i;
					else
						cout  << coefficients[i] << "x^" << i;
				}
				else
				{
					if (coefficients[i] == -1)
						cout << "-"  << "x^" << i;
					else
						cout << "-" << (-1) * coefficients[i] << "x^" << i;
				}
			}
		}
	}
	Polynomial* add(Polynomial& other)
	{
		int n = max(degree, other.degree);
		Polynomial* result = new Polynomial(n);
		for (int i = 0; i <= n; i++)
		{
			int a = i <= degree ? coefficients[i] : 0;
			int b = i <= other.degree ? other.coefficients[i] : 0;
			result->coefficients[i] = a + b;
		}
		return result;

	}
	Polynomial* sub(Polynomial& other)
	{
		int n = max(degree, other.degree);
		Polynomial* result = new Polynomial(n);
		for (int i = 0; i <= n; i++)
		{
			int a = i <= degree ? coefficients[i] : 0;
			int b = i <= other.degree ? other.coefficients[i] : 0;
			result->coefficients[i] = a - b;
		}
		return result;
	}
	Polynomial* mul(Polynomial& other)
	{
		int n = degree + other.degree;
		Polynomial* result = new Polynomial(n);
		for (int i = 0; i <= degree; i++)
		{
			for (int j = 0; j <= other.degree; j++)
			{
				result->coefficients[i + j]+= coefficients[i] * other.coefficients[j];
			}
		}
		return result;
	}
	Polynomial* derivative()
	{
		if (degree == 0)
		{
			Polynomial* result = new Polynomial(0);
			result->coefficients[0] = 0;
			return result;
		}
		int n = degree - 1;
		Polynomial* result = new Polynomial(n);
		for (int i = degree; i > 0; i--)
		{
			result->coefficients[i - 1] = coefficients[i] * i;
		}
		return result;
	}
	int evaluate(int x)
	{
		int result = 0;
		for (int i = 0; i <= degree; i++)
		{
			result += coefficients[i] * pow(x,i);
		}
		return result;
	}
	bool zero()
	{
		for (int i = 0; i <= degree; i++)
		{
			if (coefficients[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	int highDegree()
	{
		return degree;
	}
	~Polynomial()
	{
		delete[] coefficients;
	}
};
#endif