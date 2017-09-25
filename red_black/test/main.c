#include"red_black.h"
int main()
{
	int sw,num;
	sentinel = (struct node *) malloc(sizeof(struct node));
        sentinel->info = -1;
        sentinel->color = black;
        root = sentinel;
	while(1)
	{
		printf("\n1.Insert\n2.Display\n0exit\n");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				printf("\nenter the number to be inserted\n");
				scanf("%d",&num);
				insert(num/*,root,sentinel*/);
				break;
			case 2:
				display(root,0);
				break;
			case 0:
				exit(0);
		}
	}
}
