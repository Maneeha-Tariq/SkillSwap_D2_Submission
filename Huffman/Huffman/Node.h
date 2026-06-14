#ifndef NODE_H
#define NODE_H
#include "Symbol.h"
#include<iostream>
using namespace std;
struct Node
{
    Symbol* sym;
    Node* left;
    Node* right;

    Node(Symbol* s) 
    { 
        sym = s; 
        left = nullptr; 
        right = nullptr; 
    }
    Node(Symbol* s, Node* l, Node* r) 
    { 
        sym = s; 
        left = l; 
        right = r; 
    }
};
#endif
