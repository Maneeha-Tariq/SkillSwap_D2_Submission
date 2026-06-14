//Bsef24M046
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
	void reSize(int newSize);
public:
	Stack();
	Stack(const Stack<T>& ref);
	Stack& operator=(const Stack<T>& ref);
	~Stack();
	void push(T val);
	T pop();
	T stackTop();
	bool isFull();
	bool isEmpty();
	int getCapacity();
	int getNumberOfElements();
	/*void display();*/
};
template<typename T>
Stack<T>::Stack()
{
	data = nullptr;
	capacity = 0;
	top = 0;
}
template<typename T>
T Stack<T>::stackTop()
{
	if (isEmpty())
	{
		exit(0);
	}
	return data[top - 1];
}
template<typename T>
bool Stack<T>::isFull()
{
	return top == capacity;
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return top == 0;
}
template<typename T>
int Stack<T>::getCapacity()
{
	return capacity;
}
template<typename T>
int Stack<T>::getNumberOfElements()
{
	return top;
}
template<typename T>
void Stack<T>::reSize(int newSize)
{
	T* temp = new T[newSize];
	for (int i = 0; i < top; i++)
	{
		temp[i] = data[i];
	}
	int tempTop = top;
	this->~Stack();
	data = temp;
	capacity = newSize;
	top = tempTop;
}
template<typename T>
void Stack<T>::push(T val)
{
	if (isFull())
	{
		reSize(capacity == 0 ? 1 : capacity * 2);
	}
	data[top++] = val;
}
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		exit(0);
	}
	T val = data[--top];
	if (top > 0 && top == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return val;
}
template<typename T>
Stack<T>:: ~Stack()
{
	if (data)
	{
		delete[] data;
		capacity = 0;
		data = nullptr;
		top = 0;
	}
	return;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	if (ref.capacity <= 0)
		return;
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < ref.top; i++)
	{
		data[i] = ref.data[i];
	}
	top = ref.top;
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref)
{
	if (ref.capacity == 0)
	{
		this->~Stack();
		return *this;
	}
	if (this == &ref)
		return *this;
	this->~Stack();
	capacity = ref.capacity;
	data = new T[capacity];
	int i;
	for (i = 0; i < ref.top; i++)
	{
		data[i] = ref.data[i];
	}
	top = ref.top;
	return *this;
}
//template<typename T>
//void Stack<T>::display()
//{
//	for (int i = 0; i < getNumberOfElements(); i++)
//	{
//		cout << data[i] << " ";
//	}
//}
#endif