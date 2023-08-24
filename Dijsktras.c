#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int *));

    int i, j;
    printf("Enter cost matrix(use 999 for infinity):\n");
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    int src;
    scanf("%d", &src);

    int dist[n];
    bool visited[n];
    for (i = 0; i < n; i++)
    {
        dist[i] = 999;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = 999, min_index;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i], min_index = i;
            }
        }
        visited[min_index] = true;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && arr[min_index][i] && dist[min_index] != 999 && dist[min_index] + arr[min_index][i] < dist[i])
            {
                dist[i] = dist[min_index] + arr[min_index][i];
            }
        }
    }

    printf("The shortest path from source vertex %d to all other vertices is:\n", src);
    for (i = 0; i < n; i++)
    {
        printf("%d -> %d: %d\n", src, i, dist[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
