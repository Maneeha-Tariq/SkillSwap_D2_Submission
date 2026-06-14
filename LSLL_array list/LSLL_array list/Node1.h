#ifndef NODE1_H
#define NODE1_H
#include<iostream>
using namespace std;
template<typename T>
struct Node1
{
	T info;
	int next;
public:

	Node1():next(-1)
	{ }

	Node1(T val): info(val),next(-1)
	{ }
    
};
#endif