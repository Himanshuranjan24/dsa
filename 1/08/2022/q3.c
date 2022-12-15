/*3. Write a program to store employee’s information as name, gender, department,
basic pay, gross pay using one array of structure where gross pay is not the user
input. Calculate the gross pay using the following formula & assign the value in
the individual employee’s gross pay entry.
Gross Pay = basic pay + HR + DA
Where HR=25% of basic
DA= 75% of basic*/

#include <stdio.h>
#define HR 0.25
#define DA 0.75
struct emp
{
    char name[20];
    char gender[10];
    char dep[20];
    float basic;
    double gross;
};
typedef struct emp emp;
void main()
{
    int n,i;
    printf("Enter the no. of employees : ");
    scanf("%d",&n);
    emp e[n];
    for(i=0; i<n; i++)
    {
        printf("Employee %d :\n",i+1);
        printf("Enter name :");
        scanf("%s",&e[i].name);
        printf("Enter gender :");
        scanf("%s",&e[i].gender);
        printf("Enter department :");
        scanf("%s",&e[i].dep);
        printf("Enter basic pay :");
        scanf("%f",&e[i].basic);
        e[i].gross=0;
        e[i].gross=e[i].basic*(1+HR+DA);
        printf("Gross pay is %.2lf.\n",e[i].gross);
    }

}