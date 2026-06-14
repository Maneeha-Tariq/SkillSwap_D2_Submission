//BSEF24M046
#ifndef UNDO_REDO_WITH_ONE_STACK_H
#define UNDO_REDO_WITH_ONE_STACK_H
#include<iostream>
using namespace std;
#include "Stack.h"
#include "String.h"
class UndoRedoWithOneStack
{
	int capacity;
	String undoC=" ";
	String redoC=" ";
	Stack<char> UndoRedoStack;
	String undoCount(char c);
	String redoCount(char c);
	/*void displayS();*/
public:

	UndoRedoWithOneStack(int c = 100);
	void performAction(char op);
	char undo();
	char  redo();
	int getSize();
	/*void display();*/
};
#endif


