#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int s)
	{
		T* arr = new T[s];
		for (int i = 0; i < top; i++)
		{
			arr[i] = data[i];
		}
		int arrTop = top;
		delete[] data;
		data = arr;
		capacity = s;
		top = arrTop;
	}
public:
	Stack()
	{
		capacity = 0;
		data = nullptr;
		top = 0;
	}
	Stack(const Stack<T>& ref)
	{
		capacity = ref.capacity;
		top = ref.top;
		data = new T[capacity];
		for (int i = 0; i < top; i++)
		{
			data[i] = ref.data[i];
		}
	}
	Stack& operator = (const Stack<T>& ref)
	{
		if (this != &ref)
		{
			delete[] data;
			capacity = ref.capacity;
			top = ref.top;
			data = new T[capacity];
			for (int i = 0; i < top; i++)
			{
				data[i] = ref.data[i];
			}
		}
		return *this;
	}
	void push(T val)
	{
		if (isFull())
		{
			int newCapacity = (capacity == 0) ?  1 : capacity * 2;
			reSize(newCapacity);
	    }
		data[top] = val;
		top++;
	}
	T pop()
	{
		if (isEmpty()) exit(0);
		top--;
	    T val =  data[top];
		if (top > 0 && top == capacity / 4)
		{
			reSize(capacity / 2);
		}
		return val;

	}
	T stackTop()
	{
		if (isEmpty()) exit(0);
		return data[top - 1];
	}
	bool isFull()
	{
		return top == capacity;
	}
	bool isEmpty()
	{
		return top == 0;
	}
	int getCapacity()
	{
		return capacity;
	}
	int getNumberOfElements()
	{
		return top;
	}
	~Stack()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
		capacity = 0;
		top = 0;
	}

};
#endif