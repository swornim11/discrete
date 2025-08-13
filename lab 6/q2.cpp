#include <iostream>
#include <climits>
using namespace std;

#define V 10 

int main() {
    int n, graph[V][V];
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[V], visited[V] = {0};

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << dist[i] << "\n";

    return 0;
}

