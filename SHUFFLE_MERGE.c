/* SHUFFLE MERGE */
// SIDDHARTH CHANDRA
#include <stdio.h>
#include <stdlib.h>
struct node1
{
    int data1;
    struct node1 *next1;
};
struct node2
{
    int data2;
    struct node2 *next2;
};
struct node3
{
    int data3;
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
void insert1(int x)
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
void insert2(int x)
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
int delete1()
{
    struct node1 *temp;
    temp=head1;
    head1=head1->next1;
    return temp->data1;
}
int delete2()
{
    struct node2 *temp;
    temp=head2;
    head2=head2->next2;
    return temp->data2;
}
void insert3(int x)
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
void display()
{
    struct node3 *temp;
    temp=head3;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data3);
        temp=temp->next3;
    }
}

int main()
{
    int n,m,i,a,p1,p2;
    struct node1* create1();
    struct node2* create2();
    struct node3* create3();
    void insert1(int x);
    void insert2(int x);
    void insert3(int x);
    void display();

    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        insert1(a);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        insert2(a);
    }

    if(n>m)
    {
        for(i=0;i<m;i++)
        {
            p1=delete1();
            insert3(p1);
            p2=delete2();
            insert3(p2);
        }
        for(i=m;i<n;i++)
        {
            p1=delete1();
            insert3(p1);
        }
    }
    else if(m>n)
    {
        for(i=0;i<n;i++)
        {
            p1=delete1();
            insert3(p1);
            p2=delete2();
            insert3(p2);
        }
        for(i=n;i<m;i++)
        {
            p2=delete2();
            insert3(p2);
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            p1=delete1();
            p2=delete2();
            insert3(p1);
            insert3(p2);
        }
    }
    display();
    return 0;
}
