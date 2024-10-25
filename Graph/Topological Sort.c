#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj(100);
vector<bool> visited(100, false);
stack<int> topoSort;          

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    topoSort.push(node); 
}

int main() {
    int node, edge;
    cout << "Enter the number of nodes: ";
    cin >> node;
    cout << "Enter the number of edges: ";
    cin >> edge;

    int n1, n2;
    cout << "Enter directed edges (from -> to):\n";
    for (int i = 0; i < edge; ++i) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2); 
    }

    
    for (int i = 0; i < node; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << "Topological Sort Order: ";
    while (!topoSort.empty()) {
        cout << topoSort.top() << " ";
        topoSort.pop();
    }
    cout << endl;

    return 0;
}
