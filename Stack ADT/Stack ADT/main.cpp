#include <iostream>
#include "Stack.h"
#include "String.h"
using namespace std;
template<typename T>
void reverse(Stack<T>& s)
{
    Stack<T> t;
    while(!s.isEmpty())
    {
        t.push(s.pop());
    }
    Stack<T> r;
    while(!t.isEmpty())
    {
        r.push(t.pop());
    }
    while (!r.isEmpty())
    {
        s.push(r.pop());
    }
}
template<typename T>
void reverseTwo(Stack<T>& s)
{
    Stack<T> t;
    int n = s.getNumberOfElements();

    for (int i = 0; i < n - 1; i++)
    {

        T temp = s.pop();


        for (int j = 0; j < n - i - 1; j++)
        {
            t.push(s.pop());
        }


        s.push(temp);


        while (!t.isEmpty())
        {
            s.push(t.pop());
        }
    }
}
template<typename T>
void ascending(Stack<T>& s)
{
    Stack<T> t;
    int noe = s.getNumberOfElements();

    for (int i = 0; i < noe; i++)
    {
        T max = s.pop();

        for (int k = 1; k < noe - i; k++)
        {
            T curr = s.pop();

            if (curr < max)
            {
                t.push(max);
                max = curr;
            }
            else
            {
                t.push(curr);
            }
        }

        s.push(max);

        while (!t.isEmpty())
        {

            s.push(t.pop());
        }
    }
}
template<typename T>
Stack<T> transfer(Stack<T>& s, Stack<T>& t)
{
    Stack<T> rep;
    while (!s.isEmpty())
    {
        rep.push(s.pop());
    }
    while (!rep.isEmpty())
    {
        t.push(rep.pop());
    }
    return t;
}


//int main()
//{
//    Stack<int> s;
//
//    s.push(80);
//    s.push(20);
//    s.push(30);
//
//    cout << "Stack elements: ";
//    s.display();
//    cout << endl;
//
//
//
//    return 0;
//}
//
