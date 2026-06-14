#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node* next;

    Node(T value)
    {
        data = value;
        next = NULL;
    }
};

template<typename T>
class Queue
{
    Node<T>* front;
    Node<T>* rear;

public:

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL&& rear == NULL);
    }

    void enQueue(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        // Queue empty
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into Queue\n";
    }

    T deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return T();
        }

        Node<T>* temp = front;
        T element = temp->data;

        // Only one node exists
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }

        delete temp;

        cout << element << " removed from Queue\n";

        return element;
    }

    T start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return T();
        }

        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
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
    Queue<int> q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    q.display();

    q.deQueue();

    q.display();

    cout << "Front Element: " << q.start() << endl;

    return 0;
}

//void insertAtBottom(stack<int>& st, int x)
//{
//    if (st.empty())
//    {
//        st.push(x);
//        return;
//    }
//
//    int top = st.top();
//    st.pop();
//
//    insertAtBottom(st, x);
//
//    st.push(top);
//}
//
//void reverseStack(stack<int>& st)
//{
//    if (st.empty()) return;
//
//    int top = st.top();
//    st.pop();
//
//    reverseStack(st);
//
//    insertAtBottom(st, top);
//}

//void reverseQueue(queue<int>& q)
//{
//    if (q.empty()) return;
//
//    int front = q.front();
//    q.pop();
//
//    reverseQueue(q);
//
//    q.push(front);
//}