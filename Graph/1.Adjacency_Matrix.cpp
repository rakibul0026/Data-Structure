/*adjacency matrix like ->   0  1   1  0  0
                             1  0   1  1  1
                             1  1   0  0  0
                             0  1   0  0  1
                             0  1   0  1  0
                input->
                5 6
                0 1
                2 0
                2 1
                1 3
                3 4
                1 4

       Time Complexity=O(node²) 
    */
#include <bits/stdc++.h>
using namespace std;
int adj[100][100];
int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
                



