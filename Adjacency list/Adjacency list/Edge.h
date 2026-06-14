#ifndef EDGE_H
#define EDGE_H
#include<iostream>
using namespace std;
struct Edge
{
	int weight;
	int vertex;
	Edge* next;

	Edge(int v, int wt = 1): weight(wt),vertex(v)
	{
		next = nullptr;
	}
};
#endif