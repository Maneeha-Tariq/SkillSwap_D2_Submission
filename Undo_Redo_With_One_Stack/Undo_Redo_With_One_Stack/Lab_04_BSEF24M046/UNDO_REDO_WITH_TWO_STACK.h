#ifndef UNDO_REDO_WITH_TWO_STACK_H
#define UNDO_REDO_WITH_TWO_STACK_H
#include "Stack.h"
//BSEF24M046
#include<iostream>
using namespace std;
class UndoRedoWithTwoStack
{
	int capacity;
	Stack<char> undoStack;
	Stack<char> redoStack;
public:

	UndoRedoWithTwoStack(int c = 100);
	void performAction(char op);
	char undo();
	char  redo();
	int getSize();
	/*void display();*/
};
#endif

