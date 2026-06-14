#include "LDLL_ITER.h"
#include <iostream>
using namespace std;

int main()
{
    //LDLL<int> list;
    //list.insertAtTail(10);
    //list.insertAtTail(20);
    //list.insertAtTail(30);
    //list.insertAtTail(40);

    //cout << "Forward: ";
    //for (LDLL<int>::Iterator it = list.begin(); it != list.end(); ++it)
    //    cout << *it << " ";

    //cout << "\nReverse: ";
    //// move iterator to last node manually
    //LDLL<int>::Iterator it = list.begin();
    //LDLL<int>::Iterator temp = it;
    //while (temp != list.end())
    //    it = temp, temp++;

    //// now 'it' is pointing to last node (40)
    //for (;; --it)
    //{
    //    cout << *it << " ";
    //    if (it == list.begin())
    //        break;
    //}

    LDLL<int> mainList;
    mainList.insertAtTail(1);
    mainList.insertAtTail(2);
    mainList.insertAtTail(3);
    mainList.insertAtTail(4);
    mainList.insertAtTail(5);


    LDLL<int> List2;
    List2.insertAtTail(3);
    List2.insertAtTail(1);
    List2.insertAtTail(2);
    List2.insertAtTail(8);
    List2.insertAtTail(6);
    LDLL<int>::Iterator it = mainList.begin();
    LDLL<int>::Iterator i = List2.begin();
    int sum = 0;
    while (it != mainList.end() && i != List2.end())
    {
        sum = *it + *i;
        cout << sum << " ";
        ++it, ++i;
    }
}
