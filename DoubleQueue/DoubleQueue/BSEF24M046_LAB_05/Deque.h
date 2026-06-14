// BSEF24M046
#ifndef DEQUE_H
#define DEQUE_H
template<typename T>
class DECK
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int);
public:
	DECK();
	~DECK();
	void insertElementAtRear(T);
	T removeElementFromFront();
	void insertElementAtFront(T);
	T removeElementFromRear();
	T getElementAtFront() const;
	T getElementAtRear() const;
	bool isEmpty() const;
	bool isFull() const;
	int getNoOfElements() const;
	int getCapacity() const;
};
template<typename T>
DECK<T>::DECK()
{
	rear = 0;
	front = 0;
	capacity = 0;
	noOfElements = 0;
	data = nullptr;
}
template<typename T>
DECK<T>::~DECK()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		noOfElements = 0;
	}
}
template<typename T>
bool DECK<T>::isEmpty() const
{
	return noOfElements == 0;
}
template<typename T>
bool DECK<T>::isFull() const
{
	return noOfElements == capacity;
}
template<typename T>
int DECK<T>::getNoOfElements() const
{
	return noOfElements;
}
template<typename T>
int DECK<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
T DECK<T>::getElementAtFront() const
{
	if (!isEmpty())
	{
		return data[front];
	}
	else
	{
		return T();
	}
}
template<typename T>
void DECK<T>::reSize(int newSize)
{
	if (newSize > 0)
	{
		T* temp = new T[newSize];
		for (int i = 0; i < noOfElements; i++)
		{
			temp[i] = data[(front + i) % capacity];
		}

		delete[] data;

		data = temp;
		capacity = newSize;
		front = 0;
		rear = noOfElements;
	}
}
template<typename T>
void DECK<T>::insertElementAtRear(T val)
{
	if (isFull())
	{
		reSize(capacity == 0 ? 1 : capacity * 2);
	}

	data[rear] = val;
	rear = (rear + 1) % capacity;
	noOfElements++;

}
template<typename T>
void DECK<T>::insertElementAtFront(T val)
{
	if (isFull())
	{
		reSize(capacity == 0 ? 1 : capacity * 2);
	}

	front = (front-1+capacity) % capacity;
	data[front] = val;
	noOfElements++;
}
template<typename T>
T DECK<T>::removeElementFromFront()
{
	if (noOfElements == 0)
	{
		return T();
	}

	T val = data[front];
	front = (front + 1) % capacity;
	noOfElements--;
	if (noOfElements > 0 && noOfElements == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return val;

}
template<typename T>
T DECK<T>::removeElementFromRear()
{
	if (noOfElements == 0)
	{
		return T();
	}

	T val = data[(rear-1+capacity)%capacity];
	rear = (rear -1 +capacity) % capacity;
	noOfElements--;
	if (noOfElements > 0 && noOfElements == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return val;
}
template<typename T>
T DECK<T>:: getElementAtRear() const
{
	if (!isEmpty())
	{
		return data[(rear - 1 + capacity) % capacity];
	}
	else
	{
		return T();
	}
}
#endif




