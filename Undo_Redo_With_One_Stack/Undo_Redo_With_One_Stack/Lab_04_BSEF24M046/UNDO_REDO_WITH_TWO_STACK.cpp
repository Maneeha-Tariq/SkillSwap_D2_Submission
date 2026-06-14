//BSEF24M046
#include"UNDO_REDO_WITH_TWO_STACK.h"
#include<iostream>
using namespace std;
UndoRedoWithTwoStack::UndoRedoWithTwoStack(int c)
{
	if (c > 0)
		capacity = c;
}
void UndoRedoWithTwoStack::performAction(char op)
{
	if (capacity == undoStack.getNumberOfElements())
	{
		Stack<char> s;
		while (!undoStack.isEmpty())
			s.push(undoStack.pop());
		s.pop();
		while (!s.isEmpty())
			undoStack.push(s.pop());
	}
	undoStack.push(op);
}
char UndoRedoWithTwoStack::undo()
{
	if (undoStack.isEmpty())
		return 0;
	redoStack.push(undoStack.pop());
	return redoStack.stackTop();
}
char UndoRedoWithTwoStack::redo()
{
	if (redoStack.isEmpty())
		return 0;
	undoStack.push(redoStack.pop());
	return undoStack.stackTop();
}
int UndoRedoWithTwoStack::getSize()
{
	return capacity;
}
//void UndoRedoWithTwoStack::display()
//{
//	undoStack.display();
//	cout << "\nStack Status After Redo operations ";
//	redoStack.display();
//
//}