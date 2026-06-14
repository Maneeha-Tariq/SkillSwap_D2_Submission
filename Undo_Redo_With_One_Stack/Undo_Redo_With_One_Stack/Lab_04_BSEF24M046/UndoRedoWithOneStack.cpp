//BSEF24M046
#include"UNDO_REDO_WITH_ONE_STACK.h"
#include<iostream>
using namespace std;
UndoRedoWithOneStack::UndoRedoWithOneStack(int c)
{
	if (c > 0)
		capacity = c;
}
void UndoRedoWithOneStack::performAction(char op)
{
	if (capacity == UndoRedoStack.getNumberOfElements())
	{
		Stack<char> s;
		while (!UndoRedoStack.isEmpty())
			s.push(UndoRedoStack.pop());
		s.pop();
		while (!s.isEmpty())
			UndoRedoStack.push(s.pop());
	}
	UndoRedoStack.push(op);
}
char UndoRedoWithOneStack::undo()
{
	if (UndoRedoStack.isEmpty())
		return 0;
	/*UndoRedoStack.push(UndoRedoStack.pop());*/
	/*redoStack.push(undoStack.pop());*/
	char c = UndoRedoStack.stackTop();
	undoCount(c);
	UndoRedoStack.pop();
	UndoRedoStack.push(c);
	return c;
}
char UndoRedoWithOneStack::redo()
{
	if (UndoRedoStack.isEmpty())
		return 0;
	/*undoStack.push(redoStack.pop());*/
	char t = UndoRedoStack.stackTop();
	redoCount(t);
	return t;
}
int UndoRedoWithOneStack::getSize()
{
	return capacity;
}
String UndoRedoWithOneStack::undoCount(char c)
{
	undoC += c;
}
String UndoRedoWithOneStack::redoCount(char c)
{
	redoC += c;
}
//void UndoRedoWithOneStack::display()
//{
//	int i = 0;
//	cout << "Status After undo operations: ";
//	while (undoC[i]!= '\0')
//	{
//		cout << undoC[i]<< " ";
//		i++;
//	}
//	cout << "\nStack Status After Redo operations ";
//	int j = 0;
//	while (redoC[j] != '\0')
//	{
//		cout << redoC[j] << " ";
//		j++;
//	}
//
//}