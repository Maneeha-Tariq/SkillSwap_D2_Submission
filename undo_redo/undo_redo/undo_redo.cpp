#include"UndoRedo.h"
#include<iostream>
using namespace std;
UndoRedo::UndoRedo(int c )
{
	if (c > 0)
		capacity = c;
}
void UndoRedo::memoriseOperation(int op)
{
	if (capacity == undoStack.getNumberOfElements())
	{
		Stack<int> s;
		while (!undoStack.isEmpty())
			s.push(undoStack.pop());
		s.pop();
		while (!s.isEmpty())
			undoStack.push(s.pop());
	}
	undoStack.push(op);
}
int UndoRedo::undo()
{
	if (undoStack.isEmpty())
		return 0;
	redoStack.push(undoStack.pop());
	return redoStack.stackTop();
}
int  UndoRedo::redo()
{
	if (redoStack.isEmpty())
		return 0;
	undoStack.push(redoStack.pop());
	return undoStack.stackTop();
}