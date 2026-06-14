#ifndef POLYNOMIAL_HASHCODE_H
#define POLYNOMIAL_HASHCODE_H
#include "Array.h"
#include "LSLL_ITER.h"
#include "String.h"
#include<iostream>
using namespace std;
class PolyHash
{
	int tableSize;
	int entriesCount;
	Array<LSLL<String>>table;

	
	bool isPrime(int n)
	{
		if (n < 2)
		{
			return false;
		}
		if (n == 2)
		{
			return true;
		}
		if (n % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i * i <= n; i = i + 2)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;

	}
	int nextPrime(int n)
	{
		int no = (n % 2 == 0) ? n + 1 : n;
		while (!isPrime(no))
		{
			no += 2;
		}
		return no;
	}
	void rehash()
	{
		int prevSize = tableSize;
		Array<LSLL<String>> prevtable = table;
		tableSize = nextPrime(prevSize * 2);
		table = Array<LSLL<String>>(tableSize);
		entriesCount = 0;

		for (int i = 0; i < prevSize; i++)
		{
			for (auto a : prevtable[i])
			{
				long long newIndx = getPolyHashCode(a);
				table[newIndx].insertAtHead(a); 
				entriesCount++;
			}
		}
	}
	int getPolyHashCode(String str) 
	{ 
		int polyNo = 31;
		long long hash = 0; 
		long long power = 1; 
		int len = str.getLength(); 
		for (int i = 0; i < len; i++) 
		{ 
			int c = (int)str[i];
		    hash += c * power;
			power *= polyNo;
		} 
		hash = hash % tableSize; 
		return hash;
	}

public:
	PolyHash()
	{
		tableSize = 37;
		table = Array<LSLL<String>>(tableSize);
		entriesCount = 0;

	}
	void insert(String key)
	{
		int indx = getPolyHashCode(key);
		if (!table[indx].search(key))
		{
			table[indx].insertAtHead(key);
			entriesCount++;
		}
		if (loadFactor() >= 0.75)
		{
			rehash();
		}
	}
	void remove(String key)
	{
		int indx = getPolyHashCode(key);
		if (table[indx].search(key))
		{
			table[indx].remove(key);
			entriesCount--;
		}

	}
	bool search(String key)
	{
		int indx = getPolyHashCode(key);
		return table[indx].search(key);
	}
	float loadFactor()
	{
		return (float)entriesCount / tableSize;
	}
	int getNoOfElements()
	{
		return entriesCount;
	}

};
#endif
