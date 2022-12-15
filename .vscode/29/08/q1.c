/*Write a menu driven program to create a linked list where user will give the option for insertion
for each element*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

//function declarations
void insert_beg();
void insert_end();
void insert_pos();
void insert_sp_ele(int, int);
void display();

void main()
{
    int opt=0,item,ele;
    while(opt != 6)
    {
        printf("\n1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at specific location\n");
        printf("4.Insert after specific element\n");
        printf("5.Display list\n");
        printf("6.Exit\n");
        printf("Choose option : ");
        label:
        scanf("%d",&opt);
        if(opt < 1 || opt > 6)
        {
            printf("Invalid option chosen.\nChoose the correct option :");
            goto label;
        }
        switch (opt)
        {
            case 1:
                    insert_beg();
                    break;
            case 2:
                    insert_end();
                    break;
            case 3:
                    insert_pos();
                    break;
            case 4:
                    printf("Enter element after which element has to be inserted : ");
                    scanf("%d",&ele);
                    printf("Enter element to be inserted : ");
                    scanf("%d",&item);
                    insert_sp_ele(ele, item);
                    break;
            case 5:
                    display();
                    break;
            case 6:
                    break;
        }
    }
}

//Function definitions
void insert_beg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted : ");
    scanf("%d",&temp->info);
    temp->next = start;
    start = temp;
}

void insert_end()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to be inserted : ");
    scanf("%d",&temp->info);
    temp->next = NULL;
    if(start==NULL)
    start = temp;
    else
    {
        struct node *q;
        for(q=start; q->next != NULL; q=q->next);
        q->next = temp;
    }
}

void insert_pos()
{
    int pos;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position at which element has to be inserted : ");
    scanf("%d",&pos);
    printf("Enter element to be inserted : ");
    scanf("%d",&temp->info);
    if(pos==1)
    {
        temp->next = start;
        start = temp;
    }
    else if(start == NULL)
    {
        printf("Invalid Position!\n");
        return;
    }
    else if(start != NULL)
    {
        struct node *q=start;
        for(int i=1; i <= pos-2; i++)
        {
            q = q->next;
            if(q == NULL)
            {
                printf("Invalid position!\n");
                return;
            }
        }
        temp->next = q->next;
        q->next = temp;
    }
}

void insert_sp_ele(int ele, int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(start == NULL)
    {
        printf("Element not found!\n");
        return;
    }
    else
    {
        struct node *q = start;
        for(; q->info !=ele; q = q->next)
        {
            if(q->next ==NULL)
            {
                printf("Element not found!\n");
                return;
            }
        }
        temp->next = q->next;
        q->next = temp;
    }
}

void display()
{
    struct node *temp = start;
    if(temp == NULL)
    printf("No element present.\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}