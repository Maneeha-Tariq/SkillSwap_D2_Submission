#ifndef SYMBOL_H
#define SYMBOL_H
#include<iostream>
using namespace std;
struct Symbol
{
    char ch;
    int freq;

    Symbol() 
    { 
        ch = '\0';
        freq = 0;
    }
    Symbol(char c, int f) 
    { 
        ch = c;
        freq = f; 
    }
};
#endif