/*WAP to sort the linked list using following methods
1.Ascending where small elements of the list will move to the initial nodes one by one
2.Descending where large elements of the list will move to the initial nodes one by one*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void insert_end(struct node **p,int data);
void display(struct node *q);
void ascending(struct node **p);
void descending(struct node **p);

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
    int opt=0;
    while(opt !=3)
    {
        printf("\n1. Ascending\n2. Descending\n3. Exit\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 3)
        {
            printf("Choose a valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1:
                    ascending(&start);
                    printf("\nLinked list in ascending order is :\n");
                    display(start);
                    break;
            case 2:
                    descending(&start);
                    printf("\nLinked list in descending order is :\n");
                    display(start);
                    break;
            case 3:
                    printf("\nThank u!");
                    break;
        }
    }
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
void ascending(struct node **start)
{
    if(*start == NULL || (*start)->next == NULL)
    return;
    struct node *p = *start, *q = NULL, *temp = NULL;
    int min;
    while(p->next != NULL)
    {
        min = p->info;
        q = p->next;
        for(; q != NULL; q = q->next)
        {
            if(min > q->info)
            {
                min = q->info;
                temp = q;
            }
        }
        if(min != p->info)
        {
            temp->info = p->info;
            p->info = min;
        }
        p = p->next; 
    }
    
}

void descending(struct node **start)
{
    if(*start == NULL || (*start)->next == NULL)
    return;
    struct node *p = *start, *q = (*start)->next, *temp = NULL;
    int max;
    while(p->next != NULL)
    {
        max = p->info;
        q = p->next; 
        for(; q != NULL; q = q->next)
        {
            if(max < q->info)
            {
                max = q->info;
                temp = q;
            }
        }
        if(max != p->info)
        {
            temp->info = p->info;
            p->info = max;
        }
        p = p->next; 
    }
    
}
