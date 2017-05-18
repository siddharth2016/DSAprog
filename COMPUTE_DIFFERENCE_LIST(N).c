/* COMPUTE DIFFERENCE LIST */
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
struct node1 *head1=NULL;
struct node2 *head2=NULL;
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
struct node1* search1(int k)
{
    struct node1 *temp;
    temp=head1;
    if(head1->data1==k)
        return head1;
    while(temp->next1!=NULL)
    {
        if(temp->next1->data1==k)
            return temp;
        temp=temp->next1;
    }
    return NULL;
}
void delete1(int k)
{
    struct node1 *temp;
    struct node1 *t;
    temp=search1(k);
    if(temp!=NULL)
    {if(temp==head1)
    {
        if(temp->next1==NULL)
        {
            head1=NULL;
            free(temp);
        }
        else if(temp->next1->data1==k)
        {
            t=temp->next1;
            temp->next1=t->next1;
            free(t);
        }
        else
        {
            t=head1;
            head1=head1->next1;
            free(t);
        }
    }
    else
    {
        t=temp->next1;
        temp->next1=t->next1;
        free(t);
    }
    }
}
void display()
{
    struct node1 *temp;
    temp=head1;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data1);
        temp=temp->next1;
    }
}
void compute()
{
    struct node2 *temp;
    struct node1 *t;
    temp=head2;
    while(temp!=NULL)
    {
        delete1(temp->data2);
        temp=temp->next2;
    }
}
int main()
{
    int i,a,n,m;
    struct node1* create1();
    struct node2* create2();
    void insert1(int x);
    void insert2(int x);
    struct node1* search1(int k);
    void delete1(int k);
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

    /*t=head2;
    while(t!=NULL)
    {
        temp=search1(t->data2);
        if(temp==NULL)
            t=t->next2;
        else
        {
            delete1(temp);
            t=t->next2;
        }
    }*/
    compute();
    if(head1==NULL)
        printf("List is empty");
    else
        display();
    return 0;
}
