#include"digi.h"

void main()
{
        int G[MAX][MAX], i, j, n, u;

        printf("\nEnter the no. of vertices:: ");
        scanf("%d", &n);
        printf("\nEnter the adjacency matrix::\n");
        for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                        scanf("%d", &G[i][j]);
        printf("\nEnter the starting node:: ");
        scanf("%d", &u);
        dijikstra(G,n,u);
}
