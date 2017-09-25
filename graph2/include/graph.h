#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node *next;
	};
struct graph{
	int numvertex;
	struct node **adj;
	};
struct graph *create_graph(int vertex);
void edge(struct graph *G, int src, int dest);
void print_graph(struct graph *G);
struct node *createnode(int n);
