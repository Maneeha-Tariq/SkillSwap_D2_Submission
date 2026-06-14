#include<iostream>
using namespace std;
template<typename T>
class Deque
{
	int rear;
	int front;
	int size;
	T* arr;
public:
	Deque(int s)
	{
		size = s;
		arr = new T[size];
		rear = -1;
		front = -1;
	}
	void push_front(T x)
	{
		if (isFull())
		{
			cout << "Deque is Full\n";
			return;
		}
		if (isEmpty())
		{
			front = rear = 0;
			arr[front] = x;
			cout << "Pushed " << arr[front] << " into the front of deque\n";
			return;
		}
		front = (front - 1 + size) % size;
		arr[front] = x;
		cout << "Pushed " << arr[front] << " into the front of deque\n";
	}
	void push_back(int x)
	{
		if (isFull())
		{
			cout << "Deque is Full\n";
			return;
		}
		if (isEmpty())
		{
			front = rear = 0;
			arr[front] = x;
			cout << "Pushed " << arr[rear] << " into the back of deque\n";
			return;
		}
		rear = (rear + 1) % size;
		arr[rear] = x;
		cout << "Pushed " << arr[rear] << " into the back of deque\n";
	}
	void pop_front()
	{
		if (isEmpty())
		{
			cout << "Deque is Empty\n";
			return ;
		}
		if (rear == front)
		{
			cout << "Pop " << arr[front] << " into the front of deque\n";
			front = rear = -1;
		}
		else
		{
			cout << "Pop " << arr[front] << " into the front of deque\n";
			front = (front + 1) % size;
		}
		
	}
	void pop_back()
	{
		if (isEmpty())
		{
			cout << "Deque is Empty\n";
			return ;
		}
		if (rear == front)
		{
			cout << "Pop " << arr[rear] << " into the back of deque\n";
			front = rear = -1;
		}
		else
		{
			cout << "Pop " << arr[rear] << " into the back of deque\n";
			rear = (rear - 1 + size) % size;
		}
	}
	T start()
	{
		if (isEmpty())
		{
			cout << "Deque is Empty\n";
			return T();
		}
		return arr[front];
	}
	T back()
	{
		if (isEmpty())
		{
			cout << "Deque is Empty\n";
			return T();
		}
		return arr[rear];
	}
	bool isEmpty()
	{
		return front == -1;
	}
	bool isFull()
	{
		return front == (rear + 1) % size; 
	}
};
void pattern(int i)
{
	if (i == 0)
	{
		return;
	}
	for (int j = 0; j < i; j++)
	{
		cout << "*";
	}
	cout << endl;
	pattern(i - 1);
}
int main()
{
	/*Deque<int> d(5);
	d.push_front(7);
	d.push_front(8);
	d.push_back(2);
	d.pop_back();
	d.push_back(9);
	d.push_front(3);
	if (d.isFull())
	{
		cout << "Deque is Full\n";
	}
	else
	{
		cout << "Deque Not Full\n";
	}
	d.push_back(5);
	if (d.isFull())
	{
		cout << "Deque is Full\n";
	}
	else
	{
		cout << "Deque Not Full\n";
	}*/
	
	pattern(4);
}