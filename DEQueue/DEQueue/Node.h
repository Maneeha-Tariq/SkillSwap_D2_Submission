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


//void remove(T key)
//{
//	if (isEmpty())
//	{
//		return;
//	}
//	if (head->info == key)
//	{
//		Node<T>* temp = head;
//		head = head->next;
//		delete temp;
//		return;
//	}
//	Node<T>* p = head;
//	
//	while (p->next && p->next->info != key)
//	{
//		p = p->next;
//	}
//	if (p->next)
//	{
//		Node<T>* temp = p->next;
//		p->next = temp->next;
//		delete temp;
//	}
//}
//void swapNodes(T key1, T key2)
//{
//	if (key1 == key2)
//	{
//		return;
//	}
//	Node<T>* curr1 = head;
//	Node<T>* prev1 = nullptr;
//	while (curr1 && curr1->info != key1)
//	{
//		prev1 = curr1;
//		curr1 = curr1->next;
//	}
//	Node<T>* curr2 = head;
//	Node<T>* prev2 = nullptr;
//	while (curr2 && curr2->info != key2)
//	{
//		prev2 = curr2;
//		curr2 = curr2->next;
//	}
//	if (!curr1 || !curr2)
//	{
//		return;
//	}
//	if (prev1)
//	{
//		prev1->next = curr2;
//	}
//	else
//	{
//		head = curr2;
//	}
//	if (prev2)
//	{
//		prev2->next = curr1;
//	}
//	else
//	{
//		head = curr1;
//	}
//	if (curr1->next == curr2)
//	{
//		curr1->next = curr2->next;
//		curr2->next = curr1;
//	}
//	else if (curr2->next == curr1)
//	{
//		curr2->next = curr1->next;
//		curr1->next = curr2;
//	}
//	else
//	{
//		Node<T>* temp = curr1->next;
//		curr1->next = curr2->next;
//		curr2->next = temp;
//	}
//
//}