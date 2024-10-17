#include <stdio.h>
int adj[100][100];

int main()
{
    int node, edge;
    printf("Enter the number of nodes: ");
    scanf("%d", &node);
    printf("Enter the number of edges: ");
    scanf("%d", &edge);

    int n1, n2;

    for (int i = 0; i < edge; ++i)
    {
        scanf("%d %d", &n1, &n2);

        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    int userNode;
    printf("Enter the node to find its connected nodes: ");
    scanf("%d", &userNode);

    printf("Nodes connected to node %d: ", userNode);

    for (int i = 0; i < node; i++)
    {
        if (adj[userNode][i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

