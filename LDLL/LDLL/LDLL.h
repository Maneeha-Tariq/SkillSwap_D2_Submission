#ifndef LDLL_H
#define LDLL_H
#include "DNode.h"
#include<iostream>
using namespace std;
template<typename T>
class LDLL
{
	DNode<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
public:

	LDLL() :head(nullptr)
	{
	}
	void insertAtHead(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (head)
		{
			p->next = head;
			head->prev = p;
			head = p;
		}
		else
		{
			p->next = head;
			head = p;
			head->prev = nullptr;
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
		while (p->next != nullptr)
		{
			p = p->next;
		}
		DNode<T>* x =  new DNode<T>(val);
		p->next = x;
		x->prev = p;
		x->next = nullptr;

	}
	void insertBefore(T key, T val)
	{
		DNode<T>* p = head;
		while(p!=nullptr && p->info!=key)
		{
			p = p->next;
		}
		if (!p)
		{
			return;
		}
		DNode<T>* x = new DNode<T>(val);
		x->next = p;																
		x->prev = p->prev;
		p->prev = x;
		x->prev->next = x;
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;

		DNode<T>* p = head;

		while (p && p->info != key)
		{
			p = p->next;
		}

		if (!p)
			return;

		DNode<T>* x = new DNode<T>(val);
		x->prev = p;
		x->next = p->next;
		if (p->next != nullptr)
		{
			p->next->prev = x;
		}
		p->next = x;
	}

	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		DNode<T>* p = head;
		if (p->next != nullptr)
		{
			p->next->prev = p->prev;
		}
		head = p->next;
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
		DNode<T>* p = head;

		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		DNode<T>* q = p->next;
		p->next = nullptr;
		delete q;
	}
	void removeBefore(T key)
	{

		if (isEmpty() || head->info == key)
		{
			return;
		}
		if (head->next && head->next->info == key)
		{
			removeAtHead();
			return;
		}
		DNode<T>* pre = head;
		DNode<T>* p = head->next->next;
		while (p && p->info != key)
		{
			p = p->next;
			pre = pre->next;
		}
		if (p != nullptr)
		{
			DNode<T>* temp = pre->next;
			pre->next = p;
			p->prev = pre;
			delete temp;
		}
	}
	void removeAfter(T key)
	{
		if (isEmpty())
		{
			return;
		}
		DNode<T>* p = head;
		while (p && p->info != key)
		{
			p = p->next;
		}
		if (p && p->next)
		{
			DNode<T>* toDelete = p->next;
			p->next = toDelete->next;
			if (toDelete->next != nullptr)
			{
				toDelete->next->prev = p;
			}
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
			DNode<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		DNode<T>* p = head;

		while (p->next && p->next->info != key)
		{
			p = p->next;
		}
		if (p->next)
		{
			DNode<T>* t = p->next;
			p->next = p->next->next;
			if (p->next->next != nullptr)
			{
				p->next->next->prev = p;
			}
			delete t;
		}
	}
	~LDLL()
	{
		while (head)
		{
			removeAtHead();
		}
		head = nullptr;
	}
	void workhousePrint(DNode<T>* ptr)
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
	void reversePrintIteratively()
	{
		if (!head)
		{
			return;
		}
		if (head->next == nullptr)
		{
			cout << head->info << " ";
			return;
		}
		DNode<T>* p = head;
		
		while (p->next != nullptr)
		{
			p = p->next;
		}
		DNode<T>* q = p;
		while (q != head)
		{
			cout << q->info << " ";
			q = q->prev;
		}
		cout << q->info << " ";
	}
	void reverseHelper(DNode<T> * p)
	{
		if (p->prev == nullptr)
		{
			cout << p->info << " ";
			return;
		}
		cout << p->info << " ";
		p = p->prev;
		reverseHelper(p);
	}
	void reversePrintRecursively()
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		reverseHelper(temp);
	}
	// easy version cost o(n2) space o(1)
	void findPairs(int x)
	{
		if (head == nullptr)
		{
			return;
		}
		bool find = false;
		DNode<T>* p = head;
		while (p != nullptr)
		{
			DNode<T>* q = p->next;
			while (q != nullptr)
			{
				int sum = p->info + q->info;
				if (sum == x)
				{
					cout << "(" << q->info << "," << p->info << ")";
					find = true;
				}
				q = q->next;
			}
			p = p->next;
		}
		if (!find)
		{
			cout << "No pair found";
		}
	}
	// cost o(n) space o(1)
	void pairFind(int x)
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T>* start = head;
		DNode<T>* tail = head;
		bool find = false;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		while (start!=tail && start->prev!=tail)
		{
			int sum = start->info + tail->info;
			if (sum == x)
			{
				cout << "(" << tail->info << "," << start->info << ")";
				start = start->next;
				tail = tail->prev;
				find = true;
			}
			else if (sum < x)
			{
				start=start->next;
			}
			else
			{
				tail = tail->prev;
			}

		}
		if (!find)
		{
			cout << "No pair found";
		}
		
	}
	void reverse()
	{
		Node<T>* temp = nullptr;
		Node<T>* current = head;
		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}
};
#endif