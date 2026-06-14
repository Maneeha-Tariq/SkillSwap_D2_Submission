// BSEF24M046
#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"
template<typename T>
class DEQueue
{
	Node<T> * rear;
	Node<T> * front;
	int noOfElements;
public:
	DEQueue();
	~DEQueue();
	void insertElementAtRear(T);
	T removeElementFromFront();
	void insertElementAtFront(T);
	T removeElementFromRear();
	T getElementAtFront() const;
	T getElementAtRear() const;
	bool isEmpty() const;
	int getNoOfElements() const;
	
};
template<typename T>
//WorstCaseUpperBound = BigO(1)
DEQueue<T>::DEQueue() : noOfElements(0), rear(nullptr), front(0)
{
	
}
template<typename T>
//WorstCaseUpperBound =BigO(N) 
DEQueue<T>::~DEQueue()
{
	if (rear)
	{
		delete rear;
		rear = nullptr;
	}
	if (front)
	{
		delete front;
		front = nullptr;
	}
}
template<typename T>
// worstcase upperbound = BigO(1)
bool DEQueue<T>::isEmpty() const
{
	return noOfElements == 0 || front == nullptr || rear == nullptr;
}

template<typename T>
// worst case upperbound = BigO(1)
int DEQueue<T>::getNoOfElements() const
{
	return noOfElements;
}

template<typename T>
//WorstCaseUpperBound = BigO(N)
T DEQueue<T>::getElementAtFront() const
{
	if (!isEmpty())
	{
		return front->info;
	}
	else
	{
		return T();
	}
}
template<typename T>
// WorstCaseUpperBound = BigO(N)
void DEQueue<T>::insertElementAtRear(T val)
{
		Node<T>* p = new Node<T>(val);
		p->next = rear;
		rear = p;
		noOfElements++;

}
template<typename T>
// WorstCaseUpperBound = BigO(N)
void DEQueue<T>::insertElementAtFront(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = front;
    front = p;
	noOfElements++;
}
template<typename T>
// worstCaseUpperbound = BigO(N)
T DEQueue<T>::removeElementFromFront()
{
	if (noOfElements == 0)
	{
		return T();
	}
	if (!front)
	{
		return;
	}
	T val = front->info;

	front->info = 0;
	front = front->next;
	noOfElements--;
	return val;

}
template<typename T>
//WorstCaseUppebound = BigO(N)
T DEQueue<T>::removeElementFromRear()
{
	if (noOfElements == 0)
	{
		return T();
	}
	if (!rear)
	{
		return;
	}
	T val = rear->info;
	rear->info = 0;
	rear = rear->next;
	noOfElements--;
	
	return val;
}
template<typename T>
//WorstCaseUpperBound = BigO(N)
T DEQueue<T>::getElementAtRear() const
{
	if (!isEmpty())
	{
		return rear->info;
	}
	else
	{
		return T();
	}
}
#endif




