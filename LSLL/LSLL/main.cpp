//#include "LSLL.h"
//#include<iostream>
//using namespace std;
//int main()
//{
//	//LSLL<int> list;
//	//list.insertAtHead(2);
//	//list.insertAtTail(3);
//	//list.insertAtTail(4);
//	//list.insertAtTail(5);
//	//list.insertAtTail(7);
//	//list.insertAtTail(9);
//	//list.insertAtTail(11);
//	//list.deleteAlternate();
//	///*list.insertAfter(66,0);
//	//list.insertAfter(4, 88);
//	//list.insertBefore(2,11);
//	//list.removeAfter(7);
//	//list.removeAfter(88);
//	//list.removeBefore(2);
//	//list.removeBefore(4);*/
//	//list.print();
//
//	/*LSLL<int> a, b;
//	a.insertAtTail(1);
//	a.insertAtTail(2);
//	a.insertAtTail(3);
//
//	b.insertAtTail(1);
//	b.insertAtTail(2);
//	b.insertAtTail(3);
//
//	cout << a.isEqual(b);  
//
//	b.insertAtTail(4);
//	cout <<'\n'<<  a.isEqual(b);  */
//
//	/*LSLL<int> list1, list2;
//
//	list1.insertAtTail(1);
//	list1.insertAtTail(2);
//	list1.insertAtTail(3);
//
//	list2.insertAtTail(3);
//	list2.insertAtTail(4);
//	list2.insertAtTail(5);
//
//	LSLL<int> result = list1.doUnion(list2);
//	result.print();*/
//
//
//
//	//LSLL<int> mainList;
//	//mainList.insertAtTail(1);
//	//mainList.insertAtTail(2);
//	//mainList.insertAtTail(3);
//	///*mainList.insertAtTail(4);
//	//mainList.insertAtTail(5);*/
//	//LSLL<int> mainList2;
//	//mainList2.insertAtTail(3);
//	//mainList2.insertAtTail(4);
//	//mainList2.insertAtTail(2);
//	//mainList2.insertAtTail(1);
//	//
//	/*cout<< mainList.isEqual(mainList2);*/
//
//
//
//
//
//
//	LSLL<int> list1;
//	LSLL<int> list2;
//
//	// List 1: 1 -> 2 -> 3 -> 7 -> 8 -> 9
//	list1.insertAtTail(1);
//	list1.insertAtTail(2);
//	list1.insertAtTail(3);
//	list1.insertAtTail(7);
//	list1.insertAtTail(8);
//	list1.insertAtTail(9);
//
//	// List 2: 4 -> 5
//	list2.insertAtTail(4);
//	list2.insertAtTail(5);
//
//	// Make lists join at node with value 7
//	Node<int>* temp1 = list1.head;
//	while (temp1 && temp1->info != 7) temp1 = temp1->next;
//
//	Node<int>* temp2 = list2.head;
//	while (temp2->next) temp2 = temp2->next;
//	temp2->next = temp1; // join
//
//	if (list1.isJoiningPoint(list2))
//		cout << "Lists join." << list1.isJoiningPointVal(list2)<< endl;
//	else
//		cout << "Lists do not join." << endl;
//
//	
//}
//
////#include<iostream>
////using namespace std;
////#include<iostream>
////using namespace std;
////class A
////{
////	
////	int a;
////	class B
////	{
////		int b1;
////		A& ob;
////     public:
////        int b2;
////		B(A& obj): ob(obj)
////		{
////			b2 = ob.a;
////		}
////        B(A& obj,int t): ob(obj)
////        { t+=ob.a;}
//// 
////
////	};
////public:
//// void f()
////{  B obj1(*this);
////    B obj2(*this,46);}
////
////};
//


#include <iostream>
#include "LSLL.h"

using namespace std;

int main()
{
    LSLL<int> list;
    // Insert some values
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
   
  
    
  /*  list.insertAtTail(6);*/
    
   /* list.insertAtTail(10);
    list.insertAtTail(0);*/
   /* list.insertAtTail(3);
    list.insertAtTail(9);*/
    /*list.sortbyVal();*/
  /*  cout << "List1: ";
    list.print();
    cout << "\n";
    LSLL<int> list2;
    list2.insertAtTail(19);
    list2.insertAtTail(10);
    list2.insertAtTail(100);
    list2.insertAtTail(90);
    list2.insertAtTail(5);
    list2.sortbyVal();
    cout << "List2: ";
    list2.print();
    cout << "\n";

  LSLL<int> list3 =  list.mergeSortedList(list2);
  cout << "List3: ";
  list3.print();
  cout << "\n";*/

    //cout << "Original list: ";
    //list.print(); // should print: 30 10 20 50 40
    //cout << endl;

    // Sort the list using your sortbylink function
   /* list.sortbylink();*/

    //cout << "Sorted list: ";
    //list.print(); // should print: 10 20 30 40 50
    //cout << endl;

    return 0;

}

