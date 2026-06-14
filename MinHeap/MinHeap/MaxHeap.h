#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <iostream>
using namespace std;

template<typename T>
class MaxHeap
{
    T* data;
    int N;
    int noe;

   
    bool isFull()
    {
        return noe == N;
    }
public:
    MaxHeap()
    {
        data = nullptr;
        N = 1;
        noe = 0;
    }
    MaxHeap(int s)
    {
        N = s;
        noe = 0;
        data = new T[N];
    }

    void insert(T val)
    {
        if (isFull())
        {
            cout << "Heap is full";
            return;
        }

        data[noe] = val;
        int i = noe;
        noe++;

        while (i > 0)
        {
            int par = (i - 1) / 2;
            if (data[par] < data[i])
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

    T getMax()
    {
        if (isEmpty())
        {
            cout << "Heap is empty";
            exit(0);
        }
        return data[0];
    }

    T remove()
    {
        if (isEmpty())
        {
            cout << "Heap is empty";
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
            {
                break;
            }

            int largest = left;

            if (right < noe && data[right] > data[left])
            {
                largest = right;
            }

            if (data[i] < data[largest])
            {
                T temp = data[i];
                data[i] = data[largest];
                data[largest] = temp;
                i = largest;
            }
            else
            {
                break;
            }
                
        }
        return val;
    }
    bool isEmpty()
    {
        return noe == 0;
    }

   

    int getNoOfElements()
    {
        return noe;
    }
    ~MaxHeap()
    {
        delete[] data;
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
};
#endif



