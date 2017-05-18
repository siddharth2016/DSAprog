/* LINKED LIST OPERATIONS */
// SIDDHARTH CHANDRA
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node* create()
{
   struct node *p;
   p=(struct node *)malloc(sizeof(struct node));
   return p;
}
void insertend(int x)
{
    struct node *temp,*t;
    temp=create();
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}
void deletefront()
{
    struct node *temp;
    if(head==NULL)
        printf("\nEmpty list\n");
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
        printf("\nEmpty list\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int i=1,c,n;
    struct node* create();
    void insertend(int x);
    void deletefront();
    void display();
    while(1)
    {
        printf("\n1. Insert at end\n");
        printf("2. Delete at front\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter the element: ");
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
            exit(0);
        default:
            printf("Wrong input error...\n");
            break;
        }
    }
    return 0;
}
