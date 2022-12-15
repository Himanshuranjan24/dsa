/*4. Let one student structure is having following data members.
a. Roll number (int)
b. Name (string)
c. Marks of 5 subjects (array of int)
d. Percentage of mark (float)
e. Grade (Char)
WAP to do the following work (use function)
i. Take students information (User will give the input for members like roll number,
name &amp; marks of 5 subjects)
ii. Find the percentage of mark and grade from the percentage for each student and
store the value in appropriate student’s data member’s entry.
iii. Sort*/

#include <stdio.h>
#define total 500
struct student
{
    int roll;
    char name[20];
    int marks[5];
    float sum,percent;
    char grade;
};
typedef struct student student;
void percent(student *a);
void grade(student *b);
void sort(student *a,int n);
void main()
{
    int n,i,j;
    printf("Enter the no. of students : ");
    scanf("%d",&n);
    student s[n];
    for(i=0; i<n; i++)
    {
        printf("Student %d :\n",i+1);
        printf("Enter roll, name & marks in 5 subjects out of 100 respectively :\n");
        scanf("%d %s",&s[i].roll,&s[i].name);
        s[i].sum=0;
        for(j=0; j<5; j++)
        {
            scanf("%d",&s[i].marks[j]);
        }
        percent(&s[i]);
        printf("Percentage is %.2lf\n",s[i].percent);
        grade(&s[i]);
        printf("Grade is %c\n",s[i].grade);
    }
        sort(s,n);
        for(i=0; i<n; i++)
        {
            printf("%d %s",s[i].roll,s[i].name);
            for(j=0;j<5;j++)
            printf("%d",s[i].marks[j]);
            printf("%.2lf %c",s[i].percent,s[i].grade);
        }
}
void percent(student *a)
{
    a->sum=0;
    for(int i=0; i<5;i++)
    {
        a->sum+=a->marks[i];
    }
    a->percent=a->sum/total*100;
}
void grade(student *b)
{
    if(b->percent>=90)
    b->grade='O';
    else if(b->percent>=80)
    b->grade='E';
    else if(b->percent>=70)
    b->grade='A';
    else if(b->percent>=60)
    b->grade='B';
    else if(b->percent>=50)
    b->grade='C';
    else if(b->percent>=40)
    b->grade='D';
    else
    b->grade='F';
}
void sort(student *a,int n)
{
    int i,j;
    student temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].percent<a[j].percent)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
