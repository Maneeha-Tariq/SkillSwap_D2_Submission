#ifndef FOLDING_HASHCODE_H
#define FOLDING_HASHCODE_H
#include "Array.h"
#include "LSLL_ITER.h"
#include "String.h"
#include<cmath>
#include<iostream>
using namespace std;
class FoldingHash
{
	int tableSize;
	int entriesCount;
	Array<LSLL<int>>table;

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
				long long newIndx = getFoldingHashCode(a);
				table[newIndx].insertAtHead(a);
				entriesCount++;
			}
		}
	}
	long long reverseNumber(long long num)
	{
		long long rev = 0; 
		while (num != 0)
		{
			rev = rev * 10 + num%10;
			num /= 10;
		}
		return rev;
	}
	int count(int num)
	{
		int counter = 0;
		while (num != 0)
		{
			counter++;
			num /= 10;
		}
		return counter;
	}
	void computePowers(long long& p,int k,int currentGroupSize)
	{
		for (int i = 0; i < k - currentGroupSize; i++)
			p *= 10;
	}
	int getFoldingHashCode(int num)
	{
	    long long sum = 0;
		int k = count(num);
		int groupSize = 2;
		int groupno = 1;
		while (num != 0)
		{
			int currentGroupSize = min(groupSize, k);

			long long p = 1;
			computePowers(p, k, currentGroupSize);

			int extract = num / p;
			num = num % p;
			k -= currentGroupSize;
			if (groupno % 2 == 0)
			{
				extract = reverseNumber(extract);
				sum += extract;
			}
			else
			{
				sum += extract;
			}
			groupno++;
		}
		
		return sum % tableSize;
	}

public:
	FoldingHash()
	{
		tableSize = 37;
		table = Array<LSLL<int>>(tableSize);
		entriesCount = 0;

	}
	void insert(int key)
	{
		int indx = getFoldingHashCode(key);
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
	void remove(int key)
	{
		int indx = getFoldingHashCode(key);
		if (table[indx].search(key))
		{
			table[indx].remove(key);
			entriesCount--;
		}

	}
	bool search(int key)
	{
		int indx = getFoldingHashCode(key);
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
