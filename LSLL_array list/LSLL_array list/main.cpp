#include <iostream>
#include "LSLL_Array_List.h"   // yahan tumhara array-based singly linked list header include hoga
using namespace std;

int main()
{
    LSLL<int> list;   // create list object

    cout << "Inserting at tail...\n";
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    cout << "List after insertions: ";
    list.display();
    cout << endl;

    cout << "Inserting 25 after 20...\n";
    list.insertAfter(20, 25);
    list.display();
    cout << endl;

    cout << "Removing 25...\n";
    list.remove(25);
    list.display();
    cout << endl;

    cout << "Removing at tail...\n";
    list.removeAtTail();
    list.display();
    cout << endl;

    cout << "Final list: ";
    list.display();
    cout << endl;

    return 0;
}
