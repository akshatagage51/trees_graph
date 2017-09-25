#include <stdio.h>
#include <stdlib.h>
 
struct node{
        enum {black, red} color; /*node can be red or black*/
        int info;		/*data inserted is stored in info*/
        struct  node *lchild;	/*pointer to left child*/
        struct  node *rchild;	/*pointer to right child*/
        struct  node *parent;	/*pointer to parent node*/
	};

struct node *root;	/*pointer to structure node*/
struct node *sentinel;	/*pointer to structure node & will be parent of root node and replace NULL */


/*function insert is used to insert a node in red_black tree
 *it takes the value to be inserted in red_black tree
 */ 
void insert (int num);
/*function insert_balcnce is used when we insert a node and it voilates the red_black tree property
 *then this function balances the tree
 */
void insert_balance(struct node *nptr);
/*This function is used to rotateleft*/
void RotateLeft(struct node *ptr);
/*This function is used to rotateright*/
void RotateRight(struct node *ptr);
/*display function to display the red_black tree*/
void display(struct node *ptr,int level);

