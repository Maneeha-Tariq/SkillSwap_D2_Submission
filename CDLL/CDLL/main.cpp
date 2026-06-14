#include "CDLL.h"
int main()
{
	CDLL<int> list;
	list.insertAtHead(1);
	list.insertAtHead(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtHead(7);
	list.insertAfter(66, 0);
	list.insertAfter(4, 88);
	list.insertBefore(2, 11);
	list.removeAfter(7);
	list.removeAfter(88);
	list.removeBefore(2);
	list.removeBefore(4);
	list.remove(4);
	list.print();
	return 0;
}
