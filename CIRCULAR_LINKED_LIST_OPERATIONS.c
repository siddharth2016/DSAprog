/* CIRCULAR LINKED LISTS OPERATIONS */
#include <stdio.h>
#include <stdlib.h>

typedef struct CLLnode
{
    int data;
    struct CLLnode *next;
}node;
node *head=NULL;
void insertend(int data)
{
    node *temp,*newnode;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=newnode;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;
        newnode->next=head;
        temp->next=newnode;
    }
}

void deleteend()
{
    node *temp,*t;
    temp=head;
    if(head==NULL)
        printf("List is Empty\n");
    else
    {
        t=head;
        while(temp->next!=head)
        {
            t=temp;
            temp=temp->next;
        }
        t->next=temp->next;
        if(temp==head)
            head=NULL;
        else
            free(temp);
    }
}

void display()
{
    node *temp;
    temp=head;
    if(head==NULL)
        printf("List is Empty\n");
    else
    {
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
        printf("\n");
    }
}

int main()
{
    int key;
    int choice;
    void display();
    void deleteend();
    void insertend(int data);
    printf("1) Insert at end\n2) Delete at end\n3) Display\n4) Exit\n");
    printf("Enter the choice : ");
    scanf("%d",&choice);
    while(1)
    {
        switch(choice)
        {
        case 1:
            scanf("%d",&key);
            insertend(key);
            break;
        case 2:
            deleteend();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }

        printf("1) Insert at end\n2) Delete at end\n3) Display\n4) Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
    }
    return 0;
}
