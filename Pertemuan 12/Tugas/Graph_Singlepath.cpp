#include <iostream>
using namespace std;

const int INF = 99999;
const int N = 5;

int graph[N][N];
int parent[N];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = (i == j) ? 0 : INF;
}

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
}

void dijkstra(int src, int dest) {
    int dist[N];
    bool visited[N];
    
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < N - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    cout << "Shortest distance from node " << src + 1 << " to node " << dest + 1 << " = " << dist[dest] << endl;
    cout << "Path: ";
    
    int path[N];
    int count = 0;
    int curr = dest;
    while (curr != -1) {
        path[count++] = curr;
        curr = parent[curr];
    }
    
    for (int i = count - 1; i >= 0; i--) {
        cout << path[i] + 1;
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    init();
    addEdge(0, 1, 2);
    addEdge(1, 2, 3);
    addEdge(2, 4, 5);
    
    dijkstra(0, 4);
    return 0;
}
