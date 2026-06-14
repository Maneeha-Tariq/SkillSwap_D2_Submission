#include "UNDOREDO.h"
#include<iostream>
using namespace std;
int main()
{
    UndoRedo ur(3);  // capacity = 3

    cout << "Adding operations...\n";
    ur.memoriseOperation(10);
    ur.memoriseOperation(20);
    ur.memoriseOperation(30);

    cout << "Undoing last operation: " << ur.undo() << endl; // should be 30
    cout << "Undoing last operation: " << ur.undo() << endl; // should be 20

    cout << "Redoing operation: " << ur.redo() << endl; // should be 20
    cout << "Redoing operation: " << ur.redo() << endl; // should be 30

    cout << "\nAdding more operations...\n";
    ur.memoriseOperation(40);
    ur.memoriseOperation(50);
    ur.memoriseOperation(60);  // capacity full, 10 should be removed

    cout << "Undoing last operation: " << ur.undo() << endl; // should be 60
    cout << "Redoing operation: " << ur.redo() << endl; // should be 60

    return 0;
}