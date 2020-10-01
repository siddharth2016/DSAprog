#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;
};

struct node *start=NULL;

struct node* createnode()
{
struct node *n;
n=(struct node)malloc(sizeof(struct node));
return n;
}

void insertnode()
{
struct node *temp, *t;
temp=createnode();
scanf("%d",&temp->info);
temp->link=NULL;
if(START==NULL)
{
 START=temp;
}
else
{
 t=START;
while(t->link!=NULL)
{
t=t->link;
}
t->link=temp;
}
}


void deletenode()
{
    struct node *r;
    if(START==NULL)
    {
        printf("List is empty");
    }
    else
    {
    r=START;
    START=START->link;
    free(r);
    }
}

void viewlist()
{

}
