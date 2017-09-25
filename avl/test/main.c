#include"avl.h"

int main()
{
	struct node *root = NULL;
	int x, n, i, sw;
	while(1)
	{
		printf("\n1.create a tree\n2.insert node\n3.delete node\n4.print tree\n0.exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("\nenter no of elements\n");
				scanf("%d",&n);
				printf("enter the data in tree\n");
				for(i = 0; i<n; i++)
				{
					scanf("%d",&x);
					root = insert(root, x);
				}
				break;
			case 2:
				printf("enter a data\n");
				scanf("%d",&x);
				root = insert(root, x);
				break;
			case 3:
				printf("enter a node to delete\n");
				scanf("%d",&x);
				root = delete_node(root, x);
				break;
			case 4:
				printf("\n1.preorder\n2.inorder\n3.postorder\n");
				scanf("%d",&x);
				if(x == 1)
					preorder(root);
				if(x == 2)
					inorder(root);
				if(x == 3)
					postorder(root);
				break;
			case 0:
				exit(0);
		}
	}
}
