#ifndef CDLL_ARRAY_LIST_H
#define CDLL_ARRAY_LIST_H
#include <iostream>
using namespace std;
#include "DNode1.h"
template<typename T>
class CDLL
{
    DNode1<T>* data;
    int head;     
    int avail;     
    int size;    

    bool isEmpty()
    {
        return head == -1;
    }

    bool isFull()
    {
        return avail == -1;
    }

    int getNode()
    {
        if (isFull())
        {
            cout << "List is full!" << endl;
            return -1;
        }
        int p = avail;
        avail = data[avail].next;
        return p;
    }

    void freeNode(int i)
    {
        data[i].next = avail;
        avail = i;
    }

public:
    CDLL(int s = 10)
    {
        size = s;
        data = new DNode1<T>[size];
        for (int i = 0; i < size - 1; i++)
        {
            data[i].next = i + 1;
        }
        data[size - 1].next = -1;
        head = -1;
        avail = 0;
    }

    void insertAtHead(T val)
    {
        int p = getNode();
        if (p == -1) return;

        data[p].info = val;
        if (head == -1)
        {
            data[p].next = p;
            data[p].prev = p;
            head = p;
        }
        else
        {
            int tail = data[head].prev;
            data[p].next = head;
            data[p].prev = tail;
            data[tail].next = p;
            data[head].prev = p;
            head = p;
        }
    }

    void insertAtTail(T val)
    {
        if (isEmpty())
        {
            insertAtHead(val);
            return;
        }
        int tail = data[head].prev;
        int p = getNode();
        if (p == -1) return;

        data[p].info = val;
        data[p].next = head;
        data[p].prev = tail;
        data[tail].next = p;
        data[head].prev = p;
    }

    void insertAfter(T key, T val)
    {
        if (isEmpty()) return;

        int p = head;
        do
        {
            if (data[p].info == key)
            {
                int x = getNode();
                if (x == -1) return;

                int nxt = data[p].next;
                data[x].info = val;
                data[x].next = nxt;
                data[x].prev = p;
                data[p].next = x;
                data[nxt].prev = x;
                return;
            }
            p = data[p].next;
        } while (p != head);
    }

    void insertBefore(T key, T val)
    {
        if (isEmpty()) return;

        int p = head;
        do
        {
            if (data[p].info == key)
            {
                int x = getNode();
                if (x == -1) return;

                int prev = data[p].prev;
                data[x].info = val;
                data[x].next = p;
                data[x].prev = prev;
                data[prev].next = x;
                data[p].prev = x;

                if (p == head)
                    head = x;
                return;
            }
            p = data[p].next;
        } while (p != head);
    }

    void removeAtHead()
    {
        if (isEmpty()) return;

        if (data[head].next == head)
        {
            freeNode(head);
            head = -1;
            return;
        }

        int oldHead = head;
        int tail = data[head].prev;
        head = data[head].next;
        data[head].prev = tail;
        data[tail].next = head;

        freeNode(oldHead);
    }

    void removeAtTail()
    {
        if (isEmpty()) return;

        if (data[head].next == head)
        {
            removeAtHead();
            return;
        }

        int tail = data[head].prev;
        int newTail = data[tail].prev;

        data[newTail].next = head;
        data[head].prev = newTail;

        freeNode(tail);
    }

    void remove(T key)
    {
        if (isEmpty()) return;

        int p = head;
        do
        {
            if (data[p].info == key)
            {
                if (data[p].next == p) // only one node
                {
                    freeNode(p);
                    head = -1;
                    return;
                }

                int prev = data[p].prev;
                int next = data[p].next;
                data[prev].next = next;
                data[next].prev = prev;

                if (p == head)
                    head = next;

                freeNode(p);
                return;
            }
            p = data[p].next;
        } while (p != head);
    }

    void removeBefore(T key)
    {
        if (isEmpty()) return;

        int p = head;
        do
        {
            if (data[p].info == key)
            {
                int toDelete = data[p].prev;
                if (toDelete == p)
                {
                    return;
                }
                int before = data[toDelete].prev;
                data[before].next = p;
                data[p].prev = before;
                if (toDelete == head)
                    head = p;
                freeNode(toDelete);
                return;
            }
            p = data[p].next;
        } while (p != head);
    }

    void removeAfter(T key)
    {
        if (isEmpty()) return;

        int p = head;
        do
        {
            if (data[p].info == key)
            {
                int toDelete = data[p].next;
                if (toDelete == p) return;

                int after = data[toDelete].next;
                data[p].next = after;
                data[after].prev = p;
                if (toDelete == head)
                    head = after;
                freeNode(toDelete);
                return;
            }
            p = data[p].next;
        } while (p != head);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "(empty)";
            return;
        }

        int p = head;
        do
        {
            cout << data[p].info << " ";
            p = data[p].next;
        } while (p != head);
        cout << endl;
    }

    ~CDLL()
    {
        delete[] data;
    }
};

#endif
