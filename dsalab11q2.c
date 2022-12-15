/*2. WAP to implement double ended queue-input restricted, output restricted.*/
#include<stdio.h>
#include<stdlib.h>
#define max 5

void display(int *q){
    printf("\nQueue is: \n");
    for(int i = 0;i<max;i++){
        printf("%d ",q[i]);
    }
}
void create(int *q){
    for(int i = 0;i<max;i++){
        q[i] = 0;
    }
}
void insert_right(int *q,int *l,int *r,int item){
    if(*l==0 && (*r == (max - 1) || *l == (*r +1))){
        printf("Overflow");
    }
    else if(*l==-1){
        *l = *r = 0;
        q[*r] = item;
    }
    else if(*r == max - 1){
        *r = 0;
        q[*r] = item;
    }
    else{
        *r = *r + 1;
        q[*r] = item;
    }
}
void insert_left(int *q,int *l,int *r,int item){
    if(*l==0 && (*r == (max - 1) || *l == (*r +1))){
        printf("Overflow");
    }
    else if(*l == -1){
        *l = *r = 0;
        q[*l] = item;
    }
    else if(*l == 0){
        *l = max - 1;
        q[*l] = item;
    }
    else{
        *l = *l - 1;
        q[*l] = item;
    }
}
int del_right(int *q, int *l,int *r){
    int val;
    if(*r == -1){
        printf("Underflow");
        val = -999;
    }
    else if(*l == *r){
        val = q[*r];
        q[*r] = 0;
        *l = *r = -1;
    }
    else if(*r == 0){
        val = q[*r];
        q[*r] = 0;
        *r = max-1;
    }
    else{
        val = q[*r];
        q[*r] = 0;
        *r = *r - 1;
    }
    return val;
}
int del_left(int *q, int *l,int *r){
    int val;
    if(*l == -1){
        printf("Underflow");
        val = -999;
    }
    else if(*l == *r){
        val = q[*l];
        q[*l] = 0;
        // *l = *r = -1;
    }
    else if(*l == max - 1){
        val = q[*l];
        q[*l] = 0;
        // *r = max-1;
        *l = 0;
    }
    else{
        val = q[*l];
        q[*l] = 0;
        *l = *l + 1;
    }
    return val;
}
int main(){
    int q[max];
    int l, r,n,v,num,b;
    l = r = -1;
    create(q);//just for understanding

    display(q);
    while(1){
        printf("\nThe choices are\n1.insert right\n2.insert left\n3.delete right\n4.delete left\n5.display\n6.EXIT\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item: ");
            scanf("%d",&n);
            insert_right(q,&l,&r,n);
            break;
        case 2:
            printf("\nEnter the item: ");
            scanf("%d",&v);
            insert_left(q,&l,&r,v);
            break;
        case 3:
            num = del_right(q,&l,&r);
            printf("\n%d got dequeued\n",num);
            break;
        case 4:
            b = del_left(q,&l,&r);
            printf("\n%d got dequeued\n",b);
            break;
        case 5:
            display(q);
            break;
        case 6:
            exit(1);
            break;
        
        default:
            break;
        }
    }
    return 0;
}