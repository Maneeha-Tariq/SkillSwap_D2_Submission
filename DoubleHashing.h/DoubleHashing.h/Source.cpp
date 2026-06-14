#include "DoubleHashing.h"  // your DoubleHashing class header
#include <iostream>
using namespace std;

int main() {
    DoubleHashing dh;

    cout << "=== Test Case 1: Basic Insert and Search ===\n";
    dh.insert(4371);
    dh.insert(1323);
    dh.insert(6173);
    dh.insert(4199);
    dh.insert(4344);
    dh.insert(9679);
    dh.insert(1989);
    dh.insert(9560);
    dh.insert(3402);
    dh.insert(8111);
  

   /* cout << "Search 10: " << (dh.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (dh.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 30: " << (dh.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (dh.search(99) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 2: Deletion ===\n";
    dh.remove(25);
    cout << "Search 25 after deletion: " << (dh.search(25) ? "Found" : "Not Found") << endl;
    dh.insert(25);
    cout << "Search 25 after reinsertion: " << (dh.search(25) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 3: Load Factor and Rehash ===\n";
    DoubleHashing smallTable;
    smallTable.insert(3);
    smallTable.insert(10);
    smallTable.insert(17);
    cout << "Load factor before inserting 24: " << smallTable.loadFactor() << endl;
    smallTable.insert(24);
    cout << "Load factor after inserting 24: " << smallTable.loadFactor() << endl;

    cout << "\n=== Test Case 4: Duplicate Insert ===\n";
    dh.insert(10);
    cout << "Number of elements (should not increase due to duplicate): " << dh.getNoOfElements() << endl;

    cout << "\n=== Test Case 5: Search Non-existing Element ===\n";
    cout << "Search 99: " << (dh.search(99) ? "Found" : "Not Found") << endl;
    cout << "Search 0: " << (dh.search(0) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 6: DELETED Slot Reuse ===\n";
    dh.remove(10);
    dh.insert(24);
    cout << "Search 24 after inserting into DELETED slot: " << (dh.search(24) ? "Found" : "Not Found") << endl;*/

    return 0;
}
