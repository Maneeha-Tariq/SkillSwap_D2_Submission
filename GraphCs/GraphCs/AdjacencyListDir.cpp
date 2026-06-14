#include <iostream>
#include <vector>
using namespace std;
// Space complexity O(V+E) memory efficient

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

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    int edges;
    cin >> edges;

    // Input directed edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Directed edge
        adj[u].push_back(v);
    }

    printGraph(adj);

    return 0;
}