#ifndef LSLL_H
#define LSLL_H
#include <iostream>
using namespace std;
#include"Node.h"
template<typename T>
class LSLL
{
	Node<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
public:
	LSLL() :head(nullptr)
	{
	}
	LSLL(const LSLL<T>& x)
	{
		if (x.head == nullptr)
		{
			head = nullptr;
			return;
		}
		head = new Node<T>(x.head->info);

		Node<T>* src = x.head->next;
		Node<T>* dest = head;
		while (src != nullptr)
		{
			dest->next = new Node<T>(src->info);
			dest = dest->next;
			src = src->next;
		}
	}
	void insertAtHead(T val)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
	}
	void insertAtTail(T val)
	{
		Node<T>* p = head;
		if (isEmpty())
		{
			insertAtHead(val);
			return;
		}
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(val);

	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
		{
			return;
		}
		Node<T>* p = head;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		while (p->next && p->next->info != key)
		{
			p = p->next;
		}
		if (p->next)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p->next;
			p->next = x;
		}
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;

		Node<T>* p = head;

		while (p && p->info != key)
		{
			p = p->next;
		}

		if (!p)
			return;
		
		Node<T>* x = new Node<T>(val);
		x->next = p->next;
		p->next = x;
	}

	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
	void removeAtTail()
	{
		if (isEmpty())
		{
			return;
		}
		if (head->next == nullptr)
		{
			removeAtHead();
			return;
		}
		Node<T>* p = head;
		
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		Node<T>* q = p->next;
		p->next = nullptr;
		delete q;
	}
	void removeBefore(T key)
	{

		if (isEmpty()|| head->info == key)
		{
			return;
		}
		if (head->next && head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next->next;
		while (p && p->info != key)
		{
			p = p->next;
			prev = prev->next;
		}
		if (p != nullptr)
		{
			Node<T>* temp = prev->next;
			prev->next = p;
			delete temp;
		}
	}
	void removeAfter(T key)
	{
		if (isEmpty())
		{
			return;
		}
		Node<T>* p = head;
		while (p && p->info != key)
		{
			p = p->next;
		}
		if (p && p->next)
		{
			Node<T>* toDelete = p->next;
			p->next = toDelete->next;
			delete toDelete;
		}
		
	}
	void remove(T key)
	{
		if (isEmpty())
		{
			return;
		}
		if (head->info == key)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node<T>* p = head;
		
		while (p->next && p->next->info != key)
		{
			p = p->next;
		}
		if (p->next)
		{
			Node<T>* t = p->next;
			p->next = p->next->next;
			delete t;
		}
	}
	~LSLL()
	{
		while (head)
		{
			removeAtHead();
		}
		head = nullptr;
	}
	void workhousePrint(Node<T>* ptr)
	{
		if (!ptr)
		{
			return;
		}
		cout << ptr->info << " ";
		workhousePrint(ptr->next);

	}
	void print()
	{
		workhousePrint(head);
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