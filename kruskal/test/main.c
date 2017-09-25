#include"kruskal.h"

int main()
{
	struct edge *front = NULL;
	struct edge tree[MAX];
	struct edge *tree_add = NULL;
	int sw, count, vertices, max_edge, no_edge;
	int tree_weight = 0;
	while(1)
	{
		printf("\n1.create a tree\n2.print minimum spaning tree\n0.to exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("enter no of vertices\n");
				scanf("%d",&vertices);
				max_edge = vertices * (vertices - 1)/2;
				printf("no of edges you want to enter\n");
				scanf("%d",&no_edge);
				if(no_edge <= max_edge)
					front = create_graph(vertices, no_edge, front);
				else
					printf("invalid no of edges\n");
				tree_add = create_tree(tree, vertices, front);
				break;
			case 2:
				printf("edges of tree\n");
				print(tree_add,vertices);
				break;
			case 0:
				exit(0);
		}
	}
}
