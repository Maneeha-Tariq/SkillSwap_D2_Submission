#include "Queue.h"
#include<iostream>
using namespace std;
int main()
{
	Queue<int> ur;

	/*ur.enQueue(1);
	ur.enQueue(3);
	ur.enQueue(6);
	int a = ur.getNoOfElements();
	cout << a<< "\n";
	cout<< ur.deQueue()<<'\n';
	cout<< ur.getCapacity();*/

	ur.enQueue(1);
	ur.enQueue(3);
	ur.enQueue(6);
	ur.enQueue(8);
	ur.enQueue(9);
	ur.enQueue(2);
	ur.enQueue(67);
	ur.enQueue(5);
	ur.enQueue(5);
	cout << ur.getNoOfElements()<<'\n';
	cout << ur.getCapacity() << '\n';
	ur.deQueue();
	ur.deQueue();
	ur.deQueue();
	ur.deQueue();
	/*ur.deQueue();*/
	/*ur.deQueue();*/
	
	int x = ur.getNoOfElements();
	cout << x;
	cout << '\n';
	int b = ur.getCapacity();
	cout << b;


}