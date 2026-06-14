#include<iostream>
#include "FoldingHashCode.h"
using namespace std;
int main()
{
	FoldingHash fh;
	fh.insert(123456);
	fh.insert(7);
	fh.insert(12345);
	fh.remove(12345);
	cout<< fh.getNoOfElements();
}