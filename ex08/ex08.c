#include <stdio.h>

#define MAX_VERTICES 20
#define INFINITY 999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src)
{
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    /* Initialize distances and visited array */
    for (int i = 0; i < n; i++)
    {
        distance[i] = INFINITY;
        visited[i] = 0;
    }

    distance[src] = 0;

    /* Dijkstra's algorithm */
    for (int count = 0; count < n - 1; count++)
    {
        int min = INFINITY;
        int u = -1;

        /* Find vertex with minimum distance */
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && distance[v] < min)
            {
                min = distance[v];
                u = v;
            }
        }

        /* If no reachable vertex is found */
        if (u == -1)
            break;

        visited[u] = 1;

        /* Update distances */
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] != INFINITY &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    /* Display result */
    printf("\nVertex\tDistance from Source (%d)\n", src);

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INFINITY)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    if (n <= 0 || n > MAX_VERTICES)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    if (src < 0 || src >= n)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, n, src);

    return 0;
}
