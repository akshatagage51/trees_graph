#include"graph.h"
int main()
{
	struct graph *G;
	int sw, v, src, dest;
	while(1)
	{
		printf("\n1.create graph\n2.add edges\n3.print graph\n0.exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("enter no of vertex for graph\n");
				scanf("%d",&v);
				G = create_graph(v);
				break;
			case 2:
				printf("enter source and destination of an edge\n");
				scanf("%d%d",&src,&dest);
				edge(G,src,dest);
				break;
			case 3:
				print_graph(G);
				break;
			case 0:
				exit(0);
		}
	}
}
