#ifndef BTNODE_H
#define BTNODE_H
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

template<typename T>
struct BTNode
{
    T info;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode<T>* height;
    BTNode(T val)
    {
        info = val;
        left = nullptr;
        right = nullptr;
        height = 0;
    }

};
#endif 



