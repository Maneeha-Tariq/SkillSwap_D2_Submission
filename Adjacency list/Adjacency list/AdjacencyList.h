#ifndef ADJACENCY_LIST_DIR_H
#define ADJACENCY_LIST_DIR_H
#include<iostream>
#include "Edge.h"
#include "Array.h"
using namespace std;
enum Color { W, G, B };
class Adjacency_List_Dir
{
	Array<Edge*>grp;
	bool isValidIndex(int v)
	{
		return v >= 0 && v < grp.getSize();
	}
	void DFSHelper(int u, Array<bool>& visit)
	{
		visit[u] = true;
		cout << u << " ";
		Edge* temp = grp[u];
		while (temp != nullptr)
		{
			int v = temp->vertex;
			if (!visit[v])
			{
				DFSHelper(v, visit);
			}
			temp = temp->next;
		}
	}
	bool DirectedCycleHelper(int u, Array<Color>& visit)
	{
		visit[u] = G;
		Edge* temp = grp[u];
		while (temp != nullptr)
		{
			int v = temp->vertex;
			if (visit[v] == W)
			{
				if (DirectedCycleHelper(v, visit))
				{
					return true;
				}
			}
			else if(visit[v] == G )
			{
				return true;
			}
			temp = temp->next;
		}
		visit[u] = B;
		return false;
	}

public:

	Adjacency_List_Dir(int v)
	{
		grp.reSize(v);
		for (int i = 0; i < grp.getSize(); i++)
		{
			grp[i] = nullptr;
		}
	}
	void addEdge(int u, int v, int wt = 1)
	{
		if (!isValidIndex(u) || !isValidIndex(v)) return;
		if (!isEdge(u, v))
		{
			Edge* e = new Edge(v, wt);
			e->next = grp[u];
			grp[u] = e;
		}
	}
	bool isEdge(int u, int v)
	{
		if (!isValidIndex(u) || !isValidIndex(v)) return false;

		Edge* curr = grp[u];
		while (curr)
		{
			if (curr->vertex == v)
			{
				return true;
			}

			curr = curr->next;
		}
		return false;
	}
	void removeEdge(int u, int v)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			Edge* curr = grp[u];
			Edge* prev = nullptr;

			while (curr)
			{
				if (curr->vertex == v)
				{
					if (prev)
					{
						prev->next = curr->next;
					}
					else
					{
						grp[u] = curr->next;
					}
					delete curr;
					return;
				}
				prev = curr;
				curr = curr->next;
			}
		}
	}
	bool isDirectedCycle(int start)
	{
		Array<Color>visited(grp.getSize());
		for (int i = 0; i < grp.getSize(); i++)
		{
			visited[i] = W;
		}
		for (int i = 0; i < grp.getSize(); i++)
		{
			if (visited[i] == W)
			{
				if (DirectedCycleHelper(i, visited))
				{
					return true;
				}
			}
		}
		return false;
	}
	void DFS(int start)
	{
		Array<bool> visited(grp.getSize());
		for (int i = 0; i < grp.getSize(); i++)
		{
			visited[i] = false;
		}
		DFSHelper(start, visited);
		for (int i = 0; i < visited.getSize(); i++)
		{
			if (!visited[i])
			{
				DFSHelper(i, visited);
			}
		}
	}
	void display()
	{
		for (int i = 0; i < grp.getSize(); i++)
		{
			Edge* curr = grp[i];
			if (!curr)
			{
				cout << i <<  " is null\n";
			}
			else
			{
				cout << i << " ";

				while (curr)
				{
					cout << "(" << curr->vertex << "," << curr->weight << ")";
					if (curr->next) cout << "->";
					curr = curr->next;
				}
				cout << endl;
			}
		}
	}
};
#endif