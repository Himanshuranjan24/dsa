/*2. WAP to implement sparse matrix using linked list as follows
1)Transpose
2)Addition
3) Multiplication*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node node;
typedef struct header header;

struct node
{
    int x,y,z;
    node *next;
};

struct header
{
    int tr,tc,total;
    node *next;
};

void main()
{
    header *start = NULL;
    start = (header *)malloc(sizeof(header));
    if(start == NULL)
    {
        printf("Space not allocated!\n");
        exit(0);
    }
}