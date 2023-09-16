#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 100, M = 1000;

typedef struct Shoppingitem
{
    char name[50];
    int quantity;
    struct Shoppingitem* next;
}Nodeer;

Nodeer* shoppinglist = NULL;
Nodeer* shoppinglist2 = NULL;

void addItem(char ItemName[], int itemQuantity)
{
    Nodeer* newItem = (Nodeer*)malloc(sizeof(Nodeer));

    strcpy(newItem->name, ItemName);

    newItem->quantity = itemQuantity;
    if (shoppinglist == NULL) {
        shoppinglist = newItem;
        newItem->next = NULL;
        shoppinglist->next = NULL;
    }
    else {
        newItem->next = shoppinglist;
        shoppinglist = newItem;
    }
}

void removeItem(char itemName[])
{
    Nodeer* current = shoppinglist;
    Nodeer* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (previous != NULL) previous->next = current->next;
            else
                shoppinglist = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displaylist()
{
    Nodeer* current = shoppinglist;

    printf("�����嵥:\n");
    while (current != NULL)
    {
        printf("%s - ����: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

void updateQuantity(char itemName[], int newItemQuantity)
{
    Nodeer* current = shoppinglist;

    while (current != NULL)
    {
        if (strcmp(current->name, itemName) == 0)
        {
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

void clearlist()
{
    while (shoppinglist != NULL)
    {
        Nodeer* temp = shoppinglist;
        shoppinglist = shoppinglist->next;
        free(temp);
    }
}

int totalQuantity()
{
    Nodeer* current = shoppinglist;
    int total = 0;

    while (current != NULL)
    {
        total++;
        current = current->next;
    }

    return total;
}

void findItem(char itemName[])
{
    Nodeer* current = shoppinglist;

    printf("������Ʒ\"%s\" : \n", itemName);
    while (current != NULL)
    {
        if (strcmp(current->name, itemName) == 0)
        {
            printf("%s - ����: %d\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }

    printf("δ�ҵ���Ʒ\"%s\"�� \n", itemName);
}

void sortlist()
{
    Nodeer* current = shoppinglist;
    Nodeer* nextItem = NULL;
    char tempName[50];
    int tempQuantity;

    while (current != NULL) {
        nextItem = current->next;

        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0)
            {
                strcpy(tempName, current->name);
                strcpy(current->name, nextItem->name);
                strcpy(nextItem->name, tempName);

                tempQuantity = current->quantity;
                current->quantity = nextItem->quantity;
                nextItem->quantity = tempQuantity;
            }
            nextItem = nextItem->next;
        }
        current = current->next;
    }
}
//void mergeLists(struct ShoppingItem **list1,struct ShoppingItem **list2){
	struct ShoppingItem *current=*list1;
	//
	
	;
	current->next=*list2; 
	*list2=NULL;
}
void deleteItem(char itemName[], int deleteALL)
{
    Nodeer* current = shoppinglist;
    Nodeer* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                Nodeer* temp = shoppinglist;
                current = shoppinglist = shoppinglist->next;
                free(temp);
                if (!deleteALL) break;
            }
            else {
                prev->next = current->next;
                free(current);
                current = prev->next;
                if (!deleteALL) break;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

int main()
{
    int n,k;
    char item[M][N];
    int itemname;
    int a;

    scanf("%d", &n);

    for (int k = 0; k < n; k++)
    {
        scanf("%s%d",\ item[i], &itemname);
        addItem(item[i], itemname);
    }
    a=totalQuantity();
    printf("��Ʒ�������� = %d\n", a);

    printf("�ѵ�8����Ʒ������Ϊ20\n");
    updateQuantity(item[8], 20);
    displaylist();

    printf("����5����Ʒ:\n");
    findItem(item[5]);
    displaylist();
    

    printf("ɾ����item[7]��Ʒ:\n");
    removeItem(item[7]);
    displaylist();
    
    printf("����");
    sortlist();
    displaylist();
    
    printf("ɾ��item[16]����Ʒ\n");
    deleteItem(item[16], 1);
    displaylist();

    printf("���clear: \n");
    clearlist();
    displaylist();

    return 0;
}
