/*4. Write a program to take input of two polynomials (array implementation) and use
menu driven to apply the following operations on it.
a. Addition
b. Subtraction
c. Multiplication*/

#include <stdio.h>
#include <stdlib.h>

int* add(int *p, int m, int *q, int n);
int* subtract(int *p, int m, int *q, int n);
int* multiply(int *p, int m, int *q, int n);
void display(int *ptr, int m);

void main()
{
    int m,n;
    printf("Input the highest order of first polynomial : ");
    scanf("%d",&m);
    int *p = (int*)calloc(m+1,sizeof(int));
    int i;
    printf("Enter the terms of first polynomial :\n");
    for(i=0; i<m+1; i++)
    {
        printf("Enter coefficient of x^%d : ",i);
        scanf("%d",p+i);
    }
    printf("Input the highest order of second polynomial : ");
    scanf("%d",&n);
    int *q = (int*)calloc(n+1,sizeof(int));
    printf("Enter the terms of second polynomial :\n");
    for(i=0; i<n+1; i++)
    {
        printf("Enter the coefficient of x^%d : ",i);
        scanf("%d",q+i);
    }
    printf("First polynomial entered is :\n");
    display(p,m);
    printf("\nSecond polynomial entered is :\n");
    display(q,n);
    printf("\n");
    int opt=0,*res = NULL;
    int temp;
    if(m>n)
    temp = m;
    else
    temp = n;
    while(opt != 4)
    {
        printf("\n1. Addition\n");
        printf("\n2. Subtraction\n");
        printf("\n3. Multiplication\n");
        printf("\n4. Exit\n");
        printf("Choose an option :");
        scanf("%d",&opt);
        while(opt < 1 || opt > 4)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1:
                    res = add(p,m,q,n);
                    printf("\nAddition of two polynomials is :\n");
                    display(res,temp);
                    break;
            case 2:
                    res = subtract(p,m,q,n);
                    printf("\nSubtraction of two polynomials is :\n");
                    display(res,temp);
                    break;
            case 3:
                    res = multiply(p,m,q,n);
                    printf("\nMultiplication of two polynomials is :\n");
                    display(res,m+n);
                    break;
        }
    }
}

int* add(int *p, int m, int *q, int n)
{
    int *res = NULL;
    int i;
    if(m>n)
    {
        res = (int *)calloc(m+1,sizeof(int));
        for(i=0; i<n+1; i++)
        *(res+i) = *(q+i);
        for(i=0; i<m+1; i++)
        *(res+i) += *(p+i);
    }
    else
    {
        res = (int *)calloc(n+1,sizeof(int));
        for(i=0; i<m+1; i++)
        *(res+i) = *(p+i);
        for(i=0; i<n+1; i++)
        *(res+i) += *(q+i);
    }
    return res;
}

int* subtract(int *p, int m, int *q, int n)
{
    int *res = NULL;
    int i;
    if(m>n)
    {
        res = (int *)calloc(m+1,sizeof(int));
        for(i=0; i<m+1; i++)
        *(res+i) = *(p+i);
        for(i=0; i<n+1; i++)
        *(res+i) -= *(q+i);
    }
    else
    {
        res = (int *)calloc(n+1,sizeof(int));
        for(i=0; i<m+1; i++)
        *(res+i) = *(p+i);
        for(i=0; i<n+1; i++)
        *(res+i) -= *(q+i);
    }
    return res;
}

int* multiply(int *p, int m, int *q, int n)
{
    int *res = NULL;
    res = (int *)calloc(m+n+1,sizeof(int));
    int i,j;
    for(i=0; i<m+1; i++)
    for(j=0; j<n+1; j++)
    *(res+i+j) += *(p+i)* *(q+j);
    return res;
}

void display(int *ptr, int m)
{
    if(ptr == NULL)
    {
        printf("No elements!\n");
        return;
    }
    for(int i=0; i<m+1; i++)
    {
        if(*(ptr+i)!=0)
        {
            printf("%dx^%d ",*(ptr+i),i);
            if(i!=m)
            printf("+ ");
        }
    }
    printf("\n");
}