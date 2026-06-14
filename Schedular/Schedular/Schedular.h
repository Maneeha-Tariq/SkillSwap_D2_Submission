#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include "Process.h"
#include "DoubleQueue.h"
class Schedular
{
	Process * processArray;
	int processArrayLength;
	int timeQuantum;
public:
	Schedular(Process* p, int length, int quantum);
	void assignProcess();

};
Schedular:: Schedular(Process* p, int length, int quantum)
{
	processArrayLength = length;
	timeQuantum = quantum;
	processArray = new Process[length];

	for (int i = 0; i < length; i++)
	{
		processArray[i] = p[i];
	}
}
void Schedular::assignProcess()
{
	DECK<Process> data;
	for (int i = 0; i < processArrayLength; i++)
	{
		data.insertElementAtRear(processArray[i]);
	}
	cout << "\t\t=== Initial Process List ===\n";
	for (int i = 0; i < processArrayLength; i++)
	{
		cout << "Process[" << i << "]" << "-   ";
		cout << "Id: " << processArray[i].processId;
		cout << "\tName: "<< processArray[i].processName;
		cout << "\tBurst Time: " << processArray[i].processExactTime<< endl;
	}
	Process p;
	cout << "\n\n\t\t===========================\n\n";
	while (!data.isEmpty())
	{

		p = data.removeElementFromFront();
		if (p.processExactTime > timeQuantum)
		{
			cout << "Executing: " << p.processName << " for " << timeQuantum << " units\n";
			p.processExactTime -= timeQuantum;
			data.insertElementAtRear(p);
		}
		else 
		{
			cout << "Executing: " << p.processName
				<< " for " << p.processExactTime << " units (completed)\n";
		}
	}

}
#endif


