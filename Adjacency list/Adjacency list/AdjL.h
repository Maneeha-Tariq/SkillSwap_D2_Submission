//DIRECTED

#ifndef ADJL_H
#define ADJL_H

#include "Edge.h"
#include "Array.h"
#include "Queue.h"
#include <iostream>
using namespace std;

enum Color { W, G, B };

class AdjList
{
    Array<Edge*> grp;
    bool directed = true;

    void DFS_TimeHelper(int u,
        Array<bool>& visited,
        Array<int>& start,
        Array<int>& finish,
        int& timer)
    {
        visited[u] = true;
        start[u] = ++timer;

        Edge* temp = grp[u];     // iterate linked list
        while (temp != nullptr)
        {
            int v = temp->vertex;

            if (!visited[v])
                DFS_TimeHelper(v, visited, start, finish, timer);

            temp = temp->next;
        }

        finish[u] = ++timer;
    }

    void DFS_visit(int u, Array<bool>& visited)
    {
        visited[u] = true;

        Edge* temp = grp[u];
        while (temp != nullptr)
        {
            int v = temp->vertex;
            if (!visited[v])
                DFS_visit(v, visited);

            temp = temp->next;
        }
    }

    // ---------- PRIVATE DFS HELPER ----------
    void DFSHelper(int u, Array<bool>& visited)
    {
        cout << u << " ";
        visited[u] = true;

        Edge* temp = grp[u];
        while (temp != nullptr)
        {
            int v = temp->vertex;

            if (!visited[v])
                DFSHelper(v, visited);

            temp = temp->next;
        }
    }

    // ---------- DIRECTED CYCLE HELPER ----------
    bool directedCycleHelper(int u, Array<Color>& color)
    {
        color[u] = G;

        Edge* temp = grp[u];
        while (temp != nullptr)
        {
            int v = temp->vertex;

            if (color[v] == G)
                return true;

            if (color[v] == W)
            {
                if (directedCycleHelper(v, color))
                    return true;
            }

            temp = temp->next;
        }

        color[u] = B;
        return false;
    }

    // ---------- UNDIRECTED CYCLE HELPER ----------
    bool undirectedCycleHelper(int u, Array<bool>& visited, int parent)
    {
        visited[u] = true;

        Edge* temp = grp[u];
        while (temp != nullptr)
        {
            int v = temp->vertex;

            if (!visited[v])
            {
                if (undirectedCycleHelper(v, visited, u))
                    return true;
            }
            else if (v != parent)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

public:

    AdjList(int n, bool direc = true)
    {
        grp.reSize(n);
        for (int i = 0; i < grp.getSize(); i++)
            grp[i] = nullptr;

        directed = direc;
    }

    // ---------- ADD EDGE ----------
    void addEdge(int u, int v, int w = 1)
    {
        if (u >= grp.getSize() || v >= grp.getSize())
            return;

        Edge* e = new Edge(w, v);
        e->next = grp[u];
        grp[u] = e;

        if (!directed)
        {
            Edge* p = new Edge(w, u);
            p->next = grp[v];
            grp[v] = p;
        }
    }

    // ---------- REMOVE EDGE ----------
    void removeEdge(int u, int v)
    {
        Edge* curr = grp[u];
        Edge* prev = nullptr;

        while (curr != nullptr && curr->vertex != v)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
            return;

        if (curr == grp[u])
            grp[u] = curr->next;
        else
            prev->next = curr->next;

        delete curr;

        if (!directed)
        {
            Edge* curr2 = grp[v];
            Edge* prev2 = nullptr;

            while (curr2 != nullptr && curr2->vertex != u)
            {
                prev2 = curr2;
                curr2 = curr2->next;
            }

            if (curr2 == nullptr)
                return;

            if (curr2 == grp[v])
                grp[v] = curr2->next;
            else
                prev2->next = curr2->next;

            delete curr2;
        }
    }

    // ---------- BFS FULL ----------
    void BFS(int start)
    {
        Array<bool> visited(grp.getSize());
        for (int i = 0; i < visited.getSize(); i++)
            visited[i] = false;

        Queue<int> q;
        visited[start] = true;
        q.enQueue(start);

        while (!q.isEmpty())
        {
            int u = q.deQueue();
            cout << u << " ";

            Edge* temp = grp[u];
            while (temp != nullptr)
            {
                int v = temp->vertex;
                if (!visited[v])
                {
                    visited[v] = true;
                    q.enQueue(v);
                }
                temp = temp->next;
            }
        }

        // For disconnected graph
        for (int i = 0; i < visited.getSize(); i++)
        {
            if (!visited[i])
                BFS(i);
        }
    }

    // ---------- DFS FULL ----------
    void DFS(int start)
    {
        Array<bool> visited(grp.getSize());
        for (int i = 0; i < visited.getSize(); i++)
            visited[i] = false;

        DFSHelper(start, visited);

        // For disconnected parts
        for (int i = 0; i < visited.getSize(); i++)
        {
            if (!visited[i])
                DFSHelper(i, visited);
        }
    }

    // ---------- DIRECTED CYCLE ----------
    bool isDirectedCycle(int start)
    {
        Array<Color> color(grp.getSize());
        for (int i = 0; i < color.getSize(); i++)
            color[i] = W;

        return directedCycleHelper(start, color);
    }

    // ---------- UNDIRECTED CYCLE ----------
    bool isUndirectedCycle(int start)
    {
        Array<bool> visited(grp.getSize());
        for (int i = 0; i < visited.getSize(); i++)
            visited[i] = false;

        return undirectedCycleHelper(start, visited, -1);
    }
    AdjList getTranspose()
    {
        AdjList T(grp.getSize(), directed);

        for (int u = 0; u < grp.getSize(); u++)
        {
            Edge* temp = grp[u];

            while (temp != nullptr)
            {
                int v = temp->vertex;

                // reverse edge: u -> v becomes v -> u
                T.addEdge(v, u);

                temp = temp->next;
            }
        }

        return T;
    }

    // ---------- PRINT GRAPH ----------
    void print()
    {
        for (int i = 0; i < grp.getSize(); i++)
        {
            cout << i << " -> ";
            Edge* temp = grp[i];
            while (temp != nullptr)
            {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    bool isStronglyConnected()
    {
        int n = grp.getSize();

        // -------- Step 1: DFS on original graph --------
        Array<bool> visited(n);
        for (int i = 0; i < n; i++)
            visited[i] = false;
        DFS_visit(0, visited);

        // If any vertex NOT visited => not strongly connected
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;

        // -------- Step 2: Build transpose graph --------
        AdjList T = getTranspose();

        // -------- Step 3: DFS on transpose graph --------
        for (int i = 0; i < n; i++)
            visited[i] = false;

        T.DFS_visit(0, visited);

        // If any vertex not visited in transpose not strongly connected
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;

        // Otherwise strongly connected
        return true;
    }
    void DFS_with_Timestamps()
    {
        int n = grp.getSize();

        Array<bool> visited(n);
        Array<int> start(n);
        Array<int> finish(n);

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            start[i] = 0;
            finish[i] = 0;
        }

        int timer = 0;

        // Handle disconnected graph
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                DFS_TimeHelper(i, visited, start, finish, timer);
        }

        cout << "\nVertex | Start | Finish\n";
        cout << "-------------------------\n";
        for (int i = 0; i < n; i++)
        {
            cout << "  " << i << "     |   "
                << start[i] << "    |   " << finish[i] << "\n";
        }
    }

};

#endif