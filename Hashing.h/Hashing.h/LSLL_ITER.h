#ifndef LSLL_ITER_H
#define LSLL_ITER_H
#include <iostream>
using namespace std;
#include "Node .h"
template<typename T>
class LSLL
{
	Node<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
public:
	class Iterator
	{
		Node<T>* curr;
	public:
		Iterator(Node<T>* r = nullptr)
		{
			curr = r;
		}
		typename Iterator& operator++()
		{
			if (curr)
			{
				curr = curr->next;
			}
			return *this;
		}
		typename Iterator operator++(int)
		{
			Iterator r = *this;
			if (curr)
			{
				curr = curr->next;
			}
			return r;
		}
		T& operator*()
		{
			return curr->info;
		}
		bool operator!=(const Iterator& r)
		{
			return curr != r.curr;
		}
		bool operator==(const Iterator& r)
		{
			return curr == r.curr;
		}
	};
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
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

		if (isEmpty() || head->info == key)
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
	void removeDuplicates()
	{
		Node<T>* p = head;
		while (p != nullptr && p->next != nullptr)
		{
			Node<T>* s = p;
			while (s->next != nullptr)
			{
				if (p->info == s->next->info)
				{
					Node<T>* dup = s->next;
					s->next = s->next->next;
					delete dup;
				}
				else
				{
					s = s->next;
				}
			}
			p = p->next;
		}
	}
	void deleteAlternate()
	{
		Node<T>* p = head;
		while (p != nullptr && p->next != nullptr)
		{
			Node<T>* q = p->next;
			p->next = q->next;
			p = p->next;
			delete q;
		}
	}
	bool isEqual(LSLL<T>& list2)
	{
		bool flag = true;

		Node<T>* q = head;
		Node<T>* d = list2.head;
		while (q != nullptr && d != nullptr)
		{
			if (q->info != d->info)
			{
				flag = false;
				break;
			}

			q = q->next;
			d = d->next;
		}
		if (d == nullptr && q == nullptr && flag == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	LSLL<T> doUnion(LSLL<T>& list2)
	{
		LSLL<T> a;
		Node<T>* p = head;
		while (p != nullptr)
		{
			a.insertAtTail(p->info);
			p = p->next;
		}
		Node<T>* q = list2.head;

		while (q != nullptr)
		{
			Node<T>* temp = a.head;
			bool exists = false;
			while (temp != nullptr)
			{
				if (q->info == temp->info)
				{
					exists = true;
					break;

				}
				temp = temp->next;
			}
			if (!exists)
			{
				a.insertAtTail(q->info);
			}
			q = q->next;
		}
		return a;
	}
	void swap(int m, int n)
	{
		if (m == n) exit(0);

		Node<T>* p = head;
		Node<T>* prevM = nullptr;
		int count = 1;
		while (p != nullptr && count < m)
		{
			prevM = p;
			p = p->next;
			count++;
		}

		Node<T>* q = head;
		Node<T>* prevN = nullptr;
		int count1 = 1;
		while (q != nullptr && count1 < n)
		{
			prevN = q;
			q = q->next;
			count1++;
		}
		if (!p || !q)
		{
			return;
		}

		if (prevM != nullptr) prevM->next = q;
		else head = q;


		if (prevN != nullptr)   prevN->next = p;
		else head = p;

		if (p->next == q)
		{
			if (prevM) prevM->next = q;
			else head = q;

			p->next = q->next;
			q->next = p;
		}
		else
		{
			Node<T>* temp = p->next;
			p->next = q->next;
			q->next = temp;
		}
	}
	void splitList(LSLL<T>& list1, LSLL<T>& list2)
	{
		if (head == nullptr) exit(0);

		Node<T>* p = head;
		int count = 0;
		while (p != nullptr)
		{
			count++;
			p = p->next;
		}
		Node<T>* q = head;
		if (count % 2 == 0)
		{
			int i = 0;
			while (q != nullptr && i < count / 2)
			{
				T r = q->info;
				list1.insertAtTail(r);
				q = q->next;
				i++;
			}
			int j = 0;
			while (q != nullptr && j < count / 2)
			{
				T r = q->info;
				list2.insertAtTail(r);
				q = q->next;
				j++;
			}
		}
		else
		{
			int i = 0;
			while (q != nullptr && i < (count + 1) / 2)
			{
				T r = q->info;
				list1.insertAtTail(r);
				q = q->next;
				i++;
			}
			int j = 0;
			while (q != nullptr && j < count / 2)
			{
				T r = q->info;
				list2.insertAtTail(r);
				q = q->next;
				j++;
			}

		}
		Node<T>* r = head;
		cout << "Original list: ";
		while (r != nullptr)
		{
			cout << r->info << " ";
			r = r->next;
		}

		cout << "\nList 1: ";
		Node<T>* y = list1.head;
		while (y != nullptr)
		{
			cout << y->info << " ";
			y = y->next;
		}

		cout << "\nList 2: ";
		Node<T>* d = list2.head;
		while (d != nullptr)
		{
			cout << d->info << " ";
			d = d->next;
		}

		while (head != nullptr)
		{
			removeAtHead();
		}
		head = nullptr;
	}
	T findMiddlePoint()
	{
		if (head == nullptr) exit(0);

		Node<T>* p = head;
		int count = 0;
		while (p != nullptr)
		{
			count++;
			p = p->next;
		}
		if (count % 2 != 0)
		{
			Node<T>* q = head;
			int i = 1;
			while (q != nullptr && i < (count + 1) / 2)
			{
				q = q->next;
				i++;
			}
			return q->info;
		}
		else
		{
			Node<T>* q = head;
			int i = 1;
			while (q != nullptr && i < count / 2)
			{
				q = q->next;
				i++;
			}
			return q->info;
		}
	}
	bool search(T val)
	{
		Node<int>* p = head;
		while (p != nullptr)
		{
			if (p->info == val)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}

};
#endif



