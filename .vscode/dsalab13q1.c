/*Wap (menu driven)  to do the following sorting :-
1)Bubble sort
2)Insertion sort
3)Selection sort
4)Merge sort*/
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    int i,j,temp;
    for(i = 0; i < n-1; i++)
        for(j=0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

    display(arr,n);
}

void selection_sort(int *arr, int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    display(arr,n);
}

void insertion_sort(int *arr, int n)
{
    int i,j,min;
    for(i = 1; i < n; i++)
    {
        min = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > min)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = min; 
    }

    display(arr,n);
}


void main()
{
    int n;
    printf("Input the no. of elements in the array : ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    int i;
    for(i=0; i<n; i++)
        scanf("%d",arr+i);
    display(arr,n);
    int opt = 0;
    while(opt != 6)
    {
        printf("\n1. BUBBLE SORT");
        printf("\n2. SELECTION SORT");
        printf("\n3. INSERTION SORT");
        printf("\n4. MERGE SORT");
        printf("\n5. DISPLAY");
        printf("\n6. EXIT");
        printf("\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 && opt > 6)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1 :
                bubble_sort(arr,n);
                break;
            case 2 :
                selection_sort(arr,n);
                break;
            case 3 :
                insertion_sort(arr,n);
                break;
            case 4 :
                break;
            case 5 :
                display(arr,n);
                break;
            case 6:
                printf("\nThank u!\n");
                break;

        }
    }
}