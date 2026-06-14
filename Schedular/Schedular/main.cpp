#include "Process.h"
#include "String.h"
#include "Schedular.h"
#include<iostream>
using namespace std;
//int mystery(int x,int y)
//{
//	if (x < 0)
//	{
//		return -mystery(-x, y);
//	}
//	else if (y < 0)
//	{
//		return -mystery(x, -y);
//	}
//	else if (x == 0 && y == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 100 * mystery(x / 10, y / 10) + 10 * (x % 10) + (y % 10);
//	}
//}
int main()
{
	Process arr[3] = {
		Process(46, "Maneeha", 20),
	    Process(22, "Hafsa", 10),
	    Process(43, "Khadija", 40) 
	};
	
	Schedular s(arr, 3, 10);
	s.assignProcess();
	/*cout<<	mystery(135,246);*/
	
}