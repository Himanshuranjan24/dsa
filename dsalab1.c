/*1. WAP to represent polynomials using linked list
1)Addition
2)Multiplication*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node node;

struct node
{
    int coff,exp;
    struct node *next;
};

void insert_end(node **p, int coff, int exp);
void display(node *q);
node* add(node *p, node *q);
node* multiply(node *p, node *q);
void insert_sort(node **q, int coff, int exp);


void main()
{
    node *start1 = NULL;
    int deg,i,data;
    printf("Enter the degree of polynomial : ");
    scanf("%d",&deg);
    for(i=0; i<=deg; i++)
    {
        printf("Enter the coefficient of x^%d : ",i);
        scanf(" %d",&data);
        if(data != 0)
        insert_end(&start1,data,i);
    }
    display(start1);
    node *start2 = NULL;
    printf("\nEnter the degree of polynomial : ");
    scanf("%d",&deg);
    for(i=0; i<=deg; i++)
    {
        printf("Enter the coefficient of x^%d : ",i);
        scanf(" %d",&data);
        if(data != 0)
        insert_end(&start2,data,i);
    }
    display(start2);
    node *res = add(start1, start2);
    printf("\nAddition of two polynomials is :\n");
    display(res);
    res = multiply(start1, start2);
    printf("\nMultiplication of two polynomials is :\n");
    display(res);
}

void insert_end(node **q, int coff, int exp)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coff = coff;
    temp->exp = exp;
    temp->next = NULL;
    if(*q == NULL)
    {
        *q = temp;
    }
    else
    {
        node *p = *q;
        for(; p->next != NULL; p = p->next);
        p->next = temp;
    }
}

void display(node *q)
{
    if(q == NULL)
    {
        printf("No elements present!");
    }
    else
    {
        for( ; q != NULL; q=q->next)
        {
            printf("%dx^%d ",q->coff,q->exp);
            if(q->next != NULL)
            printf("+ ");
        }
    }
    printf("\n");
}

node* add(node *p, node *q)
{
    node *r = NULL; 
    if(p == NULL)
    return q;
    else if(q == NULL)
    return p;
    while(p != NULL || q !=NULL)
    {
        if(p == NULL)
        {
            while(q != NULL)
            {
                insert_end(&r, q->coff, q->exp);
                q = q->next;
            }
            return r;
        }
        else if(q == NULL)
        {
            while(p != NULL)
            {
                insert_end(&r, p->coff, p->exp);
                p = p->next;
            }
            return r;
        }
        if(p->exp == q->exp)
        {
            insert_end(&r,p->coff+q->coff, p->exp);
            p = p->next;
            q = q->next;
        }
        else if(p->exp < q->exp)
        {
            insert_end(&r, p->coff, p->exp);
            p = p->next;
        }
        else
        {
            insert_end(&r, q->coff, q->exp);
            q = q->next;
        }
    }
    return r;
}

node* multiply(node *p, node *q)
{
    node *r = NULL;
    if(p == NULL || q == NULL)
    {
        insert_end(&r,0,0);
        return r;
    }
    node *temp = NULL;
    while(p != NULL)
    {
        temp = q;
        while(temp!=NULL)
        {
            insert_sort(&r,p->coff * temp->coff, p->exp + temp->exp);
            temp = temp->next;
        }
        p = p->next;
    }
    return r;
}

void insert_sort(node **q, int coff, int exp)
{
    if(*q == NULL)
    {
        insert_end(q,coff,exp);
        return;
    }
    node *curr = *q, *prev = NULL;
    while(curr != NULL)
    {
        prev = curr;
        if(curr->exp == exp)
        {
            curr->coff += coff;
            return;
        }
        if(curr->exp > exp)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->coff = coff;
            temp->exp = exp;
            temp->next = curr;
            prev->next = temp;
            return;
        }
        curr = curr->next;
    }
    insert_end(q,coff,exp);
}