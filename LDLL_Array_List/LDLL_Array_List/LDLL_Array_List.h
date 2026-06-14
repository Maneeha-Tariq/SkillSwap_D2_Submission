#ifndef LDLL_ARRAY_LIST_H
#define LDLL_ARRAY_LIST_H
#include <iostream>
#include "DNode1.h"   
using namespace std;

template<typename T>
class LDLL
{
    int head;
    int avail;
    int size;              
    DNode1<T>* data;       

    int getNewNode()
    {
        if (avail != -1)
        {
            int x = avail;
            avail = data[avail].next;
            return x;
        }
        cout << "Error: List is full!\n";
        exit(0);
    }

    void getItBack(int node)
    {
        data[node].next = avail;
        avail = node;
    }

public:
   
    LDLL(int s = 10)
    {
        size = s;
        data = new DNode1<T>[size];

        for (int i = 0; i < size - 1; i++)
        {
            data[i].next = i + 1;
            data[i].prev = -1;
        }
        data[size - 1].next = -1;
        data[size - 1].prev = -1;

        head = -1;
        avail = 0;
    }

    
    ~LDLL()
    {
        delete[] data;
        data = nullptr;
        head = -1;
        avail = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return head == -1;
    }

   
    void insertAtHead(T val)
    {
        int x = getNewNode();
        data[x].info = val;
        data[x].prev = -1;
        data[x].next = head;

        if (head != -1)
            data[head].prev = x;

        head = x;
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
        data[x].info = val;
        data[x].next = -1;
        data[x].prev = p;
        data[p].next = x;
    }

   
    void insertBefore(T key, T val)
    {
        if (isEmpty())
            return;

        int p = head;
        while (p != -1 && data[p].info != key)
            p = data[p].next;

        if (p == -1)
            return;

        if (data[p].prev == -1)
        {
            insertAtHead(val);
            return;
        }

        int x = getNewNode();
        data[x].info = val;
        data[x].next = p;
        data[x].prev = data[p].prev;
        data[data[p].prev].next = x;
        data[p].prev = x;
    }

    
    void insertAfter(T key, T val)
    {
        if (isEmpty())
            return;

        int p = head;
        while (p != -1 && data[p].info != key)
            p = data[p].next;

        if (p == -1)
            return;

        int x = getNewNode();
        data[x].info = val;
        data[x].prev = p;
        data[x].next = data[p].next;

        if (data[p].next != -1)
            data[data[p].next].prev = x;

        data[p].next = x;
    }

    
    void removeAtHead()
    {
        if (isEmpty())
            return;

        int x = head;
        head = data[head].next;
        if (head != -1)
            data[head].prev = -1;
        getItBack(x);
    }

   
    void removeAtTail()
    {
        if (isEmpty())
            return;

        if (data[head].next == -1)
        {
            removeAtHead();
            return;
        }

        int p = head;
        while (data[data[p].next].next != -1)
            p = data[p].next;

        int q = data[p].next;
        data[p].next = -1;
        getItBack(q);
    }

    
    void removeBefore(T key)
    {
        if (isEmpty() || data[head].info == key)
            return;

        int p = head;
        while (p != -1 && data[p].info != key)
            p = data[p].next;

        if (p == -1 || data[p].prev == -1)
            return;

        int q = data[p].prev;

        if (data[q].prev != -1)
            data[data[q].prev].next = p;
        else
            head = p;

        data[p].prev = data[q].prev;
        getItBack(q);
    }

   
    void removeAfter(T key)
    {
        if (isEmpty())
            return;

        int p = head;
        while (p != -1 && data[p].info != key)
            p = data[p].next;

        if (p == -1 || data[p].next == -1)
            return;

        int q = data[p].next;
        data[p].next = data[q].next;
        if (data[q].next != -1)
            data[data[q].next].prev = p;
        getItBack(q);
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
        while (p != -1 && data[p].info != key)
            p = data[p].next;

        if (p == -1)
            return;

        if (data[p].next != -1)
            data[data[p].next].prev = data[p].prev;
        if (data[p].prev != -1)
            data[data[p].prev].next = data[p].next;

        if (p == head)
            head = data[p].next;

        getItBack(p);
    }

   
    void display()
    {
        int p = head;
        while (p != -1)
        {
            cout << data[p].info << " ";
            p = data[p].next;
        }
        cout << endl;
    }
};
#endif
