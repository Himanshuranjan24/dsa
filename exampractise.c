// wap to create a circular linked list of n element and applay the following operastion on it : 
// a. delete all the nodes at index of multiple of k and add nodes in the starting of the curcular linked list
// b. display the circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *newnode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if(newnode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
            }
        }
        temp->next = head;
        printf("CIRCULAR LINKED LIST CREATED SUCCESSFULLY ");
    }
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf(" ");
    }
}

// delete the node at the index of multiple of k
void delete(int k)
{
    struct node *temp, *prev;
    int i = 1;
    temp = head;
    while(temp->next != head)
    {
        if(i % k == 0)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
        i++;
    }
    if(i % k == 0)
    {
        prev->next = temp->next;
        free(temp);
    }
}

int main()
{
    int n, k;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("  ");
    printf("Enter the value of k: ");
    scanf("%d", &k);
    delete(k);
    printf("  ");
    printf("\n\nDisplay: ");  
    printf("\n\n\tHimanshu\n\n");
    display();
    return 0;
}