
#include "Circular .h"
#include "String.h"
#include "Stack.h"
using namespace std;
int main()
{
	Circular c(3);

	cout << "Perform A\n";
	c.performAction("A");
	cout << "Perform B\n";
	c.performAction("B");
	cout << "Perform C\n";
	c.performAction("C");
	cout << "Perform D (stack full)\n";
	c.performAction("D");
	
	cout << "\nUndo Operations:\n";
	cout << "Undo: " << c.undo() << "\n";  // removes top
	cout << "Undo: " << c.undo() << "\n";

	cout << "\nRedo Operations:\n";
	cout << "Redo: " << c.redo() << "\n";  // redo last undone

	cout << "\nPerform E (after undo)\n";
	c.performAction("E");

	cout << "\nUndo: " << c.undo() << "\n";
	cout << "Redo: " << c.redo() << "\n";
}