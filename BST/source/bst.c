#include"bst.h"
/*function to insert node in bst*/
struct bst *insert_into_bst(struct bst *root, int val)
{
	struct bst *temp;
	temp = (struct bst *)malloc(sizeof(struct bst));
	/*if root is equal to NULL make temp node as root*/
	if(root == NULL)
	{
		temp->data = val;
		temp->left = temp->right = NULL;
		return temp;
	}
	/*if value inputed is less then the root node insert in left subtree*/
	if(val < root->data)
	{
		root->left = insert_into_bst(root->left, val);
	}
	/*if value inputed is greater than the root node insert in right subtree*/
	else if(val > root->data)
	{
		root->right = insert_into_bst(root->right, val);
	}
	return root;
	free(temp);
}
/*function to search in bst*/
struct bst *search_into_bst(struct bst *root, int val)
{
	struct bst *trev;
	trev=root;
	if(trev == NULL)
	{
		printf("element not found\n");
		return root;
	}
	/*if value to be searched is found then print the value and position where it is found*/
	if(val == trev->data)
	{
		printf("element %d found at position %p\n",root->data,root);
		return root;
	}
	/*if val to be searched is greater than root node search in right subtree*/
	if(val > trev->data)
	{
		search_into_bst(trev->right, val);
	}
	/*if val to be searched is smaller than root node search in left subtree*/
	else if(val < trev->data)
	{
		search_into_bst(trev->left, val);
	}
	return root;
}
/*function to find minimum node in a tree*/
struct bst *find_min(struct bst *root)
{
	if(root == NULL)
		return NULL;
	else if(root->left == NULL)
	{
		printf("minimum element=%d\n",root->data);
		return root;
	}
	else
		find_min(root->left);
}
/*function to find maximum node in a tree*/
struct bst *find_max(struct bst *root)
{
	struct bst *temp;
	temp = root;
	if(temp == NULL)
		return NULL;
	else 
	{
		while(temp->right != NULL)
			temp=temp->right;
		printf("maximum element=%d\n",temp->data);
	}
	return root;
}
/*function to delete a node in a tree*/
struct bst *delete_into_bst(struct bst *root, int val)
{
	struct bst *temp;
	temp =(struct bst *)malloc(sizeof(struct bst));
	/*if root is equal to NULL element not found*/
	if (root == NULL)
	{
		printf("element not found\n");
		return root;
	}
	/*if element is less then root search in left subtree recursively and delete it*/
	else if(val < root->data)
		root->left = delete_into_bst(root->left, val);
	/*if element is greater than root search in right subtree recursively and delete it*/
	else if(val > root->data)
		root->right = delete_into_bst(root->right, val);
	/*if left child and right child both are not equal to NULL,then find minimum node and agian search and delete recursivly*/
	else if(root->left != NULL && root->right != NULL)
	{
		temp=find_min(root->right);
		root->data = temp->data;
		root->right = delete_into_bst(root->right,temp->data);
	}
	else
	{
                temp=root;
               	if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
                free(temp);
		printf("element deleted\n");
        }
        return root;

}
/*function to calculate height of tree*/
int Height_in_bst(struct bst *root)
{
	if(root == NULL)
		return -1;
	else
		return 1 + max(Height_in_bst(root->left), Height_in_bst(root->right));
}
/*function to find maximum between left child and right child*/
int max(int left, int right)
{
	int max_val;
	max_val = left > right ? left : right;
	return max_val;
}
/*function to display in pre_order*/
void display_pre_order(struct bst *root)
{
	if(root != NULL)
	{
	printf("%d->",root->data);
	display_pre_order(root->left);
	display_pre_order(root->right);
	}
	else
		return;

}
/*function to display in post_order*/
void display_post_order(struct bst *root)
{
	if(root == NULL)
		return;
	display_post_order(root->left);
	display_post_order(root->right);
	printf("%d->",root->data);
}
/*function to display in in_order*/
void display_in_order(struct bst *root)
{
	if(root == NULL)
		return;
	display_in_order(root->left);
	printf("%d->",root->data);
	display_in_order(root->right);
}

