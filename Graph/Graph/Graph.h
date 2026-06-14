#ifndef GRAPH_H
#define GRAPH_H
#include "Queue.h"
#include "Array.h"
#include<iostream>
using namespace std;
enum Color{W,B,G};
class Graph
{
	Array<Array<int>> grp;
	bool directed;
	bool isValidIndex(int v)
	{
		return v >= 0 && v < grp.getSize();
	}
	void DFSHelper(int startV, Array<bool>& visit)
	{
		cout << startV << " ";
		visit[startV] = true;

		for (int v = 0; v < grp.getSize(); v++)
		{
			if (isEdge(startV, v) && !visit[v])
			{
				DFSHelper(v, visit);
			}
		}

	}
	bool cycleHelper(int startV, Array<Color>& color)
	{

		color[startV] = G;

		for (int v = 0; v < grp.getSize(); v++)
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

		for (int v = 0; v < grp.getSize(); v++)
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
	void BFSHelper(int startV, Array<bool>& visit)
	{
		Queue<int> q;
		visit[startV] = true;
		q.enQueue(startV);
		while (!q.isEmpty())
		{
			int u = q.deQueue();
			cout << u << " ";
			for (int v = 0; v < grp.getSize(); v++)
			{
				if (isEdge(u, v) && !visit[v])
				{
					visit[v] = true;
					q.enQueue(v);
				}
			}
		}
	}
	void DFS_Time(int u, Array<bool>& visited,
		Array<int>& d, Array<int>& f, int& timeCounter)
	{
		visited[u] = true;
		d[u] = ++timeCounter;

		for (int v = 0; v < grp.getSize(); v++)
		{
			if (grp[u][v] != 0 && !visited[v])
			{
				DFS_Time(v, visited, d, f, timeCounter);
			}
		}

		f[u] = ++timeCounter;
	}
	bool cycleUsingTimestampsFrom(int u, Array<bool>& visited, Array<int>& d, Array<int>& f, int& timeCounter)
	{
		visited[u] = true;
		d[u] = ++timeCounter;

		for (int v = 0; v < grp.getSize(); v++)
		{
			if (isEdge(u, v))
			{
				if (!visited[v])
				{
					if (cycleUsingTimestampsFrom(v, visited, d, f, timeCounter))
						return true;
				}
				else if (f[v] == 0)  
				{
					return true;
				}
			}
		}

		f[u] = ++timeCounter;
		return false;
	}
	void DFS_Util(int u, Array<bool>& visited)
	{
		visited[u] = true;
		for (int v = 0; v < grp.getSize(); v++)
		{
			if (grp[u][v] != 0 && !visited[v]) 
			{
				DFS_Util(v, visited);
			}
		}
	}
	void fillFinishTimes(int vertex, Array<int>& finish, Array<bool>& visited)
	{
		int timer = 0;
		for (int i = 0; i < vertex; i++)
		{
			if (!visited[i]) {
				DFS_Time(i, visited, finish, finish, timer);  // use DFS_Time
			}
		}
	}
	void DFS_SpanningTree_Helper(int u, Array<bool>& visited, Graph& tree)
	{
		visited[u] = true;

		for (int v = 0; v < grp.getSize(); v++)
		{
			if (isEdge(u, v) && !visited[v])
			{
				tree.addEdge(u, v);   // add TREE EDGE
				DFS_SpanningTree_Helper(v, visited, tree);
			}
		}
	}

public:

	Graph(int v, bool dir = true) : directed(dir)
	{
		grp.reSize(v);
		for (int i = 0; i < grp.getSize(); i++)
		{
			grp[i].reSize(v);
		}
		for (int i = 0; i < grp.getSize(); i++)
		{
			for (int j = 0; j < grp[i].getSize(); j++)
			{
				grp[i][j] = 0;
			}
		}
	}
	void addEdge(int u, int v, int wt = 1)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			grp[u][v] = wt;
			if (!directed)
			{
				grp[v][u] = wt;
			}
		}
	}
	void removeEdge(int u, int v)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			grp[u][v] = 0;
			if (!directed)
			{
				grp[v][u] = 0;
			}
		}
	}
	bool isEdge(int u, int v)
	{
		if (isValidIndex(u) && isValidIndex(v))
		{
			if (grp[u][v] == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	void display()
	{
		for (int i = 0; i < grp.getSize(); i++)
		{
			for (int j = 0; j < grp[i].getSize(); j++)
				cout << grp[i][j] << " ";
			cout << endl;
		}
	}

	void BFS(int startVertex)
	{
		Queue<int> q;
		Array<bool> visited(grp.getSize());
		for (int i = 0; i < grp.getSize(); i++)
		{
			visited[i] = false;
		}
		if (isValidIndex(startVertex) && !visited[startVertex])
		{
			BFSHelper(startVertex, visited);
		}
		for (int i = 0; i < grp.getSize(); i++)
		{
			if (!visited[i])
			{
				BFSHelper(i, visited);
			}
		}
	}
	void DFS(int startVertex)
	{
		int size = grp.getSize();
		Array<bool> visited(size);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		if (isValidIndex(startVertex) && !visited[startVertex])
		{
			DFSHelper(startVertex, visited);
		}
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				DFSHelper(i, visited);
			}
		}

	}
	bool isCycle(int startVertex)
	{
		Array<Color> c(grp.getSize());

		for (int i = 0; i < grp.getSize(); i++)
			c[i] = W;

		if (isValidIndex(startVertex) && c[startVertex] == W)
		{
			if (cycleHelper(startVertex, c))
				return true;
		}

		for (int i = 0; i < grp.getSize(); i++)
		{
			if (c[i] == W)
			{
				if (cycleHelper(i, c))
					return true;
			}
		}

		return false;
	}


	bool isUndirCycle(int startVertex)
	{
		int size = grp.getSize();
		Array<bool> visited(size);

		for (int i = 0; i < size; i++)
			visited[i] = false;

		if (isValidIndex(startVertex) && !visited[startVertex])
		{
			if (isUndirCycHelper(startVertex, visited, -1))
				return true;
		}

		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				if (isUndirCycHelper(i, visited, -1))
					return true;
			}
		}
		return false;
	}

	void DFS_with_Time()
	{
		int n = grp.getSize();

		Array<bool> visited(n);
		Array<int> startTime(n);
		Array<int> endTime(n);

		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
			startTime[i] = 0;
			endTime[i] = 0;
		}

		int timeCounter = 0;  // LOCAL variable

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				DFS_Time(i, visited, startTime, endTime, timeCounter);
			}
		}

		cout << "Vertex  |  Discovery  |  Finish\n";
		for (int i = 0; i < n; i++)
		{
			cout << "   " << i << "     |     "
				<< startTime[i] << "       |    " << endTime[i] << "\n";
		}
	}
	

	bool isCycleUsingTimestamps(int startVertex)
	{
		int n = grp.getSize();
		Array<bool> visited(n);
		Array<int> d(n), f(n);

		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
			d[i] = f[i] = 0;
		}

		int timeCounter = 0;

		if (isValidIndex(startVertex) && !visited[startVertex])
			if (cycleUsingTimestampsFrom(startVertex, visited, d, f, timeCounter))
				return true;

		for (int i = 0; i < n; i++)
			if (!visited[i])
				if (cycleUsingTimestampsFrom(i, visited, d, f, timeCounter))
					return true;

		return false;
	}
	Graph getTranspose() 
	{
		int vertex = grp.getSize();
		Graph gt(vertex, directed);  
		for (int i = 0; i < vertex; i++)
		{
			for (int j = 0; j < vertex; j++)
			{
				if (grp[i][j] != 0)
					gt.addEdge(j, i, grp[i][j]);
			}
		}
		return gt;
	}
	int countUndirConnectedComponents() 
	{
		int vertex = grp.getSize();
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
	
	// 2️⃣ Function to count SCCs
	int countSCC() 
	{
		int vertex = grp.getSize();
		Array<bool> visited(vertex);
		Array<int> finish(vertex);

		for (int i = 0; i < vertex; i++) {
			visited[i] = false;
			finish[i] = 0;
		}

		fillFinishTimes(vertex,finish, visited);

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

		// Second DFS on transpose
		Graph gt = getTranspose();
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
	Array<Array<int>> getSpanningTree_Prims()
	{
		int V = grp.getSize();

		Array<bool> inMST(V);
		Array<int> key(V);
		Array<int> parent(V);

		for (int i = 0; i < V; i++)
		{
			inMST[i] = false;
			key[i] = INT_MAX;
			parent[i] = -1;
		}

		key[0] = 0;  // Start from vertex 0

		for (int count = 0; count < V - 1; count++)
		{
			// Pick vertex with minimum key not in MST
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

			// Update keys for adjacent vertices
			for (int v = 0; v < V; v++)
			{
				int wt = grp[u][v];  // weight of edge u-v
				if (wt != 0 && !inMST[v] && wt < key[v])
				{
					key[v] = wt;
					parent[v] = u;
				}
			}
		}

		// Build MST (store edges)
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
	Graph getSpanningTree(int startVertex)
	{
		int n = grp.getSize();

		Graph tree(n, false);   // spanning tree is undirected

		Array<bool> visited(n);
		for (int i = 0; i < n; i++)
			visited[i] = false;

		DFS_SpanningTree_Helper(startVertex, visited, tree);

		return tree;
	}
	
};
#endif





/*void fillFinish(int vertex, Stack<int>& finish, Array<bool>& visited)
	{
		for (int i = 0; i < vertex; i++)
		{
			if (!visited[i])
			{
				finish.push(i);
				DFS_Util(i, visited);
			}
		}
	}*/
	/*int countSCC()
	{
		Stack<int> sk;
		int size = grf.getSize();
		Array<bool>visited(size);
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				fillFinish(i,sk,visited);
			}
		}
		GraphAdjMatrix gt = getTranspose();
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		int count = 0;
		while (!sk.isEmpty())
		{
			int u = sk.pop();
			if (!visited[u])
			{
				count++;
				gt.DFS_Util(u, visited);
			}
		}
		return count;
	}*/

	


























//void BFS_Tree(int startVertex)
//{
//	Queue<int> q;
//	Array<bool> visited(grp.getSize());
//	Array<int> parent(grp.getSize());
//
//	for (int i = 0; i < grp.getSize(); i++)
//	{
//		visited[i] = false;
//		parent[i] = -1;
//	}
//
//	visited[startVertex] = true;
//	q.enQueue(startVertex);
//
//	while (!q.isEmpty())
//	{
//		int u = q.deQueue();
//
//		for (int v = 0; v < grp.getSize(); v++)
//		{
//			if (isEdge(u, v) && !visited[v])
//			{
//				visited[v] = true;
//				parent[v] = u;   // ⭐ THIS creates the tree
//				q.enQueue(v);
//			}
//		}
//	}
//
//	// Print Tree (parent-child)
//	cout << "\nBFS Tree:\n";
//	for (int i = 0; i < grp.getSize(); i++)
//	{
//		if (parent[i] != -1)
//			cout << parent[i] << " -> " << i << endl;
//	}
//}
  

//void BFS_Tree_Using_Stack(int startVertex)
//{
//	Queue<int> q;
//	Stack<int> st;
//
//	Array<bool> visited(grp.getSize());
//	Array<int> parent(grp.getSize());
//
//	for (int i = 0; i < grp.getSize(); i++)
//	{
//		visited[i] = false;
//		parent[i] = -1;
//	}
//
//	// Start BFS
//	visited[startVertex] = true;
//	q.enQueue(startVertex);
//
//	while (!q.isEmpty())
//	{
//		int u = q.deQueue();
//
//		// Store BFS order in stack
//		st.push(u);
//
//		for (int v = 0; v < grp.getSize(); v++)
//		{
//			if (isEdge(u, v) && !visited[v])
//			{
//				visited[v] = true;
//				parent[v] = u;      // forms tree
//				q.enQueue(v);
//			}
//		}
//	}
//
//	// ✅ Now printing the BFS Tree using STACK
//	cout << "\nTree (using Stack, reverse BFS order):\n";
//
//	while (!st.isEmpty())
//	{
//		int node = st.pop();
//
//		if (parent[node] != -1)
//			cout << parent[node] << " -> " << node << endl;
//		else
//			cout << node << " is Root" << endl;
//	}
//}

