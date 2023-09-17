
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

晨曦 23:30:51
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct shoppingitem
{
	char name[50];
	int quantity;
	struct shoppingitem *next;
 }SS;
 struct shoppingitem *l=NULL;
 int main()
 {
 	 void additem(char itemname[],int itemquantity);
 	 void removeitem(char itemname[]);
 	  void display();
 	  void update(char itemquantity[],int newitemquantity);
 	   void clear();
 	    int totalquantity();
 	     void finditem(char itemname[]);
 	    void sort();  
 	    void merge(struct shoppingitem **list1,struct shoppingitem **list2);
 	     void deletel(char itemname[],int delall);
 	  
 	
 }
 void additem(char itemname[],int itemquantity)
 {
 	SS *newitem=(SS *)malloc(sizeof(SS));
 	SS *p;
 	newitem->next=NULL;
 	for(int i=0;i<itemquantity;i++){
 		p=(SS*)malloc(sizeof(SS));
 		strcpy(p->name,itemname[i]);
 		p->quantity=itemquantity;
 		newitem->next=NULL;
	 }
 }
 void removeitem(char itemname[]){
 	SS *current=l;
 	SS *p=NULL;
 	while(current!=NULL){
 		if(strcmp(current->name,itemname[])==0){
 			if(p!NULL){
 				p->next=current->next;
 				
			 }else{
			 	h=current->next;
			 }
			 free(c);
			 break;
		 }
		 p=current;
		 current=current->next;
	 }
 }
 void display()
 {
 	SS*current=l;
 	PRINTF("购物清单：\n");
 	while(current!=NULL){
 		printf("%s -数量: %d\n",current->name,current->quantity);
 		current=current->next;
	 }
 }
 void update(char itemquantity[],int newitemquantity){
 	SS *current =l;
 	while(current!=NULL){
 		if(strcmp(current->name,itemname)==0){
 			newquantity--;
 			break;
		 }
		 current=current->next;
	 }
 }
 void clear()
 {
 	SS *temp;
 	while(l!=NULL)
 	{
 		temp=l;
 		l=l->next;
		 free(temp); 
 		
	 }
 }
 
 int totalquantity()
 {
 	SS *current=l;
 	int total=0;
 	while(current!=NULL)
 	{
 		total++;
 		current=current->next;
	 }
	 return total;
 }
 void finditem(char itemname[])
 {
 	SS*current=l;
 	printf("查找商品\"%s\":\n",itemname);
 	while(current!=NULL){
 		if(strcmp(current->name,itemname)==0){
 			printf("%s-数量:%d\n",current->name,current->quantity);
 			return ;
		 }
		 current=current->next;
	 }
	 printf("未找到商品\"%s\"。\n",itemname);
 }
 void sort(){
 	SS*current=l;
 	SS*nextitem=NULL;
 	char tempname[50];
 	int tempquantity;
 	while(current!=NULL)
 	{
 		nextitem=current->next;
 		while(nextitem!=NULL){
 			if(strcmp(current->name,nextitem->name)>0){
 				strcpy(tempname,current->name);
 				strcpy(current->name,nextitem->name);
 				strcpy(nextitem->name,tempname);
 				tempquantity=current->quantity;
 				current->quantity=nextitem->quantity;
 				nextitem->quantity=tempquantity;
			 }
			 nextitem=nextitem->next;
		 }
		 current=current->next;
	 }
 }
 void merge(struct shoppingitem **list1,struct shoppingitem **list2){
 	SS*current=*list1;
 	while(current!=NULL){
 		current=lcurrent->next;
	 }
	 current->next=*list2;
	 *list2=NULL;
	 
 }
 void deletel(char itemname[],int delall){
 	SS *current=l;
 	SS *prev=NULL;
 	while(current!=NULL){
 		if(strcmp(current->name,itemname)==0){
 			if(prev==NULL){
 				SS *temp=l;
 				l=l->next;
 				free(temp);
 				if(!delall)break;
			 }else{
			 	free(current);
			 	current=prev->next;
			 	if(!delall)break;
			 }
		 }else{
		 	prev=current;
		 	current=current->next;
		 }
	 }
 }


