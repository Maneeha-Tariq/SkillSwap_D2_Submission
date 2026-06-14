//#include <iostream>
//#include "LinkedBinaryTree.h"
//using namespace std;
//
//int main()
//{
//    BinaryTree<int> bt;
//    bt.setRoot(10);
//    bt.setRightChild(10, 30);
//
//    String s = bt.serializeFullyParenthesis();
//    cout << s << endl;
//
//   /* bt.setLeftChild(2, 4);
//    bt.setRightChild(2, 5);
//    bt.setLeftChild(3, 6);
//    bt.setRightChild(3, 7);
//
//    cout << "\n--- TRAVERSALS ---\n";
//    cout << "PreOrder   : ";
//    bt.preOrder();
//
//    cout << "InOrder    : ";
//    bt.inOrder();
//
//    cout << "PostOrder  : ";
//    bt.postOrder();
//
//
//    cout << "\n--- LEVEL ORDER ---\n";
//    bt.levelOrder();
//
//
//    cout << "\n--- HEIGHT OF TREE ---\n";
//    cout << "Height = " << bt.heightOfTree() << endl;
//
//
//    cout << "\n--- DISPLAY LEVELS ---\n";
//    for (int i = 0; i < bt.heightOfTree(); i++)
//    {
//        cout << "Level " << i << ": ";
//        bt.displayLevel(i);
//    }
//
//
//    cout << "\n--- FIND LEVEL OF A NODE ---\n";
//    cout << "Level of 5 = " << bt.findLevelOfNode(5) << endl;
//    cout << "Level of 7 = " << bt.findLevelOfNode(7) << endl;
//
//
//    cout << "\n--- PARENTHESIZED VIEW ---\n";
//    bt.displayParenthesizedView();
//
//
//    cout << "\n--- EXPLORER VIEW ---\n";
//    bt.displayExplorerView();
//
//
//    cout << "\n--- DESCENDANTS ---\n";
//    cout << "Descendants of 2 = ";
//    bt.displayDescendents(2);
//
//    cout << "Descendants of 1 = ";
//    bt.displayDescendents(1);
//
//
//    cout << "\n--- ANCESTORS ---\n";
//    cout << "Ancestors of 5 = ";
//    bt.displayAncestors(5);
//
//    cout << "Ancestors of 7 = ";
//    bt.displayAncestors(7);
//
//
//    cout << "\n--- GET PARENT ---\n";
//    cout << "Parent of 5 = " << bt.getParent(5) << endl;
//    cout << "Parent of 7 = " << bt.getParent(7) << endl;
//
//
//    cout << "\n--- REMOVE SUBTREE ---\n";
//    cout << "Removing node 2 (removes 2,4,5)\n";
//    bt.remove(2);
//
//    cout << "Level Order after deletion: ";
//    bt.levelOrder();
//
//
//    cout << "\n--- REMOVE ROOT ---\n";
//    cout << "Removing root (1)...\n";
//    bt.remove(1);
//
//    cout << "Level order after deleting root: ";
//    bt.levelOrder();
//
//
//    cout << "\n--- END ---\n";*/
//    return 0;
//}



#include <iostream>
#include "String.h"
#include "LinkedBinaryTree.h"

using namespace std;

int main()
{
    //// Integer se String object banao
    //String r(1234);

    //// Display the string
    //cout << "String value: " << r << endl;

    //// Get its length
    //int t = r.getLength();
    //cout << "Length of string: " << t << endl;

    //// Convert back to integer
    //long long int n = r.convertToInteger();
    //cout << "Converted back to integer: " << n << endl;

    BinaryTree<int> list;
    list.setRoot(10);
   /* list.setLeftChild(10, 20);
    list.setLeftChild(20, 30);
    list.setRightChild(20, 40);
    list.setLeftChild(40, 50);
    list.setRightChild(10, 60);
    list.setLeftChild(60, 70);*/
    list.setLeftChild(10, 5);
    list.setLeftChild(5, 2);
    list.setRightChild(5, 7);
    list.setRightChild(10, 15);
    list.setLeftChild(15, 12);
    list.setLeftChild(12, 6);
    
    cout<< list.findBalanceFactor(15);



    return 0;
}


