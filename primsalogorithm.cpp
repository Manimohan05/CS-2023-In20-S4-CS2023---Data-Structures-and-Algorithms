#include <bits/stdc++.h>
using namespace std;

// Function to find the vertex with the minimum key value
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
3 0 0 
    return min_index;
}

// Function to print the MST
void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Function to construct and print MST using Prim's algorithm
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);      // Array to store constructed MST
    vector<int> key(V, INT_MAX);    // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false);   // To represent set of vertices not yet included in MST

    // Starting vertex as the root of MST
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Prim's algorithm to find the MST
    primMST(graph, V);

    return 0;
}
