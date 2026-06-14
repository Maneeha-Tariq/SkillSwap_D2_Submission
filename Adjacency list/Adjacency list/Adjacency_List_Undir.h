#ifndef ADJACENCY_LIST_UNDIR_H
#define ADJACENCY_LIST_UNDIR_H
#include<iostream>
#include "Edge.h"
#include "Array.h"
using namespace std;
class Adjacency_List_Undir
{
	Array<Edge*>grp;
	bool isValidIndex(int v)
	{
		return v >= 0 && v < grp.getSize();
	}
	void remove(int u, int v)
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
	bool Undir_Cycle_Helper(int u, Array<bool>& visit, int parent)
	{
		visit[u] = true;
		Edge* temp = grp[u];
		while (temp != nullptr)
		{
			int v = temp->vertex;
			if (!visit[v])
			{
				if (Undir_Cycle_Helper(v, visit, u))
				{
					return true;
				}
			}
			else if (visit[v] && v != parent)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

public:

	Adjacency_List_Undir(int v)
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

		if (!isEdge(v, u))
		{
			Edge* e2 = new Edge(u, wt);
			e2->next = grp[v];
			grp[v] = e2;
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
		remove(u, v);
		remove(v, u);
	}
	bool undirectCycle(int start)
	{
		Array<bool> visited(grp.getSize());
		for (int i = 0; i < grp.getSize(); i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < visited.getSize(); i++)   //disconnected b cover hojaen g 
		{
			if (!visited[i])
			{
				if (Undir_Cycle_Helper(start, visited, -1))
				{
					return true;
				}
			}
		}
		return false;
		
	}
	void display()
	{
		for (int i = 0; i < grp.getSize(); i++)
		{
			Edge* curr = grp[i];
			if (!curr)
			{
				cout << i << " is null\n";
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