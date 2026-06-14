//#include<iostream>
//using namespace std;
//template<typename T>
//struct Node
//{
//    int priority;
//    T value;
//    int order;
//    bool compare(Node<T> a, Node<T> b)
//    {
//        if (a.priority == b.priority)
//        {
//            return a.order < b.order;
//        }
//        else
//        {
//            return a.priority > b.priority;
//        }
//    }
//};
//
//template<typename T>
//class PriorityQueue
//{
//private:
//    Node<T>* arr;
//    int size;
//    int noOfElements;
//    int counter;
//
//public:
//    PriorityQueue(int s)
//    {
//        size = s;
//        arr = new Node<T>[size];
//        noOfElements = 0;
//        counter = 0;
//    }
//
//    void insert(T val,int prior)
//    {
//        if (isFull())
//        {
//            cout << "Array is Full\n";
//            return;
//        }
//        Node<T> newNode;
//        newNode.value = val;
//        newNode.priority = prior;
//        newNode.order = counter++;
//
//        int i = noOfElements - 1;
//        while (i >= 0 && arr[i].compare(arr[i], newNode))
//        {
//            arr[i + 1] = arr[i];
//            i--;
//        }
//        arr[i + 1] = newNode;
//        noOfElements++;
//    }
//
//    T remove()
//    {
//        if (isEmpty())
//        {
//            cout << "Queue is Empty\n";
//            return T();
//        }
//        T last = arr[noOfElements - 1].value;
//        noOfElements--;
//        return last;
//    }
//
//    T peek()
//    {
//        if (isEmpty())
//        {
//            cout << "Queue is Empty\n";
//            return T();
//        }
//        return arr[noOfElements - 1].value;
//    }
//    bool isFull()
//    {
//        return noOfElements == size;
//    }
//    bool isEmpty()
//    {
//        return noOfElements == 0;
//    }
//    void display()
//    {
//        int i = noOfElements - 1;
//        while (i >= 0)
//        {
//            cout << "( "<< arr[i].value << ","<< arr[i].priority<< " ) ";
//            i--;
//        }
//    }
//};
//int main()
//{
//    PriorityQueue<string> pq(10);
//
//    // Test Case 1 (Normal)
//    pq.insert("A", 2);
//    pq.insert("B", 3);
//    pq.insert("C", 1);
//
//    cout << "Queue: ";
//    pq.display();
//
//    cout << "Remove: " << pq.remove() << endl; // B
//
//    // Test Case 2 (FIFO for equal priority)
//    pq.insert("X", 2);
//    pq.insert("Y", 2);
//    pq.insert("Z", 2);
//
//    cout << "\nQueue after equal priorities: ";
//    pq.display();
//
//    cout << "Remove: " << pq.remove() << endl; // X
//    cout << "Remove: " << pq.remove() << endl; // Y
//    cout << "Remove: " << pq.remove() << endl; // Z
//
//    // Test Case 3 (Peek)
//    pq.insert("M", 5);
//    pq.insert("N", 3);
//
//    cout << "\nPeek: " << pq.peek() << endl; // M
//
//    return 0;
//}