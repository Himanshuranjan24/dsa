/*WAP to create a circular linked list of n elements & apply the following operation on it.
i) Delete all the nodes at index of multiples of K and add those nodes in the starting of
the circular linked list.
ii) Display the linked list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

void display(node *tail)
{
    if(tail == NULL)
    {
        printf("No elements!\n");
        return;
    }

    node *p = tail->next;
    do
    {
        printf("%d ",p->info);
        p = p->next;
    } while(p != tail->next);

    printf("\n");
    printf("\n");
}

void insert_end(node **tail, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Memory not allocated!\n");
        return;
    }
    temp->info = data;

    if(*tail == NULL)
    {
        *tail = temp;
        temp->next = temp;
        return;
    }

    temp->next = (*tail)->next;
    (*tail)->next = temp;
    *tail = temp;

}

void insert_beg(node **tail, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Memory not allocated!\n");
        return;
    }
    temp->info = data;

    if(*tail == NULL)
    {
        *tail = temp;
        temp->next = temp;
        return;
    }

    temp->next = (*tail)->next;
    (*tail)->next = temp;

}

void delete_k(node **tail, int k)
{
    if(*tail == NULL)
        return;

    int i,count = 0;
    node *head = *tail, *temp = NULL;
    do
    {
        for(i=0; i < k-1; i++)
        {
            head = head->next;
            if(count && head == (*tail)->next)
                return;
            count = 1;
        }

        temp = head->next;
        head->next = temp->next;

        if(temp == *tail)
            *tail = head;

        insert_beg(tail, temp->info);

        free(temp);

    } while(head != (*tail)->next);
}

void main()
{
    int n,i,data;
    node *tail = NULL;
    display(tail);
    printf("Input the value of n : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter data %d : ",i+1);
        scanf("%d",&data);
        insert_end(&tail,data);
    }
    display(tail);
    int k;
    printf("Enter the value of k : ");
    scanf("%d",&k);
    delete_k(&tail, k);
    display(tail);

    printf("\n\nThank u\n\n");
}