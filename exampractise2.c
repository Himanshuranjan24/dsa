// WAP to create one single linked list with unique values & implement followings on it.
// i) Find the node that contains minimum value, delete the node & insert that as the first
// node in the same linked list.
// ii) FInd the node that contains the maximum value, delete that node & insert that as the
// last node in the same linked list.
// iii) Display function (Use this to display each stage of the program)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

void insert_beg(node **head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = data;
    temp->next = *head;
    *head = temp;
}

int insert_end(node **head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return 1;
    }
    if ((*head)->next == NULL && (*head)->info == data)
    {
        printf("Data already present!\n");
        return 0;
    }

    node *p = *head;
    for (; p->next != NULL; p = p->next)
    {
        if (p->info == data)
        {
            printf("Data already present!\n");
            return 0;
        }
    }

    p->next = temp;
    return 1;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("No elements!\n");
        return;
    }
    while (head)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n\n");
}

void main()
{
    int n, i, data, flag = 0;
    node *head = NULL;
    printf("Input the value of n : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data %d : ", i + 1);
        scanf("%d", &data);
        flag = insert_end(&head, data);
        if (flag == 0)
            i--;
    }
    printf("Linked list entered is :\n");
    display(head);
    node *temp = head;
    node *max_prev = NULL, *min_prev = NULL;
    int max, min;
    max = min = head->info;
    while (temp->next)
    {
        if (max < temp->next->info)
        {
            max = temp->next->info;
            max_prev = temp;
        }
        if (min > temp->next->info)
        {
            min = temp->next->info;
            min_prev = temp;
        }

        temp = temp->next;
    }

    if (max_prev == NULL && head != NULL)
    {
        temp = head;
        head = head->next;

        node *p = head;
        for (; p->next != NULL; p = p->next)
            ;

        p->next = temp;
        temp->next = NULL;
    }
    else
    {
        temp = max_prev->next;
        max_prev->next = temp->next;
        temp->next = NULL;
        node *p = head;
        for (; p->next != NULL; p = p->next)
            ;
        p->next = temp;
    }
    display(head);

    if (min_prev)
    {
        temp = min_prev->next;
        min_prev->next = temp->next;
        temp->next = head;
        head = temp;
    }
    display(head);
}