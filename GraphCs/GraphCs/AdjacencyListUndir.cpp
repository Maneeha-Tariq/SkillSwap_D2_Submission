#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS
void BFS(vector<vector<int>>& adj, int start)
{
    vector<bool> visited(adj.size(), false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

// DFS Helper
void DFSHelper(vector<vector<int>>& adj, int node, vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            DFSHelper(adj, neighbour, visited);
        }
    }
}

// DFS Function
void DFS(vector<vector<int>>& adj, int start)
{
    vector<bool> visited(adj.size(), false);

    DFSHelper(adj, start, visited);
}

// Print Graph
void printGraph(vector<vector<int>>& adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << " -> ";

        for (int neighbour : adj[i])
        {
            cout << neighbour << " ";
        }

        cout << endl;
    }
}
int indegree(vector<vector<int>>& adj, int node)
{
    int count = 0;

    // Traverse all lists
    for (int i = 0; i < adj.size(); i++)
    {
        for (int neighbour : adj[i])
        {
            if (neighbour == node)
            {
                count++;
            }
        }
    }

    return count;
}

// Calculate Out-degree
int outdegree(vector<vector<int>>& adj, int node)
{
    return adj[node].size();
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printGraph(adj);

    cout << "\nBFS: ";
    BFS(adj, 0);

    cout << "\nDFS: ";
    DFS(adj, 0);
}