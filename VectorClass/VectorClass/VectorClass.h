#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
class Vector
{
	int* arr;
	int size;
	int capacity;
	bool isFull()
	{
		return size == capacity;
	}
	
public:
	Vector()
	{
		capacity = 2;
		size = 0;
		arr = new int[capacity];
	}
	void push_back(int x)
	{
		if (isFull())
		{
			expand();
		}
		arr[size] = x;
		size++;
	}
	void pop_back()
	{
		if (isEmpty())
		{
			return;
		}
		size--;
	}
	int get(int i)
	{
		if (i >= 0 && i < size)
		{
			return arr[i];
		}
		return -1;
	}
	void set(int i, int x)
	{
		if (i >= 0 && i < size)
		{
			arr[i] = x;
		}
	}
	int getsize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	int minElement()
	{
		if (isEmpty()) return -1;
		int min = arr[0];
		for (int i = 1; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}
	int maxElement()
	{
		if (isEmpty()) return -1;
		int max = arr[0];
		for (int i = 1; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	void expand()
	{
		capacity = capacity * 2;

		int* newarr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	void insert(int i, int val)
	{
		if (isFull())
		{
			expand();
		}
		for (int j = size - 1; j >= i; j--)
			arr[j + 1] = arr[j];
		arr[i] = val;
		size++;
	}
	void erase(int i)
	{
		if (!isEmpty())
		{
			for (int j = i; j < size - 1; j++)
				arr[j] = arr[j + 1];
			size--;
		}
		else
		{
			cout << "Have nothing to remove\n";
		}
	}
	void clear()
	{
		size = 0;
	}
	~Vector()
	{
		delete[] arr;
	}
};
#endif