#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int info;
    double diff_avg;
    struct node *next;
};

struct header
{
    int nodes;
    double avg;
    double max_diff;
    double min_diff;
    struct node *next;
};

void insert_end(struct node **head,int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(!temp)
    {
        printf("Memory not allocated!\n");
        return;
    }
    temp->info = x;
    temp->next = NULL;
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *p = *head;
        for(; p->next != NULL; p = p->next);
        p->next = temp;
    }
}

void display_header(struct header *p)
{
    if(p == NULL)
        return;

    printf("No. of nodes = %d\n",p->nodes);
    printf("Average value of elements = %.2lf\n",p->avg);
    printf("Maximum difference of node info & average value = %.2lf\n",p->max_diff);
    printf("Minimum difference of node info & average value = %.2lf\n",p->min_diff);

    struct node *ptr = p->next;

    while(ptr)
    {
        printf("\nData = %d\tDiff from avg value = %.2lf\n",ptr->info,ptr->diff_avg);
        ptr = ptr->next;
    }
    
}

void main()
{
    struct header *head = (struct header *)malloc(sizeof(struct header));

    if(head == NULL)
        return;

    struct node *ptr = NULL;
    int n;
    printf("Input the value of n : ");
    scanf("%d",&n);
    head->nodes = n;
    int i, data, sum = 0;
    for(i=0; i<n; i++)
    {
        printf("Enter data %d : ",i+1);
        scanf("%d",&data);
        sum += data;
        insert_end(&ptr,data);
    }
    double avg = (sum * 1.0) / n;
    head->avg = avg;
    head->next = ptr;
    double max = INT_MIN;
    double min = INT_MAX;
    for(i = 0; i < n; i++)
    {
        ptr->diff_avg = ptr->info - head->avg;

        if(max < ptr->diff_avg)
            max = ptr->diff_avg;
        
        if(min > ptr->diff_avg)
            min = ptr->diff_avg;

        ptr = ptr->next;

    }
    head->max_diff = max;
    head->min_diff = min;

    display_header(head);
}