#ifndef QUQUE_H
#define QUQUE_H
#include<iostream>
using namespace std;
template<typename T>
class Queue
{
    T* data;
    int front, rear, capacity, noOfElements;
    int getLoc(int rotLac) const
    {
        int loc = rotLac % capacity;
        return  loc;
    }
    void resize(int newCap)
    {
        T* temp = new T[newCap];
        for (int i = front, j = 0; i < front + noOfElements; j++, i++)
        {
            temp[j] = data[getLoc(i)];
        }
        delete[] data;
        data = temp;
        front = 0;
        rear = noOfElements;
        capacity = newCap;
    }
public:
    Queue()
    {
        data = nullptr;
        capacity = 0;
        noOfElements = 0;
        front = 0;
        rear = 0;
    }
    ~Queue()
    {
        if (data)
            delete[] data;
        capacity = noOfElements = front = rear = 0;
    }
    Queue(const Queue<T>& ref)
    {
        *this = ref;
    }
    Queue<T>& operator=(const Queue<T>& ref)
    {
        if (this == &ref)
            return *this;
        delete[] data;
        capacity = ref.capacity;
        noOfElements = ref.noOfElements;
        front = 0;
        rear = noOfElements;
        data = new T[capacity];
        for (int i = 0; i < noOfElements; i++)
            data[i] = ref.data[ref.getLoc(ref.front + i)];
        return *this;
    }
    void enQueue(T x)
    {
        if (isFull())
            resize(capacity == 0 ? 1 : capacity * 2);
        data[getLoc(rear)] = x;
        noOfElements++;
        rear++;
    }

    T deQueue()
    {
        if (isEmpty())
        {
            cout << "Error at removeElementFromFront()";
            exit(0);
        }
        T el = data[getLoc(front)];
        front++;
        noOfElements--;
        if (noOfElements > 0 && noOfElements == capacity / 4)
            resize(capacity / 2);
        return el;
    }

    T getElementAtFront() const
    {
        if (isEmpty())
            return  -1;
        //int loc = getLoc(start);
        return  data[getLoc(front)];
    }
    bool isEmpty() const
    {
        return  noOfElements == 0;
    }
    bool isFull() const
    {
        return  noOfElements == capacity;
    }

    int getNoOfElements() const
    {
        return noOfElements;
    }
    int getCapacity() const
    {
        return capacity;
    }
};

#endif // !QUQUE_J
