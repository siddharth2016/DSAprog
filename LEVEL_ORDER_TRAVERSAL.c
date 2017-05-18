/* level order traversal */
#include <stdio.h>
#include <stdlib.h>
typedef struct binary_tree
{
    int data;
    struct binary_tree *left,*right;
}node;
typedef struct queue
{
    int capacity,rear,front;
    node* *array;
}q;
q* createq(int n)
{
    q* temp;
    temp=malloc(sizeof(q));
    temp->capacity=n;
    temp->rear=-1;
    temp->front=-1;
    temp->array=malloc(sizeof(node)*n);
    return temp;
}

node *create(int n)
{
    node* temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert(node *root,node *neww)
{
    if(root->data>neww->data)
    {
        if(root->left==NULL)
            root->left=neww;
        else
            insert(root->left,neww);
    }
    else if(root->data<neww->data)
    {
        if(root->right==NULL)
            root->right=neww;
        else
            insert(root->right,neww);
    }
}
int isempty(q* Q)
{
    if(Q->front==-1)
        return 1;
    else
        return 0;
}
int isfull(q* Q)
{
    if(Q->rear==Q->capacity-1)
        return 1;
    else
        return 0;
}
void enqueue(q* Q,node* neww)
{
    if(!isfull(Q))
    {
        Q->rear++;
        Q->array[Q->rear]=neww;
        if(Q->front==-1)
            Q->front=Q->rear;
    }
}
node* dequeue(q* Q)
{
    node* neww;
    if(!isempty(Q))
    {
        neww=Q->array[Q->front];
        if(Q->front==Q->rear)
        {
            Q->front=-1;
            Q->rear=-1;
        }
        else
            Q->front++;
        return neww;
    }
}

void level(node* root)
{
    node* temp;
    q* Q;
    Q=createq(20);
    if(root)
    {
        enqueue(Q,root);
        while(!isempty(Q))
        {
            temp=dequeue(Q);
            printf("%d ",temp->data);
            if(temp->left)
                enqueue(Q,temp->left);
            if(temp->right)
                enqueue(Q,temp->right);
        }
    }
    else
        printf("First enter the root node!!\n");
}
int main()
{
    node *root=NULL,*newnode;
    int i,n,a;
    printf("Enter the number of elements in the BT tree: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        newnode=create(a);
        if(root==NULL)
            root=newnode;
        else
            insert(root,newnode);
    }
    level(root);
    return 0;
}
