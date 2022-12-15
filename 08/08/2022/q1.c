/*1. Write a program to store the ’n’ employee information as follows
i. Name (Name should have fname, mname and lname and use structure within
structure)
ii. DoB (Date should have DD, MM, YYYY and use structure within structure)
iii. Account number
iv. Balance
Apply the following operation on it.
1. Print the names of all the customers having balance less than $200.
2. Add $100 in the balance of all the customers having more than $1000 in their
balance and then print the detail of those customers only with the
incremented value of their balance.*/

#include <stdio.h>
#include <stdlib.h>
struct employee
{
    struct name
    {
        char fname[10];
        char mname[10];
        char lname[10];
    }name;
    struct dob
    {
        int dd;
        int mm;
        int yyyy;
    }dob;
    unsigned long acc;
    int bal;
};
typedef struct employee emp;
void main()
{
    int n,i,j;
    printf("Enter the no. of employees : ");
    scanf("%d",&n);
    emp *e=(emp *)malloc(n*sizeof(emp));
    for(i=0; i<n; i++)
    {
        printf("Employee %d :\n",i+1);
        printf("Enter first name followed by middle & last name :\n");
        scanf("%s %s %s",&e[i].name.fname,&e[i].name.mname,&e[i].name.lname);
        printf("Enter date of birth in DD MM YYYY format :\n");
        scanf("%d %d %d",&e[i].dob.dd,&e[i].dob.mm,&e[i].dob.yyyy);
        printf("Enter account no. : ");
        scanf("%lu",&e[i].acc);
        printf("Enter balance (in dollars): ");
        scanf("%d",&e[i].bal);
    }
    printf("The names of employees with balance less than $200 :\n");
    j=1;
    for(i=0; i<n; i++)
    {
        if(e[i].bal < 200)
        {
            printf("%d. %s %s %s\n",j++,e[i].name.fname,e[i].name.mname,e[i].name.lname);
        }
    }
    printf("\n\n");
    j=1;
    printf("Customers having balance more than $1000 are :\n");
    for(i=0; i<n; i++)
    {
        if(e[i].bal > 1000)
        {
            e[i].bal+=100;
            printf("%d. Name : %s %s %s\n",j++,e[i].name.fname,e[i].name.mname,e[i].name.lname);
            printf("DOB : %d-%d-%d\n",e[i].dob.dd,e[i].dob.mm,e[i].dob.yyyy);
            printf("Account number : %lu",e[i].acc);
            printf("\nBalance : %d\n",e[i].bal);
        }
    }