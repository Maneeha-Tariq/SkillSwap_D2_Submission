#include <iostream>
#include "LinearProbing.h"
using namespace std;

int main() {
    LinearProbing lp;

    // Test 1: Insert and search
    lp.insert(10);
    lp.insert(20);
    lp.insert(30);

    if (lp.search(10)) cout << "Test 1a Passed\n";
    else cout << "Test 1a Failed\n";

    if (lp.search(20)) cout << "Test 1b Passed\n";
    else cout << "Test 1b Failed\n";

    if (!lp.search(40)) cout << "Test 1c Passed\n";
    else cout << "Test 1c Failed\n";

    // Test 2: Remove
    lp.remove(20);
    if (!lp.search(20)) cout << "Test 2 Passed\n";
    else cout << "Test 2 Failed\n";

    // Test 3: Insert after remove (DELETED slot reuse)
    lp.insert(20);
    if (lp.search(20)) cout << "Test 3 Passed\n";
    else cout << "Test 3 Failed\n";

    // Test 4: Check load factor and rehash
    for (int i = 0; i < 30; i++) {
        lp.insert(100 + i);
    }
    cout << "Test 4: Load Factor = " << lp.loadFactor() << endl;
    cout << "Number of elements = " << lp.getNoOfElements() << endl;

    return 0;
}
