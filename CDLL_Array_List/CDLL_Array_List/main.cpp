#include <iostream>
#include "CDLL_Array_List.h"
using namespace std;

int main()
{
    CDLL<int> list(10);

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertBefore(10, 5);
    list.insertAfter(20, 25);
    cout << "List after insertions: ";
    list.display();  

    list.removeBefore(20);
    list.display();  

    list.removeAfter(20);
    list.display();  

    list.removeAtHead();
    list.display();  

    list.removeAtTail();
    list.display();  

    return 0;
}
