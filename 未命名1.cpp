#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct shopping
{
	char name[50];
	int num;
	struct shopping *next;
}shop;
struct shopping *h=NULL;
void add(char item[],int itemnum)
{
	struct shopping*new=(struct shopping*)malloc(sizeof(struct shopping));
	shop *s;
	new->next=NULL;
	for(int i=0;i<itemnum;i++)
	{
		s=(shop *)malloc(sizeof(shop));
		s->name=item[i];
		s->num=itemnum;
		s->next=new->next;
		new->next=s;
		}	
}
void remove(char item[])
{
	shop*c=h;
	shop*p-NULL;
	while(c!=NULL)
	{
		if(strcmp(c->name,item)==0){
			if(p!=NULL)
			{
				p->next=c->next;
			 } 
			 else
			 {
			 	h=c->next;
			 }
			 free(c);
			 break;
		}
		p=c;
		c=c->next;
	
		
	}
}
void dis()
{
	struct shopping*c=h;
	printf("购物清单：\n");
	while(c!=NULL)
	{
		printf("%s-数量：%d\n",c->name,c->q);
		c=c->next;
	}
}
void up(char item[],int new)
{
	shop*c=h;
	while(c!=NULL)
	{
		if(strcmp(c->name,item)==0)
		{
			new--;
			break;
		}
		c=c->next;
	}
}
void clear()
{
	while(h!=NULL)
	{
		shop*n=h->next;
		free(n);
		h=n;
	}
}
int tot()
{
	shop*c=h;
	int to=0;
	whiel(c!=NULL)
	{
		to++;
		c=c->next;
	}
	return to;
}
void find(char item[])
{
	shop*c=h;
	printf("查找商品\"%s\":\n",item);
	while(c!=NULL)
	{
		if(strcmp(c->name,item)==0)
		{
			printf("%s-数量:%d\n",c->name,c->num);
			return;
		}
		c=c->next;
	}
	printf("未找到商品\"%s\"。\n",item);
}
void sort()
{
	shop*c=h;
	shop*n=NULL;
	char temp[50];
	int t;
	while(c!=NULL)
	{
		n=c->next;
		while(n!=NULL)
		{
			if(strcmp(c->name,n->name)>0)
			{
				temp=c->name;
				c->name=n->name;
				n->name=temp;
				t=c->num;
				c->num=n->num;
				n->num=t;
				
			}
			n=n->next;
		}
		c=c->next;
	}
}
void mer(shop**list1,shop**list2)
{
	shop*c=*list1;
	for(c;c!=NULL;c=c->next)
	c->next=*list2;
	*list2=NULL;
}
void dele(char item[],int dele)
{
	shop*c=h;
	shop*p=NULL;
	while(c!=NULL)
	{
		if(strcmp(c->name,item)==0)
		{
			if(p==NULL)
			{
				shop*temp=h;
				h=h->next;
				free(temp);
				if(!deleteALL)
				break;
			}
			else
			{
				free(c);
				c=p->next;
				if(!deleteALL)
				break;
			}
		}
		else
		{
			p=c;
			c=c->next;
		}
	}
}
int  main()
{
	 add(char item[],int itemnum);
 dele(char item[],int dele);
	  mer(shop**list1,shop**list2);
	 sort();
	 find(char item[]);
	 clear();
	 up(char item[],int new);
	dis();
	 remove(char item[]);
}
