#include"avl.h"
/*function to insert node in avl tree*/
struct node *insert(struct node *T, int x)
{
	/*if node is NULL then create the node which was inserted*/
	if(T==NULL)
    	{
        	T=(struct node*)malloc(sizeof(struct node));
        	T->data=x;
        	T->left=NULL;
        	T->right=NULL;
    	}
	else
		/*if data is greater then parent node insert in right subtree*/
        	if(x > T->data)
        	{
            		T->right=insert(T->right,x);
			/*checks if inserted node voilates avl property or not*/
            		if(BF(T)==-2)
                		if(x>T->right->data)
                    			T=RR(T);
                		else
                    			T=RL(T);
        	}
        	else
			/*if data is smaller than parent node insert in left subtree*/
            		if(x<T->data)
            		{
                		T->left=insert(T->left,x);
				/*checks if inserted node voilates avl property or not*/
                		if(BF(T)==2)
                    			if(x < T->left->data)
                        			T=LL(T);
					else
                                                T=LR(T);

        		}
			/*update the height of that particular node*/
        		T->ht=height(T);

        return T;
}
/*function to delete_node from avl tree*/
struct node *delete_node(struct node*T, int x)
{
	struct node *p;
	if(T==NULL)
    	{
		printf("nothing to delete\n");
        	return NULL;
    	}
    	else
		/*if entered data is greater than the parent node it will search the data in right subtree and will delete it*/
        	if(x > T->data)
        	{
            		T->right=delete_node(T->right,x);
            		if(BF(T)==2)
                		if(BF(T->left)>=0)
                    			T=LL(T);
                		else
                    			T=LR(T);
        	}
        	else
			/*if entered data is smaller than the parent node it will search the data in left subtree and will delete it*/
            		if(x<T->data)
            		{
                		T->left=delete_node(T->left,x);
				/*Rebalance during windup*/
                		if(BF(T)==-2)
                    			if(BF(T->right)<=0)
                        			T=RR(T);
                    			else
                        			T=RL(T);
            		}
            		else
            		{
                		/*data to be deleted is found*/
                		if(T->right!=NULL)
                		{    /*delete its inorder succesor*/
                    			p=T->right;

                 			 while(p->left!= NULL)
                        			p=p->left;

			                 T->data=p->data;
                    			 T->right=delete_node(T->right,p->data);
					/*rebalance during windup*/
			                 if(BF(T)==2)
                        			if(BF(T->left)>=0)
                            				T=LL(T);
                        			else
                            				T=LR(T);
                		}
                		else
                    			return T->left;
            		}
    			T->ht=height(T);
    			return T;
}
/*function calculates height of tree*/
int height(struct node *T)
{
	int lh,rh;
    	if(T==NULL)
        	return 0;
    	if(T->left==NULL)
        	lh=0;
    	else
        	lh=1+T->left->ht;

    	if(T->right==NULL)
        	rh=0;
    	else
        	rh=1+T->right->ht;
    	if(lh>rh)
        	return lh;
    	return rh;
}
/*function to rotate right*/
struct node *rotateright(struct node *x)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
    	return y;
}
/*function to rotate left*/
struct node *rotateleft(struct node *x)
{
	struct node *y;
	y=x->right;
    	x->right=y->left;
    	y->left=x;
    	x->ht=height(x);
    	y->ht=height(y);
    	return y;
}
/*function for condition right right*/
struct node *RR(struct node *T)
{
	T=rotateleft(T);
	return T;
}
/*function for condition left left*/
struct node *LL(struct node *T)
{
	T=rotateright(T);
	return T;
}
/*function for condition left right*/
struct node * LR(struct node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return T;
}
/*function for condition right left*/
struct node * RL(struct node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
    	return T;
}
/*function to see if node voilates avl property or not*/
int BF(struct node *T)
{
	int lh,rh;
	if(T==NULL)
        	return(0);

	if(T->left==NULL)
        	lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
        	rh=0;
    	else
        	rh=1+T->right->ht;
	return(lh-rh);
}

/*function to print in preorder*/
void preorder(struct node *T)
{
    if(T!=NULL)
    {
        printf("%d->",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
/*function to print in inorder*/ 
void inorder(struct node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d->",T->data);
        inorder(T->right);
    }
}
/*function to print in postorder*/
void postorder(struct node *T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		printf("%d->",T->data);
	}
}



