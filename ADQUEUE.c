/* ADQUEUE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Q
{
    int front,rear;
    int capacity;
    int *array;
}queue;

queue* create(int key)
{
    queue *q;
    q=malloc(sizeof(queue));
    q->front=-1;
    q->rear=-1;
    q->capacity=key;
    q->array=malloc(sizeof(int)*key);
    return q;
}

int isempty(queue *q)
{
    if(q->front==-1)
        return 1;
    else
        return 0;
}

int isfull(queue *q)
{
    if(q->rear==q->capacity)
        return 1;
    else
        return 0;
}

void adenqueue(int key,queue *q)
{
    if(!isfull(q))
    {
        q->rear++;
        q->array[q->rear]=key;
        if(q->front==-1)
            q->front=q->rear;
    }
}

void ddequeue(queue *q)
{
    if(!isempty(q))
    {
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->front++;
    }
}

void areverse(queue *q)
{
    int i,temp,n;
    n=q->rear+1;
    for(i=q->front;i<=(q->rear)/2;i++)
    {
        temp=q->array[i];
        q->array[i]=q->array[n-1-i];
        q->array[n-1-i]=temp;
    }
}

int main()
{
    char choice;
    char A[20],B[20]="Yes";
    int m,x=1,i=0;
    queue *Q1,*Q2;

    Q1=create(4);
    Q2=create(4);
    /*printf("Enter the choice: ");
    scanf("%c",&choice);*/
    while(strcmp(B,"No")!=0)
    {
    //printf("Enter the choice: ");
    scanf("%c",&choice);
    if(choice=='a')
    {
        //printf("Enter the element to be inserted: ");
        scanf("%d",&m);
        //printf("Enter the Queue: ");
        scanf("%s",A);
        if(strcmp(A,"Q1")==0)
            adenqueue(m,Q1);
        else if(strcmp(A,"Q2")==0)
            adenqueue(m,Q2);
        //printf("want the choice: ");
        scanf("%s",B);
    }

    if(choice=='b')
    {
        //printf("Enter the queue: ");
        scanf("%s",A);
        if(strcmp(A,"Q1")==0)
            ddequeue(Q1);
        else if(strcmp(A,"Q2")==0)
            ddequeue(Q2);
        //printf("want the choice: ");
        scanf("%s",B);
    }

    if(choice=='c')
    {
        //printf("Enter the queue: ");
        scanf("%s",A);
        if(strcmp(A,"Q1")==0)
            areverse(Q1);
        else if(strcmp(A,"Q2")==0)
            areverse(Q2);
        //printf("want the choice: ");
        scanf("%s",B);
    }
    }

    if(!isempty(Q1) && !isfull(Q1))
    {
        for(i=Q1->front;i<=Q1->rear;i++)
            printf("%d\n",Q1->array[i]);
    }
    else if(isempty(Q1))
        printf("Queue Q1 is empty\n");
    else
        printf("Queue Q1 is full\n");

    if(!isempty(Q2) && !isfull(Q2))
    {
        for(i=Q2->front;i<=Q2->rear;i++)
            printf("%d\n",Q2->array[i]);
    }
    else if(isempty(Q2))
        printf("Queue Q2 is empty\n");
    else
        printf("Queue Q2 is full\n");

    return 0;
}

