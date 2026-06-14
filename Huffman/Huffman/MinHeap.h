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

    bool isEmpty() 
    { 
        return noe == 0; 
    }
    bool isFull() 
    { 
        return noe == N;
    }

public:
    MinHeap()
    {
        data = nullptr; 
        N = 0; 
        noe = 0; 
    }
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
            cout << "Heap is full\n";
            return;
        }

        data[noe] = val;
        int i = noe;
        noe++;

        while (i > 0)
        {
            int par = (i - 1) / 2;

            if (data[par]->getMax()->sym->freq > data[i]->getMax()->sym->freq)
            {
                T temp = data[par]; data[par] = data[i]; data[i] = temp;
                i = par;
            }
            else
            {
                break;
            }
        }
    }

    int getNoOfElements() 
    { 
        return noe; 
    }
    ~MinHeap() 
    { 
        delete[] data; 
    }

    T remove()
    {
        if (isEmpty())
        {
            cout << "Heap is empty. Exiting.\n";
            exit(0);
        }

        T val = data[0];
        data[0] = data[--noe]; 

        int i = 0;
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left >= noe) break; 

            int smallest = left;

            
            if (right < noe && data[right]->getMax()->sym->freq < data[left]->getMax()->sym->freq)
                smallest = right;

            if (data[i]->getMax()->sym->freq > data[smallest]->getMax()->sym->freq)
            {
                T temp = data[i]; data[i] = data[smallest]; data[smallest] = temp;
                i = smallest;
            }
            else
            {
                break;
            }
        }
        return val;
    }

    
    T getMin()
    {
        if (isEmpty())
        {
            cout << "Heap is empty\n";
            exit(0);
        }
        return data[0];
    }
};
#endif
