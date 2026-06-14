#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
using namespace std;

template<typename T>
struct AVLNode
{
    T info;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
    AVLNode()
    {
        info = 0;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    BTNode(T val)
    {
        info = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

};
#endif 



