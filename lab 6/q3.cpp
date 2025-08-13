#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w; // start, end, weight
};

// Disjoint Set (Union-Find) functions
int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findParent(parent, parent[i]); // path compression
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[E];
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // Initialize Disjoint Set
    int parent[V], rank[V] = {0};
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "\nEdges in Minimum Spanning Tree:\n";
    int mstWeight = 0;
    int edgesInMST = 0;

    for (int i = 0; i < E && edgesInMST < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV) { // no cycle
            cout << u << " -- " << v << " == " << w << "\n";
            mstWeight += w;
            edgesInMST++;
            unionSet(parent, rank, setU, setV);
        }
    }

    cout << "Total weight of MST: " << mstWeight << "\n";

    return 0;
}
