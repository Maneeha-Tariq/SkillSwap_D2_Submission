#include <iostream>
#include "CDLL_ITER.h"
using namespace std;

int main()
{
    CDLL<int> list;
    list.insertAtHead(9);
    list.insertAtHead(8);
    list.insertAtHead(7);
    list.insertAtHead(6);


   
    /*if (list.begin() != CDLL<int>::Iterator(nullptr))
    {
        do {
            cout << *it << " ";
            ++it; 
        } while (it != list.begin()); 
    }
    
    cout << "\nReverse (Iterator): ";
    --it; 
    CDLL<int>::Iterator start = it; 

    do {
        cout << *it << " ";
        --it; 
    } while (it != start); 
    */

    for (auto x : list)
    {
        cout << x << " ";
    }
}

//void displayBackward() {
//    if (!head) return;
//    Iterator it = begin();
//    --it;  // move to tail
//    for (;;) {
//        cout << *it << " ";
//        if (it.curr->prev == head->prev) break; // one full cycle
//        --it;
//        if (it.curr == head->prev) break;
//    }
//    cout << endl;
//}



