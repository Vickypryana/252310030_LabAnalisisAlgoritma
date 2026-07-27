#include <iostream>
using namespace std;

const int INF = 99999;
const int N = 7;

string nama[N] = {"Cibinong", "Cileuteut", "Tanah Sereal", "Bogor Tengah", "Tajur", "Bogor Utara", "Baranangsiang"};
int graph[N][N];

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
    int parent[N];
    
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
    
    cout << "Jarak terpendek dari " << nama[src] << " ke " << nama[dest] << " = " << dist[dest] << endl;
    
    if (dist[dest] != INF) {
        cout << "Jalur: ";
        int path[N];
        int count = 0;
        int curr = dest;
        while (curr != -1) {
            path[count++] = curr;
            curr = parent[curr];
        }
        for (int i = count - 1; i >= 0; i--) {
            cout << nama[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
}

int main() {
    init();
    addEdge(0, 1, 5);
    addEdge(0, 5, 3);
    addEdge(1, 2, 4);
    addEdge(2, 3, 6);
    addEdge(3, 4, 2);
    addEdge(5, 6, 4);
    addEdge(6, 4, 3);
    
    dijkstra(0, 4);
    return 0;
}
