#include <stdio.h>
#include <stdlib.h>
 
struct node{
        enum {black, red} color;
        int info;
        struct  node *lchild;
        struct  node *rchild;
        struct  node *parent;
	};
void insert (int num/*,struct node *root, struct node *sentinel*/);
void insert_balance(struct node *nptr/*, struct node *root,struct node *sentinel*/);
void RotateLeft(struct node *ptr);
void RotateRight(struct node *ptr);
void display(struct node *ptr,int level);
struct node *root;
struct node *sentinel;/*will be parent of root node and replace NULL */

