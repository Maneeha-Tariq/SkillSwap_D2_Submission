#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

template<typename T>
class Deque
{
    Node<T>* front;
    Node<T>* rear;

public:

    Deque()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert at front
    void push_front(T x)
    {
        Node<T>* newNode = new Node<T>(x);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << "Pushed " << x << " into front of deque\n";
    }

    // Insert at rear
    void push_back(T x)
    {
        Node<T>* newNode = new Node<T>(x);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << "Pushed " << x << " into back of deque\n";
    }

    // Delete from front
    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        Node<T>* temp = front;

        cout << "Popped " << front->data
            << " from front of deque\n";

        // Only one node
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from rear
    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        Node<T>* temp = rear;

        cout << "Popped " << rear->data
            << " from back of deque\n";

        // Only one node
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    T start()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return T();
        }

        return front->data;
    }

    T back()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return T();
        }

        return rear->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        Node<T>* temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Deque<int> d;

    d.push_front(7);
    d.push_front(8);
    d.push_back(2);

    d.pop_back();

    d.push_back(9);
    d.push_front(3);

    d.display();

    cout << "Front: " << d.start() << endl;
    cout << "Back : " << d.back() << endl;

    return 0;
}