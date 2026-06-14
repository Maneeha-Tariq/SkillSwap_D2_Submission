//#include "newAVL.h"

//int main() {
//   /* newAVL<int> tree;*/
//
//    // Insert nodes (complex rotation scenario)
//    //tree.insert(30);
//    //tree.insert(20);
//    //tree.insert(10); // should trigger LL rotation
//
//    //tree.preOrderPrint(); // expect 20 10 30
//
//    //tree.insert(25);
//    //tree.insert(40);
//    //tree.insert(50); // should trigger RR rotation
//
//    //tree.preOrderPrint(); // check tree after rotations
//
//    //tree.insert(22);
//    //tree.insert(27); // may trigger LR rotation
//
//    //tree.preOrderPrint(); // check tree after LR rotation
//
//    ////// Deletion test
//    ////tree.remove(20); // remove root or internal node
//    ////tree.preOrderPrint(); // check tree after deletion
//
//    ////tree.remove(10);
//    ////tree.remove(50);
//    ////tree.preOrderPrint(); // final structure
//
//    //tree.insert(50);
//    //tree.insert(10);
//    //tree.insert(70); // triggers LL rotation
//    //tree.insert(5); // triggers LL rotation again
//    //tree.insert(25); // triggers LL rotation again
//    //tree.insert(60);
//    //tree.insert(80);
//    //tree.insert(2);
//    //tree.insert(7);
//    //tree.insert(1);
//   
//
//    //newAVL<int> t;
//
//    //t.insert(60);
//    //t.insert(20);
//    //t.insert(10);   // LR rotation should occur here
//    //t.insert(30);
//    //t.insert(25);
//    //t.preOrderPrint();
//
//
//    return 0;
//}

#include <iostream>
#include "newAVL.h"
using namespace std;

int main() {
    newAVL<int> tree;

    // ===== Build the tree =====
    int nodes[] = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85 };
    for (int val : nodes) tree.insert(val);

    cout << "Initial tree (preOrder): ";
    tree.preOrderPrint();

    // ===== Remove 60 =====
    cout << "Removing node 60...\n";
    tree.remove(60);

    cout << "Tree after deleting 60 (preOrder): ";
    tree.preOrderPrint();

    // ===== Optional: Remove more nodes to see rotations =====
     tree.remove(30);
     tree.preOrderPrint();
    // tree.remove(70);

    return 0;
}





