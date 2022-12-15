/*3. WAP to create one array dynamically and do the following operations. (use
functions and switch case)
i. Input the element to the array
ii. Delete the element at a specified position (User will give the position)
iii. Delete the specified element (User will give the element, consider the array
may have similar elements)
[Note: let specified element is 5 &amp; element 5 is present 3 times, then delete all the
occurrence of 5 &amp; reduce the size of array by 3.]
iv. Delete from the beginning*/

#include <stdio.h>
#include <stdlib.h>
void dlt_position(int *, int *);
void dlt_element(int *, int *);
void dlt_beginning(int *, int *);
void main()
{
    int n;
    printf("Input the no. of elements in the array : ");
    scanf("%d",&n);
    int *a = (int *)malloc(n*sizeof(int));
    int i;
    printf("Enter the elements :\n");
    for(i=0; i<n; i++)
    scanf("%d",&a[i]);
    int opt=0;
    while(opt!=4)
    {
        printf("\n\n1. Delete the element at a specified position");
        printf("\n2. Delete the specified element");
        printf("\n3. Delete from the beginning\n4. Exit");
        printf("\n\nChoose an option : ");
        scanf("%d",&opt);
        if(opt<1 || opt > 4)
        {
            printf("Invalid choice!!\n");
            break;
        }
        switch (opt)
        {
            case 1:
                    dlt_position(a,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",a[i]);
                    break;
            case 2:
                    dlt_element(a,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",a[i]);
                    break;
            case 3:
                    dlt_beginning(a,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",a[i]);
                    break;
            case 4:
                    break;
        }

    }
}
void dlt_position(int *a, int *n)
{
    int x,i;
    printf("Enter the position at which element is to be deleted : ");
    scanf("%d",&x);
    for(i=x-1; i<*n-2; i++)
    *(a+i)=*(a+i+1);
    *n-=1;
    a = realloc(a, *n*sizeof(int));
}
void dlt_element(int *a, int *n)
{
    int x,i,count=0;
    printf("Enter the element to be deleted : ");
    scanf("%d",&x);
    for(i=0; i<*n; i++)
    {
        if(*(a+i)==x)
        {
            for(int j=i; j<*n-1; j++)
            {
                *(a+j)=*(a+j+1);
            }
            *n-=1;
            i--;
        }
    }
}
void dlt_beginning(int *a, int *n)
{
    for(int i=0; i<*n-1; i++)
    *(a+i)=*(a+i+1);
    *n-=1;
    a= realloc(a, *n*sizeof(int));
}