#include"prim.h"

int prim(int n)
{
	int i, j, startVertex, endVertex;
   	int k, nr[10], temp,minimumcost=0;

   /* For first smallest edge */
	temp = cost[0][0];
   	for (i = 0; i < n; i++)
	{
      		for (j = 0; j < n; j++)
		{
			if (temp > cost[i][j])
			{
            			temp = cost[i][j];
            			startVertex = i;
            			endVertex = j;
         		}
      		}
   	}
   /* Now we have fist smallest edge in graph */
	tree[0][0] = startVertex;
	tree[0][1] = endVertex;
	tree[0][2] = temp;
	minimumcost = temp;

   /* Now we have to find min dis of each vertex from either
    startVertex or endVertex by initialising nr[] array
    */

	for (i = 0; i < n; i++)
	{
		if (cost[i][startVertex] < cost[i][endVertex])
         		nr[i] = startVertex;
      		else
         		nr[i] = endVertex;
   	}

   /* To indicate visited vertex initialise nr[] for them to 100 */
	nr[startVertex] = 100;
	nr[endVertex] = 100;

   /* Now find out remaining n-2 edges */
	temp = 99;
	for (i = 1; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (nr[j] != 100 && cost[j][nr[j]] < temp)
			{
            			temp = cost[j][nr[j]];
            			k = j;
         		}
      		}
	}
      /* Now i have got next vertex */
	tree[i][0] = k;
	tree[i][1] = nr[k];
	tree[i][2] = cost[k][nr[k]];
	minimumcost = minimumcost + cost[k][nr[k]];
	nr[k] = 100;

      /* Now find if k is nearest to any vertex
       than its previous near value */


	for (j = 0; j < n; j++)
	{
		if (nr[j] != 100 && cost[j][nr[j]] > cost[j][k])
            	nr[j] = k;
      	}
      	temp = 99;
printf("\nThe min spanning tree is:- ");
        for (i = 0; i < n - 1; i++)
        {
                for (j = 0; j < 3; j++)
                        printf("%d", tree[i][j]);
                printf("\n");
        }
        printf("\nMin cost : %d", minimumcost);


	return minimumcost;
}

void display(int n,int minimumcost)
{
	int i,j;
	printf("\nThe min spanning tree is:- ");
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d", tree[i][j]);
      		printf("\n");
   	}
	printf("\nMin cost : %d", minimumcost);
}

