/* DOUBLY LINKED LIST */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL;
void insertend(int n)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
void deletefront()
{
    struct node *temp;
    if(head==NULL)
        printf("LIST IS EMPTY\n");
    else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void insertfront(int n)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void deleteend()
{
    struct node *temp,*t;
    if(head==NULL)
        printf("LIST IS EMPTY\n");
    else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        t=temp->prev;
        t->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}
int main()
{
    int choice,n;
    void insertend(int n);
    void deletefront();
    void display();
    while(1)
    {
        printf("1. Insert at end\n");
        printf("2. Delete at front\n");
        printf("3. Display the resulting list\n");
        printf("4. Insert at front\n");
        printf("5. Delete at end\n");
        printf("6. To Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d",&n);
            insertend(n);
            break;
        case 2:
            deletefront();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter the number:");
            scanf("%d",&n);
            insertfront(n);
            break;
        case 5:
            deleteend();
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
