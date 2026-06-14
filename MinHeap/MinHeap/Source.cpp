#include <iostream>
#include "MinHeap.h"  // your header file
using namespace std;

int main()
{
    // Create a MinHeap of size 10
    MinHeap<int> heap(10);

    cout << "=== Test Case 1: Insert values ===\n";
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(5); // duplicate value
    heap.printHeap();

    //cout << "\n=== Test Case 2: Get Min ===\n";
    //cout << "Minimum element: " << heap.getMin() << "\n";

    cout << "\n=== Test Case 3: Remove Min ===\n";
    int removed = heap.remove();
    cout << "Removed: " << removed << "\n";
    heap.printHeap();

    //cout << "\n=== Test Case 4: Insert more duplicates ===\n";
    //heap.insert(3);
    //heap.insert(1);
    //heap.insert(5);
    //heap.printHeap();

    //cout << "\n=== Test Case 5: Remove all elements ===\n";
    //while (!heap.isEmpty())
    //{
    //    cout << "Removed: " << heap.remove() << "\n";
    //    heap.printHeap();
    //}

    //cout << "\n=== Test Case 6: Remove from empty heap ===\n";
    //// Should print error and exit
    //// heap.remove();

    return 0;
}
