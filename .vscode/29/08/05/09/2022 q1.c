/*WAP to take the input of your name character wise where each character should be one node of the
linked list.User will give the length of name including space.
Implement the following function on the above list.
1.Return the no. of vowels
2.Return the no. of words
3.Display the odd position character only.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char info;
    struct node *next;
};

void insert_end(struct node **start, char c);
int vowel(struct node *start);
int words(struct node *start);
void display_odd(struct node *start);

void main()
{
    int len;
    printf("Input the no. of characters in name including space : ");
    scanf("%d",&len);
    struct node *start = NULL;
    int i;
    char ch;
    for(i=0; i<=len; i++)
    {
        scanf(" %c",&ch);
        insert_end(&start, ch);
    }
    display_odd(start);
    int vc,wc;
    vc = vowel(start);
    printf("\nTotal no. of Vowels is %d\n",vc);
    wc = words(start);
    printf("\nTotal no. of Words is %d\n",wc);
}

void insert_end(struct node **start, char c)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = c;
    temp->next = NULL;
    if(*start == NULL)
    {
        *start = temp;
        return;
    }
    struct node *q = *start;
    for(; q->next != NULL; q=q->next);
    q->next = temp;
}

void display_odd(struct node *start)
{
    if(start == NULL)
    {
        return;
    }
    struct node *q = start;
    int count = 1;
    while(q!=NULL)
    {
        if(count%2 == 0)
        {
            printf("%c ",q->info);
        }
        q = q->next;
        count++;
    }
}

int vowel(struct node *start)
{
    int count=0;
    char s;
    while(start != NULL)
    {
        s = start->info;
        if(s=='A' || s=='a' || s=='E' || s=='e' || s=='I' || s=='i' || s=='O' || s=='o' || s=='U' || s=='u')
        {
            count++;
        }
        start = start->next;
    }
    return count;
}

int words(struct node *start)
{
    int count = 0 ;
    while(start != NULL)
    {
        if(start->info == ' ')
        count++;
        start = start->next;
    }
    return ++count;
}