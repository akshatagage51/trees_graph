#include<stdio.h>
#include<stdlib.h>
#define NIL -1
#define MAX 100

struct edge{
	int source;
	int desti;
	int weight;
	struct edge *link;
	};


struct edge *create_tree(struct edge *tree, int vertices, struct edge *front);
int empty_list(struct edge *front);
struct edge *insert_node(int src, int dest, int wt, struct edge *front);
struct edge *create_graph(int vertices, int no_edge, struct edge *front);
void print(struct edge *tree, int vertices);
