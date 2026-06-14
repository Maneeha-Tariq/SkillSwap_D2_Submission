#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H
#include "Array.h"
#include<iostream>
using namespace std;
enum SloStatus { EMPTY, OCCUPIED, DELETED };
class QuadraticProbing
{
	Array<int> table;
	Array<SloStatus> bucketStatus;
	int tableSize;
	int entriesCount;

	int getHashCode(int key)
	{
		return key % tableSize;
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
				int hash = getHashCode(val);
				int attempt = 0;
				int indx;
				do
				{
					indx = (hash + attempt * attempt) % tableSize;
					attempt++;

				} while (bucketStatus[indx] == OCCUPIED);
				
				table[indx] = val;
				bucketStatus[indx] = OCCUPIED;
				entriesCount++;

			}
		}
	}
public:
	QuadraticProbing()
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
		int hash = getHashCode(val);
		int deleted = -1;
		int attempt = 0;
		int indx;
		while (attempt<tableSize)
		{
			indx = (hash + attempt * attempt) % tableSize;
			if (bucketStatus[indx] == EMPTY) break;
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				return;
			}
			if (bucketStatus[indx] == DELETED && deleted == -1)
			{
				deleted = indx;
			}
			attempt++;
		}
		if (deleted != -1)
		{
			indx = deleted;
		}

		table[indx] = val;
		bucketStatus[indx] = OCCUPIED;
		entriesCount++;

		if (loadFactor() > 0.5)
		{
			rehash();
		}
	}
	void remove(int val)
	{
		int hash = getHashCode(val);
		int attempt = 0;
		int indx;

		while (attempt<tableSize)
		{
			indx = (hash + attempt * attempt) % tableSize;
			if (bucketStatus[indx] == EMPTY)
			{
				cout << "Value not found\n";
				return;
			}
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				bucketStatus[indx] = DELETED;
				entriesCount--;
				return;
			}
			attempt++;
		}
		cout << "Value not found\n";

	}
	bool search(int val)
	{
		int hash = getHashCode(val);
		int attempt = 0;
		int indx;

		while (attempt<tableSize)
		{
			indx = (hash + attempt * attempt) % tableSize;
			if (bucketStatus[indx] == EMPTY) return false;
			if (bucketStatus[indx] == OCCUPIED && table[indx] == val)
			{
				return true;
			}
			attempt++;
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