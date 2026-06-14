//BSEF24M046
#include"UNDO_REDO_WITH_ONE_STACK.h"
#include<iostream>
using namespace std;
UndoRedoWithOneStack::UndoRedoWithOneStack(int c)
{
	if (c > 0)
		capacity = c;
	redoC.reSize(capacity);
}
void UndoRedoWithOneStack::performAction(const String& op)
{
	if (capacity == UndoRedoStack.getNumberOfElements())
	{
		Array<String> s(UndoRedoStack.getNumberOfElements());
		int i = 0;
		while (!UndoRedoStack.isEmpty())
		{
			s[i] = UndoRedoStack.pop();
			i++;
		}
		int j = i - 2;
		while (j >= 0)
		{
			UndoRedoStack.push(s[j]);
			j--;
		}
	}
	UndoRedoStack.push(op);
	redoIndex = 0;
}
String UndoRedoWithOneStack::undo()
{
	if (UndoRedoStack.isEmpty())
		return "";
	String s = UndoRedoStack.stackTop();
	UndoRedoStack.pop();
	redoCount(s);
	return s;
}
String UndoRedoWithOneStack::redo()
{
	if (redoIndex == 0)
		return "";

	redoIndex--;
	String t = redoC[redoIndex];
	UndoRedoStack.push(t);
	return t;
}
int UndoRedoWithOneStack::getSize()
{
	return capacity;
}
String UndoRedoWithOneStack::redoCount(const String& c)
{
	if (redoIndex < redoC.getSize())
	{
	    redoC[redoIndex++] = c;
    }
	return c;
}
