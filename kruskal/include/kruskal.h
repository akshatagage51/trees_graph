#include<stdio.h>
#include<stdlib.h>
#define NIL -1
#define MAX 100

struct edge{
	int source;	/*variable to store source vertex*/
	int desti;	/*variable to store destination vertex*/
	int weight;	/*variable to store weight of edges*/
	struct edge *link;/*pointer to structure edge*/
	};

/*function to takes pointer to the tree no of vertices and pointer to the root node*/
struct edge *create_tree(struct edge *tree, int vertices, struct edge *front);

/*function empty_list is used to check whether the link list is empty or not*/
int empty_list(struct edge *front);

/*function insert_node is used to create a linklist*/
struct edge *insert_node(int src, int dest, int wt, struct edge *front);

/*function create graph is used to create graph by inputting source vertex,destination vertex,weight of a edge and pointer to root node*/
struct edge *create_graph(int vertices, int no_edge, struct edge *front);

/*function print is used to print the minimal spaning tree*/
void print(struct edge *tree, int vertices);
