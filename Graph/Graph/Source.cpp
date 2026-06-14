#include "GraphAdjMatrix.h"
#include<iostream>
using namespace std;
int main()
{
	GraphAdjMatrix g1(9);
	g1.addEdge(0, 1);
	g1.addEdge(0, 3);
	g1.addEdge(1, 2);
	g1.addEdge(1, 4);
	g1.addEdge(2, 1);
	g1.addEdge(2, 3);
	g1.addEdge(2, 4);
	g1.addEdge(2, 5);

	g1.printAdjacencyMatrix();
	GraphAdjMatrix spTree1 = g1.DFS(0);
	spTree1.printAdjacencyMatrix();

	GraphAdjMatrix spTree2 = g1.DFS(2);
	spTree2.printAdjacencyMatrix();

	cout << g1.isCyclic();
	cout << g1.isStronglyConnected();
	g1.printStronglyConnectedComponents();

}