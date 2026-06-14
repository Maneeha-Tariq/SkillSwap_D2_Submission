#include "BinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
    BinaryTree<char> bt(5); // height 4

    bt.setRoot('A');
    bt.setLeftChild('A', 'B');
    bt.setRightChild('A', 'C');
    bt.setLeftChild('B', 'D');
    bt.setRightChild('B', 'E');
    bt.setRightChild('C', 'F');
    bt.setRightChild('D', 'H');
    bt.setLeftChild('E', 'I');
    bt.setLeftChild('I', 'K');
    bt.setRightChild('E', 'J');
   
    

   /* cout << "Pre-order: ";
    bt.preOrder();

    cout << "\nIn-order: ";
    bt.inOrder();

    cout << "\nPost-order: ";
    bt.postOrder();

    cout << "\nLevel 0: ";
    bt.displayLevel(0);

    cout << "\nLevel 1: ";
    bt.displayLevel(1);

    cout << "\nLevel 2: ";
    bt.displayLevel(2);

    cout << "\n"<<bt.heightOfTree(0);
    bt.levelOrder();
    cout << "\n";*/
  
    bt.displayExplorerView();

    return 0;
}


//#include "BinaryTree.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    BinaryTree<char> bt(5); // height 4
//
//    bt.setRoot('A');
//    bt.setLeftChild('A', 'B');
//    bt.setRightChild('A', 'C');
//    bt.setLeftChild('B', 'D');
//    bt.setRightChild('B', 'E');
//    bt.setRightChild('C', 'F');
//    bt.setRightChild('D', 'H');
//    bt.setLeftChild('E', 'I');
//    bt.setRightChild('E', 'J');
//    bt.setLeftChild('I', 'K');
//
//   
// 
//    
//    /* cout << "\n\nPre-order (VLR): ";
//     bt.preOrder();*/
//     cout << "\nIn-order (LVR): ";
//     bt.inOrder();
//    /* cout << "\nPost-order (LRV): ";
//     bt.postOrder();
//     cout << "\nLevel-order: ";
//     bt.levelOrder();
//     cout << "\n";*/
//    
//
//    return 0;
//}
//



