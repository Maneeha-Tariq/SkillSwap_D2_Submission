#include <iostream>
#include "UNDO_REDO_WITH_ONE_STACK.h"
using namespace std;

int main()
{
    UndoRedoWithOneStack editor(5);  // stack capacity = 5

    cout << "Performing actions: A, B, C" << endl;
    editor.performAction("A");
    editor.performAction("B");
    editor.performAction("C");

    cout << "\nUndo 1 → should remove C" << endl;
    String u1 = editor.undo();
    cout << "Undo returned: " << u1 << endl;

    cout << "Undo 2 → should remove B" << endl;
    String u2 = editor.undo();
    cout << "Undo returned: " << u2 << endl;

    cout << "\nRedo 1 → should redo B" << endl;
    String r1 = editor.redo();
    cout << "Redo returned: " << r1 << endl;

    cout << "Redo 2 → should redo C" << endl;
    String r2 = editor.redo();
    cout << "Redo returned: " << r2 << endl;

    cout << "\nPerform new action: D (after undo)" << endl;
    editor.performAction("D");

    cout << "Redo after new action → should return empty (redo history cleared)" << endl;
    String r3 = editor.redo();
    cout << "Redo returned: " << r3 << endl;

    return 0;
}
