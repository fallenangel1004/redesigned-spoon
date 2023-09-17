有佳 22:27:00
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Shoppingltem
{
	char name[50];
	int quantity;
	struct Shoppingltem *next;	
};
struct Shoppingltem *shoppingList=NULL,*temp=NULL;
void addltem(char itemName[],int itemQuantity)
{
	struct Shoppingltem *newltem=(struct Shoppingltem *)malloc(sizeof(struct Shoppingltem));
	strcpy(newltem->name,itemName);
	newltem->quantity=itemQuantity;
	if(shoppingList==NULL)
	shoppingList=newltem;
	else
	{
		shoppingList->next=newltem;
		shoppingList=newltem;
	}
}
void removeltem(char itemName[])
{
	struct Shoppingltem *current=shoppingList;
	struct Shoppingltem *previous=NULL;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			if(previous!=NULL)
			{
				previous->next=current->next;
			}
			else
			{
				shoppingList=current->next;
			}
			free(current);
			break;
		}
		previous=current;
		current=current->next;
	}
}
void displayList()
{
	struct Shoppingltem *current=shoppingList;
	printf("购物清单：\n");
	while(current!=NULL)
	{
		printf("%s - 数量：%d\n",current->name,current->quantity);
		current=current->next;
	}
}
void updateQuantity(char itemName[],int newltemQuantity)
{
	struct Shoppingltem *current=shoppingList;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			current->quantity=newltemQuantity;
			break;
		}
		current=current->next;
	}
}
void clearList()
{
	while(shoppingList!=NULL)
	{
		temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}
int totalQuantity()
{
	struct Shoppingltem *current=shoppingList;
	int total=0;
	while(current!=NULL)
	{
		total++;
		current=current->next;
	}
	return total;
}
void findltem(char itemName[])
{
	struct Shoppingltem *current=shoppingList;
	printf("查找商品\"%s\"：\n",itemName);
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			printf("%s - 数量：%d\n",current->name,current->quantity);
			return;
		}
		current=current->next;
	}
	printf("未找到商品\"%s\"。\n",itemName);
}
void sortList()
{
	struct Shoppingltem *current=shoppingList;
	struct Shoppingltem *nextltem=NULL;
	char tempName[50];
	int tempQuantity;
	while(current!=NULL)
	{
		nextltem=current->next;
		while(nextltem!=NULL)
		{
			if(strcmp(current->name,nextltem->name)>0)
			{
				strcpy(tempName,current->name);
				strcpy(current->name,nextltem->name);
				strcpy(nextltem->name,tempName);
				tempQuantity=current->quantity;
				current->quantity=nextltem->quantity;
				nextltem->quantity=tempQuantity;
			}
			nextltem=nextltem->next;
		}
		current=current->next;
	}
}
int main()
{
	int n,q;
	char Name[50];
	while(1)
	{
		scanf("%d",&n);
	if(n<0||n>10)
		break;
	else
	{
	switch(n)
	{
		case 1:while(1)
		{
			scanf("%s%d",Name,&q);
			if(strcmp(Name,"xx")==0)
			break;
			else
			{
				addltem(Name,q);
			}
		};break;
		case 2:scanf("%s",Name);removeltem(Name);break;
		case 3:displayList();break;
		case 4:scanf("%s%d",Name,&q);updateQuantity(Name,q);break;
		case 5:clearList();break;
		case 6:totalQuantity();break;
		case 7:scanf("%s",Name);findltem(Name);break;
		case 8:sortList();break;
	}
	}
	}
	return 0;
}


