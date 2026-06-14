#include "QuadraticProbing.h"
#include <iostream>
using namespace std;

int main() {
    QuadraticProbing hp;

    cout << "=== Test Case 1: Basic Insert and Search ===\n";
    hp.insert(10);
    hp.insert(47);
    hp.insert(84);

    cout << "Search 10: " << (hp.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search 47: " << (hp.search(47) ? "Found" : "Not Found") << endl;
    cout << "Search 84: " << (hp.search(84) ? "Found" : "Not Found") << endl;
    cout << "Search 21: " << (hp.search(21) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 2: Deletion ===\n";
    hp.remove(47);
    cout << "Search 47 after deletion: " << (hp.search(47) ? "Found" : "Not Found") << endl;
    hp.insert(47);
    cout << "Search 47 after reinsertion: " << (hp.search(47) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 3: Load Factor and Rehash ===\n";
    QuadraticProbing smallTable; 
    smallTable.insert(3);
    smallTable.insert(10);
    smallTable.insert(17);
    cout << "Load factor before inserting 24: " << smallTable.loadFactor() << endl;
    smallTable.insert(24); 
    cout << "Load factor after inserting 24: " << smallTable.loadFactor() << endl;

    cout << "\n=== Test Case 4: Duplicate Insert ===\n";
    hp.insert(10); 
    cout << "Number of elements (should not increase due to duplicate): " << hp.getNoOfElements() << endl;

    cout << "\n=== Test Case 5: Search Non-existing Element ===\n";
    cout << "Search 99: " << (hp.search(99) ? "Found" : "Not Found") << endl;
    cout << "Search 0: " << (hp.search(0) ? "Found" : "Not Found") << endl;

    cout << "\n=== Test Case 6: DELETED Slot Reuse ===\n";
    hp.remove(10);
    hp.insert(24);
    cout << "Search 24 after inserting into DELETED slot: " << (hp.search(24) ? "Found" : "Not Found") << endl;

    return 0;
}
