/* QUEUE OPERATIONS */
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front,rear;
    int capacity;
    int *array;
};
struct queue* create(int cap)
{
    struct queue *q;
    q=malloc(sizeof(struct queue));
    q->front=0;
    q->rear=-1;
    q->capacity=cap;
    q->array=malloc(sizeof(int)*cap);
    return q;
}
int isempty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    else
        return 0;
}
int isfull(struct queue *q)
{
    if(q->rear==q->capacity-1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q,int n)
{
    if(!isfull(q))
    {
        q->rear++;
        q->array[q->rear]=n;
    }
    else
        printf("Queue overflow\n");
}
int dequeue(struct queue *q)
{
    int ch=0;
    if(q->front==q->rear)
    {
        ch=q->array[q->front];
        q->front=0;
        q->rear=-1;
        return ch;
    }
    else if(!isempty(q))
    {
        ch=q->array[q->front];
        q->front++;
        return ch;
    }
    else
        printf("Queue underflow\n");
        return;
}

int main()
{
    int x=1,y,choice=0,n=0;
    struct queue *q;
    struct queue* create(int cap);
    int isempty(struct queue *q);
    int isfull(struct queue *q);
    void enqueue(struct queue *q,int n);
    int dequeue(struct queue *q);
    q=create(10);
    while(x==1)
    {
        printf("Enter your choices:\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d",&n);
            enqueue(q,n);
            break;
        case 2:
            y=dequeue(q);
            printf("%d\n",y);
            break;
        case 3:
            x=0;
            break;
        }
    }
    return 0;
}
