#ifndef PROCESS_H
#define PROCESS_H
#include "String.h"
#include<iostream>
using namespace std;
class Process
{
public:
	int processId;
	String processName;
	int processExactTime;
	Process(int id = 1, String pname = "notepad", int brustTime = 10);
};
Process::Process(int id, String pname, int brustTime)
{
	processId = id;
	processName = pname;
	processExactTime = brustTime;
}

#endif

