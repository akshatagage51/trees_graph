#include"prim.h"
void main()
{
	int i,j,sw,n,minimumcost;
	while(1)
	{
		printf("\n1.insert\n2.display\n0.exit");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("\nEnter the no of vertices:");
				scanf("%d",&n);
				printf("\nEnter the costs of edges in matrix form :");
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						scanf("%d",&cost[i][j]);
					}
				}
				printf("\nThe matrix is :");
				for(i=0;i<n;i++)
 				{
  					for(j=0;j<n;j++)
					{
						printf("%d\t",cost[i][j]);
					}
					printf("\n");
	 			}
				minimumcost=prim(n);
				break;
			case 2:
				display(n,minimumcost);
				break;
			case 0:
				exit(0);
		}
	}
}
