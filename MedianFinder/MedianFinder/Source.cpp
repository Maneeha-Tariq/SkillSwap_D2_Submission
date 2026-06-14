#include "MedianFinder.h"
#include <iostream>
using namespace std;
int main()
{
	MedianFinder mf;
	int stream[] = { 5,2,10,3,8 };
	int n = 5;
	for (int i = 0; i < n; i++)
	{
		mf.addNumber(stream[i]);
		cout << mf.findMedian() << '\n';
	}
	return 0;

}