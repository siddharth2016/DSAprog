/* ALTER SPLIT */
// SIDDHARTH CHANDRA
#include <stdio.h>
#include <stdlib.h>
struct node1
{
    char data1;
    struct node1 *next1;
};
struct node2
{
    char data2;
    struct node2 *next2;
};
struct node3
{
    char data3;
    struct node3 *next3;
};
struct node1 *head1=NULL;
struct node2 *head2=NULL;
struct node3 *head3=NULL;

struct node1* create1()
{
    struct node1 *p;
    p=(struct node1 *)malloc(sizeof(struct node1));
    return p;
}
struct node2* create2()
{
    struct node2 *p;
    p=(struct node2 *)malloc(sizeof(struct node2));
    return p;
}
struct node3* create3()
{
    struct node3 *p;
    p=(struct node3 *)malloc(sizeof(struct node3));
    return p;
}

void insert1(char x)
{
    struct node1 *temp,*t;
    temp=create1();
    temp->data1=x;
    temp->next1=NULL;
    if(head1==NULL)
        head1=temp;
    else
    {
        t=head1;
        while(t->next1!=NULL)
            t=t->next1;
        t->next1=temp;
    }
}
void insert2(char x)
{
    struct node2 *temp,*t;
    temp=create2();
    temp->data2=x;
    temp->next2=NULL;
    if(head2==NULL)
        head2=temp;
    else
    {
        t=head2;
        while(t->next2!=NULL)
            t=t->next2;
        t->next2=temp;
    }
}
void insert3(char x)
{
    struct node3 *temp,*t;
    temp=create3();
    temp->data3=x;
    temp->next3=NULL;
    if(head3==NULL)
        head3=temp;
    else
    {
        t=head3;
        while(t->next3!=NULL)
            t=t->next3;
        t->next3=temp;
    }
}
char delete1()
{
    struct node1 *temp;
    char t;
    temp=head1;
    t=temp->data1;
    head1=head1->next1;

    return t;
}
void display2()
{
    struct node2 *temp;
    temp=head2;
    while(temp!=NULL)
    {
        printf("%c\n",temp->data2);
        temp=temp->next2;
    }
}
void display3()
{
    struct node3 *temp;
    temp=head3;
    while(temp!=NULL)
    {
        printf("%c\n",temp->data3);
        temp=temp->next3;
    }
}
void aftersplit()
{
    struct node1 *temp;
    char p,q;
    temp=head1;
    while(temp!=NULL)
    {
        p=delete1();
        insert2(p);
        if(head1==NULL)
            break;
        q=delete1();
        insert3(q);
        temp=head1;
    }
}
int main()
{
    int n,i;
    char a;
    struct node1* create1();
    struct node2* create2();
    struct node3* create3();
    void insert1(char x);
    void insert2(char x);
    void insert3(char x);
    char delete1();
    void display2();
    void display3();
    void aftersplit();

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("\n%c",&a);
        insert1(a);
    }
    aftersplit();
    display2();
    display3();
    return 0;
}
