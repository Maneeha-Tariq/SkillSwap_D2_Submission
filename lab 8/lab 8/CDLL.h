#ifndef CDLL_H
#define CDLL_H
#include "DNode.h"
#include <iostream>
using namespace std;
template<typename T>
class CDLL
{
	DNode<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
public:

	CDLL() :head(nullptr)
	{
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (head)
		{
			p->next = head;
			p->prev = head->prev;
			head->prev->next = p;
			head->prev = p;
			head = p;
		}
		else
		{
			p->next = p;
			p->prev = p;
			head = p;
			return;
		}
	}
	void insertAtTail(T val)
	{
		DNode<T>* p = head;
		if (isEmpty())
		{
			insertAtHead(val);
			return;
		}
		while (p->next != head)
		{
			p = p->next;
		}
		DNode<T>* x = new DNode<T>(val);
		p->next = x;
		x->prev = p;
		x->next = head;
		head->prev = x;

	}
	void insertBefore(T key, T val)
	{

		if (isEmpty())
			return;

		DNode<T>* p = head;

		do
		{
			if (p->info == key)
			{

				DNode<T>* x = new DNode<T>(val);
				x->next = p;
				x->prev = p->prev;
				p->prev->next = x;
				p->prev = x;

			}
			p = p->next;
		} while (p != head);
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;

		DNode<T>* p = head;

		do
		{
			if (p->info == key)
			{

				DNode<T>* x = new DNode<T>(val);
				x->next = p->next;
				x->prev = p;
				p->next->prev = x;
				p->next = x;
			}
			p = p->next;
		} while (p != head);
	}

	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		if (head->next == head) 
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* p = head;
	
		DNode<T>* toDelete = head;
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
		head = toDelete->next;
		delete toDelete;
	}
	void removeAtTail()
	{
		if (isEmpty())
		{
			return;
		}
		if (head->next == head)
		{
			removeAtHead();
			return;
		}
		DNode<T>* p = head;

		while (p->next->next != head)
		{
			p = p->next;
		}
		DNode<T>* q = p->next;
		p->next = q->next;
		q->next->prev = q->prev;
		delete q;
	}
	void removeBefore(T key)
	{

		if (isEmpty()|| head->next == head)
		{
			return;
		}

		DNode<T>* p = head;

		do
		{
			if (p->info == key)
			{
				DNode<T>* toDelete = p->prev;
				if (toDelete == head)
				{
					head = head->next;
				}
				toDelete->next->prev = toDelete->prev;
				toDelete->prev->next = toDelete->next;
				
				delete toDelete;
				return;
			}
			p = p->next;
		} while (p != head);
		

	}
	void removeAfter(T key)
	{
		if (isEmpty() || head->next == head)
			return;

		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>* toDelete = p->next;

				
				if (toDelete == head)
					head = head->next;

				toDelete->next->prev = p;
				p->next = toDelete->next;

				delete toDelete;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	void remove(T key)
	{
		if (isEmpty())
		{
			return;
		}

		DNode<T>* p = head;

		do
		{
			if (p->info == key)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				if (head == p)
				{
					head = p->next;
				}
				delete p;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	~CDLL()
	{
		if (!head)
			return;

		DNode<T>* p = head->next;
		while (p != head)
		{
			DNode<T>* temp = p;
			p = p->next;
			delete temp;
		}
		delete head;
		head = nullptr;
	}
	
	void print()
	{
		if (!head) return;
		DNode<T>* p = head;
		do
		{
			cout << p->info << " ";
			p = p->next;
		} while (p != head);
		cout << endl;
		

	}
};
#endif