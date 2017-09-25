#include"bst.h"

int main()
{
	struct bst *root = NULL;
	int sw, val, disp, height;
	while(1)
	{
		printf("\n1.To insert in BST\n2.To search in BST\n3.To delete in BST\n4.To display nodes in BST\n5.Find Minimum Node\n6.Find Maximum Node\n7.Find Height in bst\n0.exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("enter the value to insert into BST\n");
				scanf("%d",&val);
				root = insert_into_bst(root,val);
				break;
			case 2:
				printf("enter the value to be searched\n");
				scanf("%d",&val);
				root = search_into_bst(root,val);
				break;
			case 3:
				printf("enter the value to be deleted\n");
				scanf("%d",&val);
				root = delete_into_bst(root,val);
				printf("\n");
				display_pre_order(root);
				break;
			case 4:
				printf("\n1.To display in pre_order\n2.To display in post_order\n3.To display in in_order\n");
				scanf("%d",&disp);
				if(disp ==  1)
					display_pre_order(root);
				else if(disp == 2)
					display_post_order(root);
				else if(disp == 3)
					display_in_order(root);
				break;
			case 5:
				root = find_min(root);
				break;
			case 6:
				root = find_max(root);
				break;
			case 7:
				height = Height_in_bst(root);
				printf("Maximum Height of bst=%d\n",height);
				break;
			case 0:
				exit(0);
			default:
				printf("Invalid input\n");
				break;
		}
	}
}
