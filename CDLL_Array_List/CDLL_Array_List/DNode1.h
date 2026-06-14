#ifndef DNODE1_H
#define DNODE1_H

#include <iostream>
using namespace std;

template <typename T>
struct DNode1
{
    T info;   
    int next; 
    int prev; 

    
    DNode1() : info(), next(-1), prev(-1)
    {
    }

    DNode1(T val) : info(val), next(-1), prev(-1)
    {
    }
};

#endif
