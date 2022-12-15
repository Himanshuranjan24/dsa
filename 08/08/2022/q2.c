/*2. WAP to create one array dynamically (user will tell the size of the array at run
time) and do the following operations. (use functions and switch case)
i. Input the element to the array
ii. Insert the element at a specified position (User will give the element and
position)
iii. Insert at beginning (User will give the element)
iv. Insert at end (User will give the element use realloc() to increase the size)*/

#include <stdio.h>
#include <stdlib.h>
void input(int *a, int *n);
void insert(int *a, int *n);
void insert_beginning(int *a,int *n);
void insert_end(int *a,int *n);
void main()
{
    int n,i;
    printf("Input the no. of elements in the array : ");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    input(p,&n);
    printf("Entered elements are :\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n\n1. Insert the element at a specified position\n");
    printf("2. Insert at beginning\n3. Insert at end\n4. Exit");
    int opt=0;
    while(opt!=4)
    {
        printf("\n\nChoose an option : ");
        scanf("%d",&opt);
        if(opt<1 || opt > 4)
        {
            printf("Invalid choice!!");
            exit(0);
        }
        switch (opt)
        {
            case 1:
                    insert(p,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",p[i]);
                    break;
            case 2:
                    insert_beginning(p,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",p[i]);
                    break;
            case 3:
                    insert_end(p,&n);
                    for(i=0; i<n; i++)
                    printf("%d ",p[i]);
                    break;
            case 4:
                    break;
        }
    }
}
void input(int *a, int *n)
{
    printf("Enter the elements :\n");
    for(int i=0; i<*n; i++)
    scanf("%d",a+i);
}
void insert(int *a, int *n)
{
    int loc,x,i;
    printf("\nEnter the location(index) at which element is to be inserted : ");
    scanf("%d",&loc);
    printf("Enter the element to be inserted : ");
    scanf("%d",&x);
    *n+=1;
    a = realloc(a,*n*sizeof(int));
    for(i=*n-1; i>loc; i--)
    {
        *(a+i)=*(a+i-1);
    }
    *(a+i)=x;
}
void insert_beginning(int *a,int *n)
{
    int x,i;
    printf("\nEnter the element to be inserted at the beginning : ");
    scanf("%d",&x);
    *n+=1;
    a = realloc(a,*n*sizeof(int));
    for(i=*n-1; i>0; i--)
    *(a+i)=*(a+i-1);
    *(a+i)=x;
}
void insert_end(int *a,int *n)
{
    int x,i;
    printf("\nEnter the element to be inserted at the end : ");
    scanf("%d",&x);
    *n+=1;
    a = realloc(a,*n*sizeof(int));
    *(a+*n-1)=x;
}
