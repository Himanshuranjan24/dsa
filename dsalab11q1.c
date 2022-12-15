/*1. WAP to do the following in queue data structure:
a. Enqueue
b. Dequeue
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int N = 50;
int queue[50];
int front = -1, rear = -1;

void enqueue(int data)
{
    if(rear == N-1)
    {
        printf("Overflow!!\n");
        return;
    }
    if(front == -1 && rear == -1)
    front = rear = 0;
    else
    rear ++;
    queue[rear] = data;
}

int dequeue()
{
    int r;
    if(front == -1 || front > rear)
    {
        printf("Underflow!!\n\n");
        return INT_MAX;
    }
    r = queue[front];
    if(front == rear)
    front = rear = -1;
    else
    front ++;
    return r;
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("No element present!\n\n");
        return;
    }
    int temp = front;
    while(temp <= rear)
    {
        printf("%d ",queue[temp++]);
    }
}

void main()
{
    int opt = 0,data;
    while(opt != 4)
    {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nChoose an option : ");
        scanf("%d",&opt);
        while(opt < 1 || opt > 4)
        {
            printf("Choose valid option : ");
            scanf("%d",&opt);
        }
        switch(opt)
        {
            case 1:
                    printf("Enter element to be queued : ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2:
                    data = dequeue();
                    printf("Data dequeued is %d.\n\n",data);
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    printf("Thank u!\n\n");
                    break;
        }
    }
}