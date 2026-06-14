////bsef24m046
//#include "UNDO_REDO_WITH_TWO_STACK.h"
//#include<iostream>
//using namespace std;
//int main()
//{
//    //UndoRedoWithTwoStack u(3);
//
//    //u.performAction('A');
//    //u.performAction('B');
//    //u.performAction('C');
//    //u.undo();
//    //u.redo();
//    //u.performAction('D');
//    //u.undo();  
//    //u.undo();  
//    //u.redo(); 
//    //UndoRedoWithTwoStack x(2);
//    //x.undo();    // no action yet
//    //x.redo();    // redo bhi empty
//
//   /* UndoRedoWithTwoStack t(3);
//    t.performAction('X');
//    t.performAction('Y');
//    char undone = t.undo();
//    char redone = t.redo();
//    cout << "Undone: " << undone << ", Redone: " << redone << endl;*/
//   
//    return 0;
//}

#include<iostream>
#include"UNDO_REDO_WITH_TWO_STACK.h"
using namespace std;

int main()
{
    UndoRedoWithTwoStack editor(5);   // Capacity 5

    editor.performAction("A");
    editor.performAction("B");
    editor.performAction("C");
    editor.performAction("D");

    cout << "Undo: " << editor.undo() << endl;   // should undo D
    cout << "Undo: " << editor.undo() << endl;   // should undo C

    cout << "Redo: " << editor.redo() << endl;   // should redo C

    editor.performAction("E");  // redo stack should clear

    cout << "Redo after new action: " << editor.redo() << endl;  // should give empty

    cout << "Undo: " << editor.undo() << endl;   // undo E
    cout << "Undo: " << editor.undo() << endl;   // undo C
    cout << "Undo: " << editor.undo() << endl;   // undo B
    cout << "Undo: " << editor.undo() << endl;   // undo A
    cout << "Undo: " << editor.undo() << endl;   // nothing left → empty

    return 0;
}

