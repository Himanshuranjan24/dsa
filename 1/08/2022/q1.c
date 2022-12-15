/*1.Write a program to add two distances (in KM -MTR) represented in the form of structure 
by passing structure to function.*/

#include <stdio.h>
struct distance
{
    int km;
    int mtr;
};
typedef struct distance distance;
distance add(distance a, distance b)
{
    distance r;
    r.km=a.km+b.km;
    r.mtr=a.mtr+b.mtr;
    if(r.mtr>=1000)
    {
        r.km+=r.mtr/1000;
        r.mtr%=1000;
    }
    return r;
}
void main()
{
    distance d1,d2,sum;
    printf("Enter the first distance :\n");
    scanf("%d %d",&d1.km,&d1.mtr);
    printf("Enter the second distance :\n");
    scanf("%d %d",&d2.km,&d2.mtr);
    sum=add(d1,d2);
    printf("The sum of two distances is %d kms %d meters.\n\n",sum.km,sum.mtr);
}
