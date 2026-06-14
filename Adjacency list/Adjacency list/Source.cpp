#include "Adjacency_List_Undir.h"
#include "AdjacencyList.h"
#include "Edge.h"
#include <iostream>
using namespace std;

int main()
{
    // Create a graph with 4 vertices
    Adjacency_List_Undir g(4);

    // Test 1: Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

   cout<<  g.undirectCycle(0);

    //cout << "Graph after adding edges:\n";
    //g.display();
    //cout << "\n";

    //// Test 2: Check edges
    //cout << "Edge 0->1 exists? " << (g.isEdge(0, 1) ? "Yes" : "No") << endl;
    //cout << "Edge 0->2 exists? " << (g.isEdge(0, 2) ? "Yes" : "No") << endl;
    //cout << "Edge 1->3 exists? " << (g.isEdge(1, 3) ? "Yes" : "No") << endl;
    //cout << "Edge 2->3 exists? " << (g.isEdge(2, 3) ? "Yes" : "No") << endl;

    //// Test 3: Remove edge
    //g.removeEdge(0, 1);
    //cout << "\nGraph after removing edge 0->1:\n";
    //g.display();
    //cout << "Edge 0->1 exists? " << (g.isEdge(0, 1) ? "Yes" : "No") << endl;
    //cout << "Edge 1->0 exists? " << (g.isEdge(1, 0) ? "Yes" : "No") << endl;

    //// Test 4: Remove non-existent edge
    //g.removeEdge(1, 3);  // should do nothing
    //cout << "\nGraph after trying to remove edge 1->3 (non-existent):\n";
    //g.display();

    //// Test 5: Add another edge
    //g.addEdge(3, 0);
    //cout << "\nGraph after adding edge 3->0:\n";
    //g.display();
    //cout << "Edge 3->0 exists? " << (g.isEdge(3, 0) ? "Yes" : "No") << endl;

    return 0;
}
