//#include<iostream>
//using namespace std;
//
//template<typename T>
//class PriorityQueue
//{
//private:
//    T* arr;
//    int size;
//    int noOfElements;
//
//public:
//    PriorityQueue(int s)
//    {
//        size = s;
//        arr = new T[size];
//        noOfElements = 0;
//    }
//
//    void insert(T value)
//    {
//        if (isFull())
//        {
//            cout << "Array is Full\n";
//            return;
//        }
//        int i = noOfElements - 1;
//        while (i >= 0 && arr[i] < value)
//        {
//            arr[i + 1] = arr[i];
//            i--;
//        }
//        arr[i + 1] = value;
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