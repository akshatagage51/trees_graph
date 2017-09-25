#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define MIN 3

int tree[MAX][MIN];
int cost[MAX][MIN];

int prim(int n);
void display(int n, int minimumcost);

