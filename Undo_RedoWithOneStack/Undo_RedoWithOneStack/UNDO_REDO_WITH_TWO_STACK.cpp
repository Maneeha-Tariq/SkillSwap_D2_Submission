//BSEF24M046
#include"UNDO_REDO_WITH_TWO_STACK.h"
#include<iostream>
using namespace std;
UndoRedoWithTwoStack::UndoRedoWithTwoStack(int c)
{
	if (c > 0)
		capacity = c;
}
void UndoRedoWithTwoStack::performAction(String op)
{
	if (capacity == undoStack.getNumberOfElements())
	{
		int i = 0;
		while (!undoStack.isEmpty())
		{
			s[i] = undoStack.pop();
			i++;
		}
		int j = i-2;
		while (j>=0)
		{
			undoStack.push(s[j]);
			j--;
		}
	}
	undoStack.push(op);
	while (!redoStack.isEmpty())
	{
		redoStack.pop();
	}
}
String UndoRedoWithTwoStack::undo()
{
	if (undoStack.isEmpty())
		return 0;
	redoStack.push(undoStack.pop());
	return redoStack.stackTop();
}
String UndoRedoWithTwoStack::redo()
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
//void UndoRedoWithTwoStack::displayS()
//{
//	cout << "\nStack Status After undo operations(Action history): ";
//	undoStack.display();
//	cout << "\nStack Status After Redo operations(Action history): ";
//	redoStack.display();
//
//}