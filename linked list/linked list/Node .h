#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node() : next(nullptr)
	{
	}
	Node(T val) : info(val), next(nullptr)
	{
	}
	~Node()
	{
		delete next;
	}
};
#endif