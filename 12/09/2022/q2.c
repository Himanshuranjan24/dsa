/*1.Find the smallest and largest element in the linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void insert_end(struct node **p,int data);
void display(struct node *q);
int largest(struct node *q);
int smallest(struct node *q);

void main()
{
    struct node *start = NULL;
    int count,i,data;
    printf("Input the no. of elements in the linked list : ");
    scanf("%d",&count);
    for(i=0; i<count; i++)
    {
        scanf("%d",&data);
        insert_end(&start,data);
    }
    printf("Entered linked list is :\n");
    display(start);
    int max,min;
    max = largest(start);
    min = smallest(start);
    printf("\nSmallest element in the linked list is %d\n",min);
    printf("Largest element in the linked list is %d\n",max);
}

void insert_end(struct node **p,int data)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Space not allocated!");
        exit(0);
    }
    temp->info = data;
    temp->next = NULL;
    if(*p == NULL)
    {
        *p = temp;
        return;
    }
    struct node *q = *p;
    for(; q->next != NULL; q=q->next);
    q->next = temp;
}

void display(struct node *q)
{
    if(q == NULL)
    {
        printf("No elements found!");
        return;
    }
    while(q != NULL)
    {
        printf("%d ",q->info);
        q=q->next;
    }
}

int largest(struct node *q)
{
    int x=q->info;
    while(q!=NULL)
    {
        if(x < q->info)
        x = q->info;
        q = q->next;
    }
    return x;
}

int smallest(struct node *q)
{
    int x=q->info;
    while(q!=NULL)
    {
        if(x > q->info)
        x = q->info;
        q = q->next;
    }
    return x;
}
