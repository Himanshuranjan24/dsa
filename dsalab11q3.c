/*3. WAP to implement priority queue.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};


struct node *front = NULL;


void insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    printf("Enter the priority: ");
    scanf("%d", &newnode->priority);
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        struct node *temp;
        temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


void delete()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue is empty ");
    }
    else
    {
        front = front->next;
        free(temp);
    }
}


void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue is empty ");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}


void main()
{
    int choice;
    while (1)
    {
        printf(" 1. Insert 2. Delete 3. Display 4. Exit ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}