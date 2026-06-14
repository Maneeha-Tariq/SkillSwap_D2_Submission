//#include<iostream>
//using namespace std;
//template<typename T>
//struct Node
//{
//    int priority;
//    T value;
//    int order;
//    bool compare(Node<T>a, Node<T>b)
//    {
//        if (a.priority == b.priority)
//        {
//            return a.order > b.order;
//        }
//        else
//        {
//            return a.priority < b.priority;
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
//    void insert(T value,int prior)
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
//        T last = arr[noOfElements - 1];
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
//        return arr[noOfElements - 1];
//    }
//    bool isFull()
//    {
//        return noOfElements == size;
//    }
//    bool isEmpty()
//    {
//        return noOfElements == 0;
//    }
//};