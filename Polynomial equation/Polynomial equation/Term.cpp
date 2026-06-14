#include<iostream>
using namespace std;
class Term
{
	float coef;
	int exp;
public:
	Term()
	{
		coef = exp = 0;
	}
	Term(float c, int e)
	{
		coef = c;
		exp = e;
	}
	void setExponent(int x)
	{
		exp = x;
	}
	int getExponent()
	{
		return exp;
	}
	void setCoefficient(float c)
	{
		coef = c;
	}
	float getCoefficient()
	{
		return coef;
	}

};
class Polynomial
{
	Term* data;
	int noOfTerms;
	int capacity;

	bool isDuplicate(int exponent)
	{
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == exponent)
			{
				return true;
			}
		}
		return false;
	}

public:
	Polynomial()
	{
		data = nullptr;
		noOfTerms = capacity = 0;
	}
	Polynomial(int n) : Polynomial()
	{
		if (n <= 0)
		{
			return;
		}
		capacity = n;
		data = new Term[capacity];
	}
	void addTerm(float coefficient, int power)
	{
		if (isDuplicate(power))
		{
			for (int i = 0; i < noOfTerms; i++)
			{
				if (data[i].getExponent() == power)
				{
					data[i].setCoefficient(coefficient);
					return;
				}

			}
		}
		else
		{
			int i = noOfTerms;
			while (i > 0 && data[noOfTerms - 1].getExponent() < power)
			{
				data[i] = data[noOfTerms - 1];
				i--;
			}
			data[i].setCoefficient(coefficient);
			data[i].setExponent(power);
			noOfTerms++;
		}

	}
	int getDegree()
	{
		return data[0].getExponent();
	}
	void clear()
	{
		noOfTerms = 0;
	}
	void setCoefficient(float newCoefficient, int power)
	{
		bool exist = false;
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == power)
			{
				data[i].setCoefficient(newCoefficient);
				exist = true;
				return;
			}
		}
		if (!exist)
		{
			addTerm(newCoefficient, power);
		}
		
	}
	void addToCoefficient(float coefficient, int power)
	{
		bool exist = false;
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == power)
			{
				data[i].setCoefficient(data[i].getCoefficient() + coefficient);
				exist = true;
				return;
			}
		}
		if (!exist)
		{
			addTerm(coefficient, power);
		}
	}
	float getCoefficient(int power)
	{
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() == power)
			{
				return data[i].getCoefficient();
			}
		}

		return 0.0f;
	}
	Polynomial* Derivative()
	{
		Polynomial* result = new Polynomial(noOfTerms);
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() > 0)
			{
				float coef = data[i].getCoefficient() * data[i].getExponent();
				int exp= data[i].getExponent() - 1;

				result->addTerm(coef, exp);
			}
			
		}
		return result;
	}
	Polynomial* AntiDerivative()
	{
		Polynomial* result = new Polynomial(noOfTerms);
		for (int i = 0; i < noOfTerms; i++)
		{
			if (data[i].getExponent() > 0)
			{
				float coef = data[i].getCoefficient() / (data[i].getExponent() + 1);
				int exp = data[i].getExponent() + 1;

				result->addTerm(coef, exp);
			}
		}
		return result;
	}
	Polynomial operator+(Polynomial* p1)
	{

	}

};

class polynomial
{
	float* data;
	int degree;
public:
	polynomial()
	{
		degree = 0;
		data = new float[degree + 1];
		data[0] = 0;
	}
	polynomial(int d) :polynomial()
	{

		if (d <= 0)
		{
			return;

		}
		delete[] data;
		degree = d;
		data = new float[degree + 1];
		for (int i = 0; i <= degree; i++)
		{
			data[0] = 0;
		}
	}
	void addTerm(float coefficient, int power)
	{
		data[power] = coefficient;
	}
	int getDegree()
	{
		return degree;
	}
	void clear()
	{
		for (int i = 0; i < degree; i++)
		{
			data[i] = 0;
		}
	}
	polynomial operator+(polynomial & d)
	{
		int maxD;
		if (this->degree > d.degree)
		{
			maxD = this->degree;
		}
		else
		{
			maxD= d.degree;
		}
		polynomial result(maxD);
		for (int i = 0; i < maxD; i++)
		{
			float coef1, coef2;
			if (i <= this->degree)
			{
				coef1= this->data[i];
			}
			else
			{
				coef1 = 0;
			}
			if (i <= d.degree)
			{
				coef2 = d.data[i];
			}
			else
			{
				coef2 = 0;
			}
			result.data[i] = coef1 + coef2;
		}
		return result;
	}
	void setCoefficient(float newCoefficient, int power)
	{
		data[power] = newCoefficient;
	}
	void addToCoefficient(float coefficient, int power)
	{
		data[power] = data[power] + coefficient;
	}
	polynomial Derivative()
	{
		if (degree == 0)
		{
			return ;
		}
		polynomial result(degree-1);
		for (int i = 1; i <= degree; i++)
		{
			result.data[i - 1] = this->data[i] * i;
		}
		return result;
	}
		
    polynomial AntiDerivative()
	{
		polynomial result(degree +1);
		for (int i = 1; i <= degree; i++)
		{
			result.data[i + 1] = this->data[i] / (i+1);
		}
		result.data[0] = 0;
		return result;
	}

};




