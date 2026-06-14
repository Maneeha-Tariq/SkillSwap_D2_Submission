#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H
#include "Array.h"
#include<iostream>
using namespace std;
enum SloStatus{EMPTY,OCCUPIED,DELETED};
class LinearProbing
{
	Array<int> table;
	Array<SloStatus> bucketStatus;
	int tableSize;
	int entriesCount;

	int getHashCode(int key)
	{
		return key % tableSize;
	}
	int getNextIndex(int indx)
	{
		int jump = 1;
		return (indx + jump) % tableSize;
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

	bool isFull()
	{
		return entriesCount == tableSize;

	}
	void rehash()
	{
		int prevSize = tableSize;
		Array<int> prevtable = table;
		Array<SloStatus> prevStatus = bucketStatus;
		tableSize = nextPrime(prevSize * 2);
		table = Array<int>(tableSize);
		bucketStatus = Array<SloStatus>(tableSize);
		entriesCount = 0;

		for (int i = 0; i < prevSize; i++)
		{
			if (prevStatus[i] == OCCUPIED)
			{
				int val = prevtable[i];
				int indx = getHashCode(val);
				while (bucketStatus[indx] == OCCUPIED)
				{
					indx = getNextIndex(indx);
				}
				table[indx] = val;
				bucketStatus[indx] = OCCUPIED;
				entriesCount++;

			}
		}
	}
public:
	LinearProbing()
	{
		tableSize = 37;
		entriesCount = 0;
		table = Array<int>(tableSize);
		bucketStatus = Array<SloStatus>(tableSize);
		int len = bucketStatus.getSize();
		for (int i = 0; i < len; i++)
		{
			bucketStatus[i] = EMPTY;
		}
	}
	void insert(int val)
	{
		int indx = getHashCode(val);
		int deleted = -1;
		int start = indx;
		while (bucketStatus[indx] != EMPTY)
		{
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				return;
			}
			if (bucketStatus[indx] == DELETED && deleted == -1)
			{
				deleted = indx;
			}

			indx = getNextIndex(indx);
			if (indx == start)  // full circle
				break;

		}
		if (deleted != -1)
		{
			indx = deleted;
		}

		table[indx] = val;
		bucketStatus[indx] = OCCUPIED;
		entriesCount++;

		if (loadFactor() >= 0.75)
		{
			rehash();
		}
	}
	void remove(int val)
	{
		int indx = getHashCode(val);
		int oldIndx = indx;

		while (bucketStatus[indx] != EMPTY)
		{
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				bucketStatus[indx] = DELETED;
				entriesCount--;
				return;
			}

			indx = getNextIndex(indx);

			if (indx == oldIndx)
			{
				break;
			}
		}
		cout << "Value not found\n";
		
	}
	bool search(int val)
	{
		int indx = getHashCode(val);
		int oldIndx = indx;
		
		while (bucketStatus[indx] != EMPTY)
		{
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				return true;
			}

			indx = getNextIndex(indx);

			if (indx == oldIndx)
			{
				break;
			}
		}
		return false;
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