#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;		/*variavble to store data in the node*/
	struct bst *left;	/*pointer to left child of parent node*/
	struct bst *right;	/*pointer to right child of parent node*/
	};
/*function to insert  data in tree
 *this function takes two inputs 
 *first is the pointer to the root of tree
 *second the value to be inserted in a tree
 */
struct bst *insert_into_bst(struct bst *root, int val);
/*function to search a particular node in tree*/
struct bst *search_into_bst(struct bst *root, int val);
/*function to delete a particular node in tree
 *this function deletes the node which user enters and 
 *then arrange the tree as per bst property
 */

struct bst *delete_into_bst(struct bst *root, int val);
/*function to find minimum node in tree*/
struct bst *find_min(struct bst *root);
/*function to find maximum node in tree*/
struct bst *find_max(struct bst *root);
/*function to find height in bst*/
int Height_in_bst(struct bst *root);
/*function to find maximum between left and right parent child*/
int max(int left, int right);
/*function to display the tree in pre order
 *pre order prints 
 *1.root node
 *2.left child
 *3.right child
 */
void display_pre_order(struct bst *root);
/*function to display the node in post order
 *post order prints 
 *1.left child
 *2.root node
 *3.right child
 */
void display_post_order(struct bst *root);
/*function to display the node in in order
 *in order prints
 *1.left child
 *2.right child
 *3.root node
 */
void display_in_order(struct bst *root);

