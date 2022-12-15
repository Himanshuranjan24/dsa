/*2. WAP to implement the following function on the time value where the time is
one structure element containing hour, minutes and second as the data member.
i. Addition of 2 time value
ii. Subtraction of 2 time value
Note: Check the validity of result after operation*/

#include <stdio.h>
struct time
{
    int hours;
    int minutes;
    int seconds;
};
typedef struct time time;
time addition(time a, time b)
{
    time t_t={0,0,0};
    t_t.seconds=a.seconds+b.seconds;
    if(t_t.seconds>=60)
    {
        t_t.minutes += t_t.seconds/60;
        t_t.seconds%=60;
    }
    t_t.minutes += a.minutes+b.minutes;
    if(t_t.minutes>=60)
    {
        t_t.hours +=t_t.minutes/60;
        t_t.minutes%=60;
    }
    t_t.hours+=a.hours+b.hours;
    return t_t;
}
time difference(time a, time b)
{
    time r = {0,0,0};
    if(a.seconds < b.seconds)
    {
        a.seconds += 60;
        a.minutes--;
    }
    r.seconds=a.seconds-b.seconds;
    if(a.minutes<b.minutes)
    {
        a.minutes+=60;
        a.hours--;
    }
    r.minutes=a.minutes-b.minutes;
    r.hours=a.hours-b.hours;
    return r;
}
void main()
{
    time t1,t2,sum,diff;
    printf("Enter the first time value :\n");
    scanf("%d %d %d",&t1.hours,&t1.minutes,&t1.seconds);
    printf("Enter the second time value :\n");
    scanf("%d %d %d",&t2.hours,&t2.minutes,&t2.seconds);
    sum=addition(t1,t2);
    diff=difference(t1,t2);
    printf("Addition of two time values is %d hrs %d min %d sec.\n",sum.hours,sum.minutes,sum.seconds);
    printf("Subtraction of two time values is %d hrs %d min %d sec.\n",diff.hours,diff.minutes,diff.seconds);

}
