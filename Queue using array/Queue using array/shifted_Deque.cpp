//#include<iostream>
//using namespace std;
//template<typename T>
//class Queue
//{
//	T* arr;
//	int front;
//	int rear;
//	int size;
//public:
//	Queue(int s)
//	{
//		arr = new T[s];
//		front = -1;
//		rear = -1;
//		size = s;
//	}
//	bool isEmpty()
//	{
//		if (front == -1 && rear == -1)
//		{
//			return 1;
//		}
//		return false;
//	}
//	bool isFull()
//	{
//		return rear == size - 1 ? 1 : 0;
//	}
//	void enQueue(T x)
//	{
//		if (isEmpty())
//		{
//			cout << "Pushed " << x << " into the Queue\n";
//			front = 0;
//			rear = 0;
//			arr[rear] = x;
//		}
//		else if (isFull())
//		{
//			cout << "Queue overflow\n";
//			return;
//		}
//		else
//		{
//			cout << "Pushed " << x << " into the Queue\n";
//			rear = rear + 1;
//			arr[rear] = x;
//		}
//	}
//	T deQueue()
//	{
//		if (isEmpty())
//		{
//			cout << "Queue Underflow\n";
//			return T();
//		}
//		else if (rear == front)
//		{
//			T element = arr[front];
//			cout << "Popped " << arr[front] << " from the Queue\n";
//			front = -1;
//			rear = -1;
//			return element;
//
//		}
//		else
//		{
//			T element = arr[front];
//			cout << "Popped " << arr[front] << " from the Queue\n";
//			int oldFront = front;
//			front = front + 1;
//			for (int i = front; i <= rear; i++)
//			{
//				arr[i - 1] = arr[i];
//			}
//			front = 0;
//			rear = rear - oldFront - 1;
//			return element;
//		}
//	}
//	T start()
//	{
//		if (front == -1)
//		{
//			cout << "Queue is Empty\n";
//			return T();
//		}
//		else
//		{
//			return arr[front];
//		}
//	}
//};
//int main()
//{
//	Queue<int>q(4);
//	q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//	q.enQueue(4);
//	q.deQueue();	
//	q.deQueue();
//	q.deQueue();
//	q.deQueue();
//	int start = q.start();
//	if (start)
//	{
//		cout << start;
//	}
//
//	return 0;
//}