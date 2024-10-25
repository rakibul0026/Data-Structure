#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    queue<int> pq;
    int cnt = 0;

    cout << "Enter directed edges (from -> to):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(i);
        }
    }

    cout << "Topological Sort Order: ";
    while (!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        cnt++;

        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                pq.push(it);
            }
        }
    }

    if (cnt != n)
    {
        cout << "\nCycle detected! Topological sort not possible.\n";
    }
    else
    {
        cout << endl;
    }

    return 0;
}

