#include <stdio.h>
#include <stdbool.h>

int adj[100][100]; 
bool visited[100]; 

void dfs(int node, int totalNodes)
{
  
    visited[node] = true;
    printf("%d ", node);


    for (int i = 0; i < totalNodes; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            dfs(i, totalNodes);
        }
    }
}

int main()
{
    int nodes, edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int n1, n2;

    for (int i = 0; i < edges; ++i)
    {
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    dfs(startNode, nodes);
    printf("\n");

    return 0;
}

