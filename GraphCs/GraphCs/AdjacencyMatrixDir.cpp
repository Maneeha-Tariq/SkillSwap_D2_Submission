#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Space complexity O(V^2)

// Print Matrix
void printMatrix(vector<vector<int>>& adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

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

        // Traverse row of matrix
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// DFS Helper
void DFSHelper(vector<vector<int>>& adj, int node, vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    // Traverse row of matrix
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            DFSHelper(adj, i, visited);
        }
    }
}

// DFS Wrapper
void DFS(vector<vector<int>>& adj, int start)
{
    vector<bool> visited(adj.size(), false);

    DFSHelper(adj, start, visited);
}
// Function to calculate indegree
int indegree(vector<vector<int>>& adj, int node)
{
    int count = 0;

    // Traverse column of node
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i][node] == 1)
        {
            count++;
        }
    }

    return count;
}
int outdegree(vector<vector<int>>& adj, int node)
{
    int count = 0;

    // Traverse row of node
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[node][i] == 1)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;

    // Matrix initialized with 0
    vector<vector<int>> adj(n, vector<int>(n, 0));

    int edges;
    cin >> edges;

    // Directed graph input
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
    }

    cout << "Adjacency Matrix:\n";
    printMatrix(adj);

    cout << "\nBFS Traversal: ";
    BFS(adj, 0);

    cout << "\nDFS Traversal: ";
    DFS(adj, 0);

    return 0;
}