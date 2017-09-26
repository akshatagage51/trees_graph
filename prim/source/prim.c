#include"prim.h"

int prim(int n)
{
	int i, j, startVertex, endVertex;
   	int k, arr[10], temp,minimumcost=0;

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
    startVertex or endVertex by initialising arr[] array
    */

	for (i = 0; i < n; i++)
	{
		if (cost[i][startVertex] < cost[i][endVertex])
         		arr[i] = startVertex;
      		else
         		arr[i] = endVertex;
   	}

   /* To indicate visited vertex initialise arr[] for them to 100 */
	arr[startVertex] = 100;
	arr[endVertex] = 100;

   /* Now find out remaining n-2 edges */
	temp = 99;
	for (i = 1; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[j] != 100 && cost[j][arr[j]] < temp)
			{
            			temp = cost[j][arr[j]];
            			k = j;
         		}
      		}
	}
      /* Now i have got next vertex */
	tree[i][0] = k;
	tree[i][1] = arr[k];
	tree[i][2] = cost[k][arr[k]];
	minimumcost = minimumcost + cost[k][arr[k]];
	arr[k] = 100;

      /* Now find if k is nearest to any vertex
       than its previous near value */


	for (j = 0; j < n; j++)
	{
		if (arr[j] != 100 && cost[j][arr[j]] > cost[j][k])
            	arr[j] = k;
      	}
      	temp = 99;
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

