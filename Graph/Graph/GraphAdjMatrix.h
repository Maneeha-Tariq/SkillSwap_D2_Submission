#ifndef GRAPHADJMATRIX_H
#define GRAPHADJMATRIX_H
#include "Queue.h"
#include "Array.h"
#include "Stack.h"
#include <iostream>
using namespace std;
enum Color { W, B, G };
class GraphAdjMatrix
{
	Array<Array<int>> grf;
	bool directed = true;
	bool isValidIndex(int v)
	{
		return v >= 0 && v < grf.getSize();
	}
	void BFSHelper(int startV, Array<bool>& visit,GraphAdjMatrix& tree)
	{
		Queue<int> q;
		visit[startV] = true;
		q.enQueue(startV);
		while (!q.isEmpty())
		{
			int u = q.deQueue();
			for (int v = 0; v < grf.getSize(); v++)
			{
				if (isEdge(u, v) && !visit[v])
				{
					tree.addEdge(u, v);
					visit[v] = true;
					q.enQueue(v);
				}
			}
		}
	}
	void DFSHelper(int startV, Array<bool>& visit,GraphAdjMatrix& tree)
	{
		visit[startV] = true;

		for (int v = 0; v < grf.getSize(); v++)
		{
			if (isEdge(startV, v) && !visit[v])
			{
				tree.addEdge(startV, v);
				DFSHelper(v, visit,tree);
			}
		}

	}
	bool cycleHelper(int startV, Array<Color>& color)
	{

		color[startV] = G;
		int size = grf.getSize();
		for (int v = 0; v < size; v++)
		{
			if (isEdge(startV, v))
			{
				if (color[v] == G)
					return true;

				if (color[v] == W)
				{

					if (cycleHelper(v, color))
					{
						return true;
					}


				}
			}
		}
		color[startV] = B;
		return false;
	}
	bool isUndirCycHelper(int startVertex, Array<bool>& visit, int parent)
	{
		visit[startVertex] = true;

		for (int v = 0; v < grf.getSize(); v++)
		{
			if (isEdge(startVertex, v))
			{
				if (!visit[v])
				{
					if (isUndirCycHelper(v, visit, startVertex))
					{
						return true;
					}
				}
				else if (v != parent)
				{
					return true;
				}
			}

		}
		return false;
	}
	void DFS_Util(int u, Array<bool>& visited)
	{
		visited[u] = true;
		for (int v = 0; v < grf.getSize(); v++)
		{
			if (grf[u][v] != 0 && !visited[v])
			{
				DFS_Util(v, visited);
			}
		}
	}
	int countUndirConnectedComponents()
	{
		int vertex = grf.getSize();
		Array<bool> visited(vertex);
		for (int i = 0; i < vertex; i++)
		{
			visited[i] = false;
		}

		int components = 0;
		for (int i = 0; i < vertex; i++)
		{
			if (!visited[i])
			{
				components++;
				DFS_Util(i, visited);
			}
		}
		return components;
	}
	
	
	void DFS_Time(int u, Array<bool>& visited,
		Array<int>& d, Array<int>& f, int& timeCounter)
	{
		visited[u] = true;
		d[u] = ++timeCounter;

		for (int v = 0; v < grf.getSize(); v++)
		{
			if (grf[u][v] != 0 && !visited[v])
			{
				DFS_Time(v, visited, d, f, timeCounter);
			}
		}

		f[u] = ++timeCounter;
	}
	void DFS_with_Time(int startVertex)
	{
		int n = grf.getSize();

		Array<bool> visited(n);
		Array<int> startTime(n);
		Array<int> endTime(n);

		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
			startTime[i] = 0;
			endTime[i] = 0;
		}

		int timeCounter = 0;  

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				DFS_Time(i, visited, startTime, endTime, timeCounter);
			}
		}

		cout << "Vertices(Start/Finish):  ";
		for (int i = startVertex; i < n; i++)
		{
			cout << i << "("
				<< startTime[i] << "/" << endTime[i] << ")   ";
		}
	}
	void fillFinishTimes(int vertex, Array<int>& finish, Array<bool>& visited)
	{
		int timer = 0;
		for (int i = 0; i < vertex; i++)
		{
			if (!visited[i]) {
				DFS_Time(i, visited, finish, finish, timer);  
			}
		}
	}
	int countSCC()
	{
		int vertex = grf.getSize();
		Array<bool> visited(vertex);
		Array<int> finish(vertex);

		for (int i = 0; i < vertex; i++) {
			visited[i] = false;
			finish[i] = 0;
		}

		fillFinishTimes(vertex, finish, visited);

		Array<int> order(vertex);
		for (int i = 0; i < vertex; i++)
		{
			order[i] = i;
		}

		for (int i = 0; i < vertex - 1; i++)
		{
			for (int j = 0; j < vertex - i - 1; j++)
			{
				if (finish[order[j]] < finish[order[j + 1]])
				{
					int temp = order[j];
					order[j] = order[j + 1];
					order[j + 1] = temp;
				}
			}
		}

		GraphAdjMatrix gt = getTranspose();
		for (int i = 0; i < vertex; i++) visited[i] = false;

		int scc_count = 0;
		for (int i = 0; i < vertex; i++)
		{
			int u = order[i];
			if (!visited[u])
			{
				scc_count++;
				gt.DFS_Util(u, visited);
			}
		}

		return scc_count;
	}
	GraphAdjMatrix getTranspose()
	{
		int vertex = grf.getSize();
		GraphAdjMatrix gt(vertex, directed);
		for (int i = 0; i < vertex; i++)
		{
			for (int j = 0; j < vertex; j++)
			{
				if (grf[i][j] != 0)
					gt.addEdge(j, i, grf[i][j]);
			}
		}
		return gt;
	}
	Array<Array<int>> getSpanningTree_Prims()
	{
		int V = grf.getSize();

		Array<bool> inMST(V);
		Array<int> key(V);
		Array<int> parent(V);

		for (int i = 0; i < V; i++)
		{
			inMST[i] = false;
			key[i] = INT_MAX;
			parent[i] = -1;
		}

		key[0] = 0;  

		for (int count = 0; count < V - 1; count++)
		{
			
			int u = -1;
			int minKey = INT_MAX;

			for (int v = 0; v < V; v++)
			{
				if (!inMST[v] && key[v] < minKey)
				{
					minKey = key[v];
					u = v;
				}
			}

			inMST[u] = true;

			
			for (int v = 0; v < V; v++)
			{
				int wt = grf[u][v];  
				if (wt != 0 && !inMST[v] && wt < key[v])
				{
					key[v] = wt;
					parent[v] = u;
				}
			}
		}

		Array<Array<int>> tree(V - 1);
		int k = 0;

		for (int i = 1; i < V; i++)
		{
			Array<int> edge(3);
			edge[0] = parent[i];
			edge[1] = i;
			edge[2] = key[i];
			tree[k++] = edge;
		}

		return tree;
	}
	void DFS_Strongly_Helper(int u, Array<bool>& visited)
	{
		cout << u << " ";
		visited[u] = true;
		for (int v = 0; v < grf.getSize(); v++)
		{
			if (grf[u][v] != 0 && !visited[v])
			{
				DFS_Util(v, visited);
			}
		}
	}
	void BFS_Time(int u, Array<bool>& visited,
		Array<int>& d, Array<int>& f, int& timeCounter)
	{
		Queue<int> q;
		visited[u] = true;
		d[u] = ++timeCounter;
		q.enQueue(u);
		while (!q.isEmpty())
		{
			int u = q.deQueue();
			for (int v = 0; v < grf.getSize(); v++)
			{
				if (isEdge(u, v) && !visited[v])
				{
					visited[v] = true;
					q.enQueue(v);
				}
			}
		}
		f[u] = ++timeCounter;
	}
	void BFS_with_Time(int startVertex)
	{
		int n = grf.getSize();

		Array<bool> visited(n);
		Array<int> startTime(n);
		Array<int> endTime(n);

		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
			startTime[i] = 0;
			endTime[i] = 0;
		}

		int timeCounter = 0;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				BFS_Time(i, visited, startTime, endTime, timeCounter);
			}
		}

		cout << "Vertices(Start/Finish):  ";
		for (int i = startVertex; i < n; i++)
		{
			cout << i << "("
				<< startTime[i] << "/" << endTime[i] << ")   ";
		}
	}
public:

	GraphAdjMatrix(int v, bool dir = true) : directed(dir)
	{
		grf.reSize(v);
		for (int i = 0; i < grf.getSize(); i++)
		{
			grf[i].reSize(v);
		}
		for (int i = 0; i < grf.getSize(); i++)
		{
			for (int j = 0; j < grf[i].getSize(); j++)
			{
				grf[i][j] = 0;
			}
		}
	}
	void addEdge(int u, int v, int weight = 1)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			grf[u][v] = weight;
			if (!directed)
			{
				grf[v][u] = weight;
			}
		}
	}
	void removeEdge(int u, int v)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			grf[u][v] = 0;
			if (!directed)
			{
				grf[v][u] = 0;
			}
		}
	}
	bool isEdge(int u, int v)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			if (grf[u][v] == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	void printAdjacencyMatrix()
	{
		for (int i = 0; i < grf.getSize(); i++)
		{
			for (int j = 0; j < grf[i].getSize(); j++)
				cout << grf[i][j] << " ";
			cout << endl;
		}
	}
	GraphAdjMatrix BFS(int startVertex)
	{
		Queue<int> q;
		int size = grf.getSize();
		GraphAdjMatrix tree(size, false);
		Array<bool>visited(size);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		if (isValidIndex(startVertex) && !visited[startVertex])
		{
			BFSHelper(startVertex, visited, tree);
		}
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				BFSHelper(i, visited, tree);
			}
		}
		BFS_with_Time(startVertex);
		return tree;

	}
	GraphAdjMatrix DFS(int startVertex)
	{
		int size = grf.getSize();
		GraphAdjMatrix tree(size, false);
		Array<bool> visited(size);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		if (isValidIndex(startVertex) && !visited[startVertex])
		{
			DFSHelper(startVertex, visited, tree);
		}
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				DFSHelper(startVertex, visited, tree);
			}
		}
		DFS_with_Time(startVertex);
		return tree;
	}
	bool isCyclic()
	{
		if (directed)
		{
			Array<Color> c(grf.getSize());
			for (int i = 0; i < grf.getSize(); i++)
			{
				c[i] = W;
			}
			for (int i = 0; i < grf.getSize(); i++)
			{
				if (isValidIndex(i) && c[i] == W)
				{
					if (cycleHelper(i, c))
					{
						return true;
					}
				}
			}
			return false;
		}
		else 
		{
			int size = grf.getSize();
			Array<bool> visited(size);

			for (int i = 0; i < size; i++)
				visited[i] = false;

			for (int i = 0; i < size; i++)
			{
				if (isValidIndex(i) && !visited[i])
				{
					if (isUndirCycHelper(i, visited, -1))
						return true;
				}
			}
			return false;
		}
	}
	bool isStronglyConnected()
	{
		if (!directed)
		{
			int count = countUndirConnectedComponents();
			if (count == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			int count = countSCC();
			if (count == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	GraphAdjMatrix DFS()
	{
		int size = grf.getSize();
		GraphAdjMatrix tree(size, false);
		Array<bool> visited(size);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < size; i++)
		{
			if (isValidIndex(i) && !visited[i])
			{
				DFSHelper(i, visited, tree);
			}
		}
		return tree;
	}
	int prims(int start)
	{
		Array<Array<int>> tree = getSpanningTree_Prims();
		int size = tree.getSize();
		int cost = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (grf[i][j] != 0)
				{
					cout << i << "->" << j << "\tWeight: " << grf[i][j]<< "\n";
					cost = cost + grf[i][j];
				}
			}
		}
		return cost;

	}
	void printStronglyConnectedComponents()
	{
		int vertex = grf.getSize();
		Array<bool> visited(vertex);
		Array<int> finish(vertex);

		for (int i = 0; i < vertex; i++) {
			visited[i] = false;
			finish[i] = 0;
		}

		fillFinishTimes(vertex, finish, visited);

		Array<int> order(vertex);
		for (int i = 0; i < vertex; i++)
		{
			order[i] = i;
		}

		for (int i = 0; i < vertex - 1; i++)
		{
			for (int j = 0; j < vertex - i - 1; j++)
			{
				if (finish[order[j]] < finish[order[j + 1]])
				{
					int temp = order[j];
					order[j] = order[j + 1];
					order[j + 1] = temp;
				}
			}
		}

		GraphAdjMatrix gt = getTranspose();
		for (int i = 0; i < vertex; i++) visited[i] = false;

		
		for (int i = 0; i < vertex; i++)
		{
			int u = order[i];
			if (!visited[u])
			{
				cout << "SCC: ";
				gt.DFS_Strongly_Helper(u, visited);
			}
		}
	}
	int getIndegree(int u)
	{
		int count = 0;
		int size = grf.getSize();
		for (int i = 0; i < size; i++)
		{
			if (i == u)
			{
				for (int j = 0; j < size; j++)
				{
					if (grf[j][i] != 0)
					{
						count++;
					}
				}
				return count;
			}
		}
	}
	int getOutdegree(int u)
	{
		int count = 0;
		int size = grf.getSize();
		for (int i = 0; i < size; i++)
		{
			if (i == u)
			{
				for (int j = 0; j < size; j++)
				{
					if (grf[i][j] != 0)
					{
						count++;
					}
				}
				return count;
			}
		}
	}
	void listEdges(int start)
	{
       
	}

}; 
#endif