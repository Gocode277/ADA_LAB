#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    int adj[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    bool visited[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printf("Enter the starting vertex: ");
    int start;
    scanf("%d", &start);
    visited[start] = true;

    printf("\nThe minimal spanning tree is:\nEdge : Weight\n");
    int cost = 0;
    for (k = 0; k < n - 1; k++)
    {
        int min = 999;
        int u = 0;
        int v = 0;
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && adj[i][j] && min > adj[i][j])
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", u, v, adj[u][v]);
        cost += adj[u][v];
        visited[v] = true;
    }
    printf("The cost of the minimal spanning tree is: %d\n", cost);
}