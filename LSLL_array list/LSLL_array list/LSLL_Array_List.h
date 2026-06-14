#ifndef LSLL_ARRAY_LIST_H
#define LSLL_ARRAY_LIST_H
#include "Node1.h"
#include<iostream>
using namespace std;
template<typename T>
class LSLL
{
	int head;
	int avail;
	Node1<T> data[9];
	int getNewNode()
	{
		if (avail != -1)
		{
			int x = avail;
			avail = data[avail].next;
			return x;
		}
		exit(0);
	}
	void getItBack(int node)
	{
		data[node].next = avail;
		avail = node;
		/*while (data[x].next != -1)
			x = data[x].next;
		data[x].next = node;
		data[node].next = -1;*/
	}
public:
	LSLL()
	{
		for (int i = 0; i < 8; i++)
			data[i].next = i + 1;
		data[8].next = -1;
		head = -1;
		avail = 0;
	}
	void insertAtTail(T val)
	{
		if (isEmpty())
		{
			insertAtHead(val);
			return;
		}
		int p = head;
		while (data[p].next != -1)
			p = data[p].next;
		int x = getNewNode();
		data[x].next = -1;
		data[x].info = val;
		data[p].next = x;

	}

	void insertAtHead(T val)
	{
		int x = getNewNode();
		data[x].next = head;
		data[x].info = val;
		head = x;
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;
		int p = head;
		while (data[p].next != -1 && data[p].info != key)
			p = data[p].next;
		if (data[p].info == key)
		{
			int x = getNewNode();
			data[x].info = val;
			data[x].next = data[p].next;
			data[p].next = x;
		}
	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
			return;
		int p = head;

		if (data[p].info == key)
		{
			insertAtHead(val);
			return;
		}
		while (data[p].next != -1 && data[data[p].next].info != key)
			p = data[p].next;
		if (data[p].next != -1)
		{
			int x = getNewNode();
			data[x].info = val;
			data[x].next = data[p].next;
			data[p].next = x;
		}
	}
	void remove(T key)
	{
		if (isEmpty())
			return;
		if (data[head].info == key)
		{
			removeAtHead();
			return;
		}
		int p = head;
		while (data[data[p].next].next != -1 && data[data[p].next].info != key)
			p = data[p].next;
		if (data[data[p].next].info == key)
		{
			int x = data[p].next;
			data[p].next = data[data[p].next].next;
			getItBack(x);
		}
	}
	void removeAtHead()
	{
		if (isEmpty())
			return;
		int x = head;
		head = data[head].next;
		getItBack(x);
	}
	void removeAtTail()
	{
		int p = head;
		if (data[p].next == -1)
		{
			removeAtHead();
			return;
		}
		while (data[data[p].next].next != -1)
			p = data[p].next;
		getItBack(data[p].next);
		data[p].next = -1;
	}
	void removeAfter(T key)
	{
		if (isEmpty())
			return;
		int p = head;
		while (data[p].next != -1 && data[p].info != key)
			p = data[p].next;
		if (data[p].info == key)
		{
			int q = data[p].next;
			data[p].next = data[data[p].next].next;
			getItBack(q);
		}
	}
	void removeBefore(T key)
	{
		if (isEmpty())
			return;
		if (data[head].next != -1)
		{
			if (data[data[head].next].info == key)
			{
				removeAtHead();
				return;
			}
			int p = head;
			while (data[data[p].next].next != -1 && data[data[data[p].next].next].info != key)
				p = data[p].next;
			if (data[data[data[p].next].next].info == key)
			{
				int q = data[p].next;
				data[p].next = data[data[p].next].next;
				getItBack(q);
			}
		}
	}
	bool isEmpty()
	{
		return head == -1 ? true : false;
	}
	void display()
	{
		int p = head;
		while (p != -1)
		{
			cout << data[p].info << " ";
			p = data[p].next;
		}
	}
	
};

#endif



//#ifndef LSLL_ARRAY_LIST_H
//#define LSLL_ARRAY_LIST_H
//#include "Node1.h"
//#include<iostream>
//using namespace std;
//
//template<typename T>
//class LSLL
//{
//	int head;
//	int avail;
//	int capacity;        // total slots in the array
//	Node1<T>* data;      // dynamic array of nodes
//
//	int getNewNode()
//	{
//		if (avail != -1)
//		{
//			int x = avail;
//			avail = data[avail].next;
//			return x;
//		}
//		cout << "No space available!\n";
//		exit(0);
//	}
//
//	void getItBack(int node)
//	{
//		data[node].next = avail;
//		avail = node;
//	}
//
//public:
//	
//	LSLL(int size = 10)
//	{
//		capacity = size;
//		data = new Node1<T>[capacity];
//		for (int i = 0; i < capacity - 1; i++)
//			data[i].next = i + 1;
//		data[capacity - 1].next = -1;
//		head = -1;
//		avail = 0;
//	}
//
//	
//	~LSLL()
//	{
//		delete[] data;
//	}
//
//	void insertAtTail(T val)
//	{
//		if (isEmpty())
//		{
//			insertAtHead(val);
//			return;
//		}
//		int p = head;
//		while (data[p].next != -1)
//			p = data[p].next;
//		int x = getNewNode();
//		data[x].next = -1;
//		data[x].info = val;
//		data[p].next = x;
//	}
//
//	void insertAtHead(T val)
//	{
//		int x = getNewNode();
//		data[x].next = head;
//		data[x].info = val;
//		head = x;
//	}
//
//	void insertAfter(T key, T val)
//	{
//		if (isEmpty())
//			return;
//		int p = head;
//		while (data[p].next != -1 && data[p].info != key)
//			p = data[p].next;
//		if (data[p].info == key)
//		{
//			int x = getNewNode();
//			data[x].info = val;
//			data[x].next = data[p].next;
//			data[p].next = x;
//		}
//	}
//
//	void insertBefore(T key, T val)
//	{
//		if (isEmpty())
//			return;
//		int p = head;
//
//		if (data[p].info == key)
//		{
//			insertAtHead(val);
//			return;
//		}
//		while (data[p].next != -1 && data[data[p].next].info != key)
//			p = data[p].next;
//		if (data[p].next != -1)
//		{
//			int x = getNewNode();
//			data[x].info = val;
//			data[x].next = data[p].next;
//			data[p].next = x;
//		}
//	}
//
//	void remove(T key)
//	{
//		if (isEmpty())
//			return;
//		if (data[head].info == key)
//		{
//			removeAtHead();
//			return;
//		}
//		int p = head;
//		while (data[data[p].next].next != -1 && data[data[p].next].info != key)
//			p = data[p].next;
//		if (data[data[p].next].info == key)
//		{
//			int x = data[p].next;
//			data[p].next = data[data[p].next].next;
//			getItBack(x);
//		}
//	}
//
//	void removeAtHead()
//	{
//		if (isEmpty())
//			return;
//		int x = head;
//		head = data[head].next;
//		getItBack(x);
//	}
//
//	void removeAtTail()
//	{
//		int p = head;
//		if (data[p].next == -1)
//		{
//			removeAtHead();
//			return;
//		}
//		while (data[data[p].next].next != -1)
//			p = data[p].next;
//		getItBack(data[p].next);
//		data[p].next = -1;
//	}
//
//	void removeAfter(T key)
//	{
//		if (isEmpty())
//			return;
//		int p = head;
//		while (data[p].next != -1 && data[p].info != key)
//			p = data[p].next;
//		if (data[p].info == key)
//		{
//			int q = data[p].next;
//			data[p].next = data[data[p].next].next;
//			getItBack(q);
//		}
//	}
//
//	void removeBefore(T key)
//	{
//		if (isEmpty())
//			return;
//		if (data[head].next != -1)
//		{
//			if (data[data[head].next].info == key)
//			{
//				removeAtHead();
//				return;
//			}
//			int p = head;
//			while (data[data[p].next].next != -1 && data[data[data[p].next].next].info != key)
//				p = data[p].next;
//			if (data[data[data[p].next].next].info == key)
//			{
//				int q = data[p].next;
//				data[p].next = data[data[p].next].next;
//				getItBack(q);
//			}
//		}
//	}
//
//	bool isEmpty()
//	{
//		return head == -1;
//	}
//
//	void display()
//	{
//		int p = head;
//		while (p != -1)
//		{
//			cout << data[p].info << " ";
//			p = data[p].next;
//		}
//		cout << endl;
//	}
//};
//
//#endif
//
