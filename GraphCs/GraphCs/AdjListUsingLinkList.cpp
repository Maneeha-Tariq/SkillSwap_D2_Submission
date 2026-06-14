#include <iostream>
#include <queue>
using namespace std;

// ================= NODE =================
struct Node {
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = nullptr;
    }
};

// ================= GRAPH =================
class Graph {
    int n;
    Node** adj;

public:

    Graph(int size) {
        n = size;
        adj = new Node * [n];

        for (int i = 0; i < n; i++)
            adj[i] = nullptr;
    }

    void addEdge(int u, int v) {
        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }
    void removeEdge(int u, int v) {

        // ===== remove v from u's list =====
        Node* temp = adj[u];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == v) {
                if (prev == nullptr) {
                    adj[u] = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    int outdegree(int node) {
        int count = 0;

        Node* temp = adj[node];

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
    int indegree(int node) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            Node* temp = adj[i];

            while (temp != nullptr) {
                if (temp->data == node)
                    count++;

                temp = temp->next;
            }
        }

        return count;
    }
    void printList() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";

            Node* temp = adj[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

   
    ~Graph() {
        for (int i = 0; i < n; i++) {
            Node* temp = adj[i];

            while (temp != nullptr) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }

        delete[] adj;
    }
};

// ================= MAIN (same style as yours) =================
int main() {

    int n;
    cin >> n;

    Graph g(n);

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v); // directed graph (same as your matrix version)
    }

    cout << "Adjacency List:\n";
    g.printList();

    
   

    return 0;
}