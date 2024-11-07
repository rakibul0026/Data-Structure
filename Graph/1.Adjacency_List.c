/*
  Adjacency list
 time
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100]; 

int main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1); 
    }

    for (int i = 0; i < node; i++)
    {
        cout << "Node " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

