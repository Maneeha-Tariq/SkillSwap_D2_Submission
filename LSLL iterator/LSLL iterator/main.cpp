#include "LSLL_ITER.h"
#include<iostream>
using namespace std;
int main()
{
	LSLL<int> mainList;
	mainList.insertAtTail(1);
	mainList.insertAtTail(2);
	mainList.insertAtTail(3);
	mainList.insertAtTail(4);
	mainList.insertAtTail(5);


	LSLL<int> List2;
	List2.insertAtTail(3);
	List2.insertAtTail(1);
	List2.insertAtTail(2);
	List2.insertAtTail(8);
    List2.insertAtTail(6);
	LSLL<int>::Iterator it = mainList.begin();
	LSLL<int>::Iterator i = List2.begin();
	int sum = 0;
	while (it != mainList.end() && i != List2.end())
	{
		sum = *it + *i;
		cout << sum << " ";
		++it, ++i;
	}
	
	/*cout << "Original iterator:  ";
	while (it != mainList.end())
	{
		cout << *it<< " ";
		++it;
	} 
	
	for (auto it = mainList.begin(); it != mainList.end(); ++it)
	{
		*it+= 20;
	}
	cout << "\nAfter Modification:  ";
	for (auto it = mainList.begin(); it != mainList.end(); ++it)
	{
		cout << *it<< " ";
	}*/

}