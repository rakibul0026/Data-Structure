#include <iostream>
#include <queue>
using namespace std;

int adj[100][100] = {0}; 

void bfs(int node, int start) {
    queue<int> q;
    bool visited[100] = {false}; 
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int j = 0; j < node; j++) {
            if (adj[curr][j] == 1 && !visited[j]) { 
                visited[j] = true; 
                q.push(j); 
            }
        }
    }
}

int main() {
    int node, edge;
    cout << "Enter the number of nodes: ";
    cin >> node;
    cout << "Enter the number of edges: ";
    cin >> edge;

    int n1, n2;

    for (int i = 0; i < edge; ++i) {
        cout << "Enter edge (u v): ";
        cin >> n1 >> n2;
        adj[n1][n2] = 1; 
        adj[n2][n1] = 1;
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << adj[i][j] << "\t";
        }
        cout << "\n";
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS starting from " << startVertex << ":\n";
    bfs(node, startVertex);

    return 0;
}

