#include"digi.h"

void dijikstra(int G[][MAX], int n, int startnode)
{
        int cost[MAX][MAX], distance[MAX], pred[MAX];
        int visited[MAX], count, mindistance, nextnode, i,j;
        for(i=0;i < n;i++)
                for(j=0;j < n;j++)
                        if(G[i][j]==0)
                                cost[i][j]=INFINITE;
                        else
                                cost[i][j]=G[i][j];

        for(i=0;i< n;i++)
        {
                distance[i]=cost[startnode][i];
                pred[i]=startnode;
                visited[i]=0;
        }
        distance[startnode]=0;
        cost[i][j]=G[i][j];

        for(i=0;i< n;i++)
        {
                distance[i]=cost[startnode][i];
                pred[i]=startnode;
                visited[i]=0;
        }
        distance[startnode]=0;
        visited[startnode]=1;
        count=1;
        while(count < n-1){
                mindistance=INFINITE;
                for(i=0;i < n;i++)
                        if(distance[i] < mindistance&&!visited[i])
                        {
                                mindistance=distance[i];
                                nextnode=i;
                        }
                visited[nextnode]=1;
                for(i=0;i < n;i++)
                        if(!visited[i])
                                if(mindistance+cost[nextnode][i] < distance[i])
                                {
                                        distance[i]=mindistance+cost[nextnode][i];
                                        pred[i]=nextnode;
                                }
                        	count++;
        }
        for(i=0;i < n;i++)
                if(i!=startnode)
                {
                        printf("\nDistance of %d = %d", i, distance[i]);
                        printf("\nPath = %d", i);
                        j=i;
                        do
                        {
                                j=pred[j];
                                printf(" <-%d", j);
                        }
                        while(j!=startnode);
                }
}

