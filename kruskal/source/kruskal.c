#include"kruskal.h"
/*function create a tree*/
struct edge *create_tree(struct edge *tree, int vertices, struct edge *front)
{
	struct edge *temp;
	int src, dest, root_src, root_dest, list;
	int parent[MAX];
	int i, no =0;
	for(i = 0;i < vertices; i++)
	{
		parent[i] = NIL;
	}
	list = empty_list(front);
	while(!list && no < vertices - 1)
	{
		temp = front;
		front  = front->link;
		src = temp->source;
		dest = temp->desti;
		while(src != NIL)
		{
			root_src = src;
			src = parent[src];
		}
		while(dest != NIL)
		{
			root_dest = dest;
			dest = parent[dest];
		}
		if(root_src != root_dest)
		{
			no++;
			tree[no].source = temp->source;
			tree[no].desti = temp->desti;
			tree[no].weight = temp->weight;
			parent[root_dest] = root_src;
		}
	}
	return tree;
}
/*function to check whether tree is empty or not*/
int empty_list(struct edge *front)
{
	if(front == NULL)
		return 1;
	else
		return 0;
}
/*function to create a linklist*/
struct edge *insert_node(int src, int dest, int wt, struct edge *front)
{
	struct edge *temp, *q;
	temp = (struct edge *)malloc(sizeof(struct edge));
	temp->source = src;
	temp->desti = dest;
	temp->weight = wt;
	if(front == NULL || temp->weight < front->weight)
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		q = front;
		while(q->link != NULL && q->link->weight <= temp->weight)
		{
			q = q->link;
		}
		temp->link = q->link;
		q->link = temp;
		if(q->link == NULL)
		{
			temp->link = NULL;
		}
	}
	return front;
}
/*function to create a graph by adjacency list*/
struct edge *create_graph(int vertices, int no_edge, struct edge *front)
{
	int i, source_vertex, dest_vertex, weight;
	for(i = 0; i < no_edge; i++)
	{
		printf("Edge %d\n",i + 1);
		printf("enter source\t");
		scanf("%d",&source_vertex);
		printf("enter destination\t");
		scanf("%d",&dest_vertex);
		printf("enter weight of edge\n");
		scanf("%d", &weight);
		if(source_vertex != dest_vertex)
			front = insert_node(source_vertex, dest_vertex, weight, front);
	}
	return front;
}
/*function to print the graph*/
void print(struct edge *tree, int vertices)
{
	int i;
	int count = 0;
	for(i = 1; i <= vertices - 1; i++)
	{
		printf("%d->",tree[i].source);
		printf("%d\n",tree[i].desti);
		printf("%d\n",tree[i].weight);

		count = count + tree[i].weight;
	}
	printf("weight of minimum spanning tree=%d\n",count);
}




