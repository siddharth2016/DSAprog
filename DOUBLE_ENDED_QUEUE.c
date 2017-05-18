/* DOUBLE ENDED QUEUE */
#include <stdio.h>

struct queue
{
    int front;
    int rear;
    int capacity;
    int array[100];
};
int isempty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    else
        return 0;
}
void insertfront(struct queue *q,int x)
{
    int temp,i;
    if(q->front==-1)
    {
        q->front++;
        q->array[q->front]=x;
        q->rear=q->front;
    }
    else
    {
        for(i=q->rear;i>=q->front;i--)
            q->array[i+1]=q->array[i];
        q->array[q->front]=x;
        q->rear++;
    }
}
void insertrear(struct queue *q,int x)
{
    if(q->rear==-1)
    {
        q->rear++;
        q->array[q->rear]=x;
        q->front=q->rear;
    }
    else
    {
        q->rear++;
        q->array[q->rear]=x;
    }
}
int deletefront(struct queue *q)
{
    int temp,i;
    temp=q->array[q->front];
    for(i=q->front;i<q->rear;i++)
        q->array[i]=q->array[i+1];
    q->rear--;
    if(q->rear==-1)
        q->front=q->rear;
    return temp;
}
int deleterear(struct queue *q)
{
    int temp;
    temp=q->array[q->rear];
    q->rear--;
    if(q->rear==-1)
        q->front=q->rear;
    return temp;
}
void display(struct queue *q)
{
    int i;

    for(i=q->front;i<=q->rear;i++)
        printf("%d\n",q->array[i]);
}
int main()
{
    int v=1,n;
    char choice;
    struct queue q;
    void insertfront(struct queue *q,int x);
    void insertrear(struct queue *q,int x);
    int deletefront(struct queue *q);
    int deleterear(struct queue *q);
    void display(struct queue *q);
    q.front=-1;
    q.rear=-1;
    q.capacity=100;
    while(v=1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
        case 'a':
            scanf("%d",&n);
            insertfront(&q,n);
            break;
        case 'b':
            printf("%d\n",deletefront(&q));
            break;
        case 'c':
            scanf("%d",&n);
            insertrear(&q,n);
            break;
        case 'd':
            printf("%d\n",deleterear(&q));
            break;
        case 'e':
            if(!isempty(&q))
            display(&q);
            else
            {
              printf("Queue is empty");
              v=0;
            }
            break;
        }
        if(v==0)
            break;
    }
    return 0;
}
