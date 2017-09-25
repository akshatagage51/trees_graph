#include"graph.h"
struct node *createnode(int n)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->vertex = n;
	newnode->next = NULL;
	return newnode;
}

struct graph *create_graph(int vertex)
{
	struct graph *G;
	G = (struct graph *)malloc(sizeof(struct graph));
	G->numvertex = vertex;
	G->adj = (struct node **)malloc(vertex * sizeof(struct node *));
	int i;
	for(i=0; i<vertex; i++)
		G->adj[i] = NULL;
	return G;
}

void edge(struct graph *G, int src, int dest)
{
	struct node *newnode;
	//edge from destination to source
	newnode = createnode(dest);
	newnode->next = G->adj[src];
	G->adj[src] = newnode;
	//edge from source to destination
	newnode = createnode(src);
	newnode->next = G->adj[dest];
	G->adj[dest] = newnode;
}
void print_graph(struct graph *G)
{
	int i,degree;
	for(i = 0; i < G->numvertex; i++)
	{
		degree = 0;
		struct node *temp;
		temp = G->adj[i];
		printf("\nadjacency list of vertex %d\n",i);
		while(temp)
		{
			printf("%d->",temp->vertex);
			temp = temp->next;
			degree++;
		}
		printf("\ndegree of vertex %d is %d\n",i,degree);
		printf("\n");
	}
}
