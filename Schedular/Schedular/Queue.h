#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int );
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	int getNoOfElements() const;
	int getCapacity() const;
	Queue(const Queue<T>& );
	Queue& operator=(const Queue<T>& );
	void enQueue(T);
	T deQueue();
	T getElementAtFront() const;
};
template<typename T>
Queue<T>::Queue()
{
	rear = 0;
	front = 0;
	capacity = 0;
	noOfElements = 0;
	data = nullptr;
}
template<typename T>
Queue<T>::~Queue()
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
bool Queue<T>:: isEmpty() const
{
	return noOfElements == 0;
}
template<typename T>
bool Queue<T>:: isFull() const
{
	return noOfElements == capacity;
}
template<typename T>
int Queue<T>::getNoOfElements() const
{
	return noOfElements;
}
template<typename T>
int Queue<T>:: getCapacity() const
{
	return capacity;
}
template<typename T>
Queue<T>::Queue(const Queue<T>& ref)
{
	if (ref.capacity <= 0)
		return;
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < ref.noOfElements; i++)
	{
		data[i] = ref.data[i];
	}
	noOfElements = ref.noOfElements;
	rear = ref.rear;
	front = ref.front;
}
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& ref)
{
	if (ref.capacity == 0)
	{
		delete[] data;
		return *this;
	}
	if (this == &ref)
		return *this;
	delete[] data;
	capacity = ref.capacity;
	data = new T[capacity];
	int i;
	for (i = 0; i < ref.noOfElements; i++)
	{
		data[i] = ref.data[i];
	}
	noOfElements = ref.noOfElements;
	rear = ref.rear;
	front = ref.front;
	return *this;
}
template<typename T>
void Queue<T>::enQueue(T val)
{
	if (capacity <= 0)
	{
		reSize(1);
	}
	if (isFull())
	{
		reSize(capacity * 2);
	}

	data[rear] = val;
	rear = (rear + 1) % capacity;
	noOfElements++;
}
template<typename T>
T Queue<T>::deQueue()
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
T Queue<T>:: getElementAtFront() const
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
void Queue<T>::reSize(int newSize)
{
	if (newSize > 0)
	{
		T* temp = new T[newSize];
		for (int i = 0; i < noOfElements; i++)
		{
			temp[i] = data[(front+i)%capacity];
		}

		delete[] data;

		data = temp;
		capacity = newSize;
		front = 0;
		rear = noOfElements;
	}
}
#endif
