#include "BST.h"
#include<iostream>
using namespace std;
int main()
{
	//BST<int> tree;

	//tree.insert(50);
	//tree.insert(30);
	//tree.insert(70);
	//tree.insert(20);
	//tree.insert(40);
	//tree.insert(60);
	//tree.insert(80);

	////// Search existing values
	////cout << tree.search(50) << endl; // 1 (true)
	////cout << tree.search(20) << endl; // 1 (true)
	////cout << tree.search(80) << endl; // 1 (true)

	////// Search non-existing values
	////cout << tree.search(25) << endl; // 0 (false)
	////cout << tree.search(90) << endl; // 0 (false)

	//tree.remove(20); // leaf node

	//cout << tree.search(20) << endl; // 0 (false)
	//cout << tree.search(30) << endl; // 1 (true)

	//tree.remove(30); // 30 has only left child 40 now

	//cout << tree.search(30) << endl; // 0 (false)
	//cout << tree.search(40) << endl; // 1 (true)

	//cout << tree.root->left->info;      //only works if root is public

	//BST<int> tree3;
	//tree3.insert(100);

	//tree3.remove(100); // root is leaf

	//cout << tree3.search(100) << endl; // 0
	BST<int> tree;

	// Insert values
	tree.insert(4);
	tree.insert(2);
	tree.insert(5);
	tree.insert(6);

	//cout << "Original Preorder: ";
	//tree.preOrderPrint();   // provided by your BST

	//// Call double tree
	//tree.doubleTree(); // this internally calls doubleTre(root)

	//cout << "\nAfter doubleTree Preorder: ";
	//tree.preOrderPrint();   // see result
	cout<< tree.findBalanceFactor(5);



}