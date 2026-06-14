#include "LDLL_Array_List.h"

int main()
{
    LDLL<int> list(15); // 15 elements capacity

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertBefore(10, 5);
    list.insertAfter(20, 25);
    list.display();   // Output: 5 10 20 25 30

    list.removeBefore(20);
    list.display();   // Output: 10 20 25 30

    list.removeAfter(20);
    list.display();   // Output: 10 20 30

    list.removeAtHead();
    list.display();   // Output: 20 30

    list.removeAtTail();
    list.display();   // Output: 20
}
