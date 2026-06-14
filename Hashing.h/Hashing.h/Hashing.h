#ifndef HASHING_H
#define HASHING_H
#include "Array.h"
#include <cmath>
#include "String.h"
#include "LSLL_ITER.h"
class HashTable
{
	int tableSize ;
	int entriesCount ;
	Array<LSLL<int>>table;

	int getHashCode(int val)
	{
		return (val < 0 ? -val : val) % tableSize;
	}
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
		Array<LSLL<int>> prevtable = table;
		tableSize = nextPrime(prevSize * 2);
		table = Array<LSLL<int>>(tableSize);
		entriesCount = 0;

		for (int i = 0; i < prevSize; i++)
		{
			for (auto a : prevtable[i])
			{
				int newIndx = getHashCode(a);
				table[newIndx].insertAtHead(a);
				entriesCount++;
			}
		}
	}
	
public:
	HashTable()
	{
		tableSize = 37;
		table = Array<LSLL<int>>(tableSize);
		entriesCount = 0;
	}
	void insert(int val)
	{

		int indx = getHashCode(val);
		if (!table[indx].search(val))
		{
			table[indx].insertAtHead(val);
			entriesCount++;
		}
		if (loadFactor() > 0.75)
		{
			rehash();
		}
	}
	void remove(int val)
	{
		int indx = getHashCode(val);
		if (table[indx].search(val))
		{
			table[indx].remove(val);
			entriesCount--;
		}
	
	}
	bool search(int val)
	{
		int indx = getHashCode(val);
		return table[indx].search(val);
	}
	float loadFactor() const
	{
		return (float)entriesCount / tableSize;
	}
	int getNoOfElements()
	{
		return entriesCount;
	}

};
#endif
