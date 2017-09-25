#include<stdio.h>
#include<stdlib.h> 

struct node{
    int data;
    struct node *left,*right;
    int ht;
	};

struct node *insert(struct node *T, int x);
struct node *delete_node(struct node *T, int x);
int height(struct node *T);
struct node *rotateright(struct node *x);
struct node *rotateleft(struct node *x);
struct node *RR(struct node *T);
struct node *LL(struct node *T);
struct node * LR(struct node *T);
struct node * RL(struct node *T);
int BF(struct node *T);
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);

