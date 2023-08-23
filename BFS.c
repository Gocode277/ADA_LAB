#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    int i, j;
    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        adjMatrix[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    int src;
    scanf("%d", &src);

    printf("Breadth First Traversal is as (starting from vertex %d):\n", src);
    bool visited[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int queue[n];
    int front = 0, rear = 0;

    visited[src] = true;
    queue[rear++] = src;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int adjacent = 0; adjacent < n; adjacent++)
        {
            if (adjMatrix[currentVertex][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}
