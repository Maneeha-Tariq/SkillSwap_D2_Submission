#include "Circular .h"

Circular::Circular(int c)
{
	if (c > 0)
	{
		capacity = c;
	}
	redoC.reSize(capacity);
}
void Circular::performAction(const String& op)
{
	if (capacity == UndoRedo.getNumberOfElements())
	{
		Array<String> s(UndoRedo.getNumberOfElements());
		int i = 0;
		while (!UndoRedo.isEmpty())
		{
			s[i] = UndoRedo.pop();
			i++;
		}
		s[i - 1].remove(0,s[i-1].getLength());
		s[i - 1] = op;
		int j = i-1;
		while (j >= 0)
		{
			UndoRedo.push(s[j]);
			j--;
		}
	}
	else
	{
		UndoRedo.push(op);
	}
	redoIndex = 0;
}
String Circular::undo()
{
	if (UndoRedo.isEmpty())
		return "";
	String s = UndoRedo.stackTop();
	UndoRedo.pop();
	redoCount(s);
	return s;
}
String Circular::redo()
{
	if (redoIndex == 0)
		return "";

	redoIndex--;
	String t = redoC[redoIndex];
	UndoRedo.push(t);
	return t;
}
int Circular::getSize()
{
	return capacity;
}
String Circular::redoCount(const String& c)
{
	if (redoIndex < redoC.getSize())
	{
		redoC[redoIndex++] = c;
	}
	return c;
}


