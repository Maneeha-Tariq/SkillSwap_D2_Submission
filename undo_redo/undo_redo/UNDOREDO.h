#ifndef UNDO_REDO_H
#define UNDO_REDO_H
#include"Stack.h"
class UndoRedo
{
	int capacity;
	Stack<int> undoStack;
	Stack<int> redoStack;
public:
	UndoRedo(int c = 10);
	void memoriseOperation(int op);
	int undo();
	int  redo();
};
#endif
