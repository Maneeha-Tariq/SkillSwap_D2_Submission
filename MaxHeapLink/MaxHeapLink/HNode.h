#ifndef HNODE_H
#define HNODE_H
#include<iostream>
using namespace std;

template<typename T>
struct HNode 
{
    T data;
    HNode* left;
    HNode* right;
    HNode* par;  // to move up easily

    HNode(T val) {
        data = val;
        left = right = par = nullptr;
    }
};
#endif
