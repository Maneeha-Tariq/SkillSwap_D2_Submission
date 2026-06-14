//#ifndef MIN_HEAP_H
//#define MIN_HEAP_H
//#include <iostream>
//using namespace std;
//template<typename T>
//class MinHeap
//{
//	int* timestamp;
//	T* data;
//	int N;
//	int noe;
//	int ts;
//public:
//	MinHeap(int s)
//	{
//		N = s;
//		noe = 0;
//		data = new T[N];
//		timestamp = new int[N];
//		ts = 1;
//	}
//	void insert(T val)
//	{
//
//		if (isFull())
//		{
//			cout << "Capacity is full";
//			return;
//		}
//		
//			
//		data[noe] = val;
//		timestamp[noe] = ts++;
//		int i = noe;
//		noe++;
//
//		while (i > 0)
//		{
//			int par = (i - 1) / 2;
//			if ((data[par] > data[i]) || (data[par] == data[i] && timestamp[par] > timestamp[i]))
//			{
//				T temp = data[par];
//				data[par] = data[i];
//				data[i] = temp;
//
//				int t = timestamp[par];
//				timestamp[par] = timestamp[i];
//				timestamp[i] = t;
//
//				i = par;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	T getMin() 
//	{
//		if (isEmpty())
//		{
//			cout << "Array is Empty";
//			exit(0);
//		}
//		return data[0];
//	}
//	T remove()
//	{
//		if (isEmpty())
//		{
//			cout << "No data found";
//			exit(0);
//		}
//
//		T val = data[0];
//		data[0] = data[noe - 1];
//		timestamp[0] = timestamp[noe - 1];
//		noe--;
//
//		int i = 0;
//		int leftChild = 2 * i + 1;
//		int rightChild = 2 * i + 2;
//
//		while (leftChild < noe)
//		{
//			int smallerChild = leftChild;
//			if (rightChild < noe && data[rightChild] < data[leftChild] || (data[rightChild] == data[leftChild] && 
//				timestamp[rightChild] < timestamp[leftChild]))
//			{
//				smallerChild = rightChild;
//			}
//			if ((data[i] > data[smallerChild]) || data[i] == data[smallerChild] && timestamp[i] > timestamp[smallerChild])
//			{
//				T temp = data[i];
//				data[i] = data[smallerChild];
//				data[smallerChild] = temp;
//
//				int t = timestamp[i];
//				timestamp[i] = timestamp[smallerChild];
//				timestamp[smallerChild] = t;
//
//				i = smallerChild;
//			}
//			else
//			{
//				break;
//			}
//
//			leftChild = 2 * i + 1;
//			rightChild = 2 * i + 2;
//		}
//		return val;
//		
//	}
//	bool isEmpty()
//	{
//		return noe == 0;
//	}
//	bool isFull()
//	{
//		return noe == N;
//	}
//	int getNoOfElements()
//	{
//		return noe;
//	}
//	~MinHeap()
//	{
//		if (data)
//		{
//			delete[] data;
//			data = nullptr;
//		}
//		if (timestamp)
//		{
//			delete[] timestamp;
//			timestamp = nullptr;
//		}
//	}
//	void printHeap() 
//	{
//		if (isEmpty())
//		{
//			cout << "Heap is empty\n";
//			return;
//		}
//
//		cout << "Heap elements (value : timestamp):\n";
//		for (int i = 0; i < noe; i++)
//		{
//			cout << data[i] << " : " << timestamp[i] <<"\t";
//		}
//		cout << "\n";
//	}
//
//};
//#endif


#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <iostream>
using namespace std;

template<typename T>
class MinHeap
{
    T* data;
    int N;
    int noe;

public:
    MinHeap(int s)
    {
        N = s;
        noe = 0;
        data = new T[N];
    }

    void insert(T val)
    {
        if (isFull())
        {
            cout << "Capacity is full";
            return;
        }

        data[noe] = val;
        int i = noe;
        noe++;

        while (i > 0)
        {
            int par = (i - 1) / 2;
            if (data[par] > data[i])
            {
                T temp = data[par];
                data[par] = data[i];
                data[i] = temp;
                i = par;
            }
            else
                break;
        }
    }

    T getMin()
    {
        if (isEmpty())
        {
            cout << "Heap is Empty";
            exit(0);
        }
        return data[0];
    }

    T remove()
    {
        if (isEmpty())
        {
            cout << "Heap is Empty";
            exit(0);
        }

        T val = data[0];
        data[0] = data[noe - 1];
        noe--;

        int i = 0;

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left >= noe)
                break;

            int smallest = left;

            if (right < noe && data[right] < data[left])
                smallest = right;

            if (data[i] > data[smallest])
            {
                T temp = data[i];
                data[i] = data[smallest];
                data[smallest] = temp;
                i = smallest;
            }
            else
                break;
        }

        return val;
    }

    bool isEmpty()
    {
        return noe == 0;
    }

    bool isFull()
    {
        return noe == N;
    }

    int getNoOfElements()
    {
        return noe;
    }

    void printHeap()
    {
        if (isEmpty())
        {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Heap elements:\n";
        for (int i = 0; i < noe; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap()
    {
        delete[] data;
    }
};

#endif
