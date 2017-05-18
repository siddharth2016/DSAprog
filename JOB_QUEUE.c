/* JOB QUEUE */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct queue
{
    int front,rear;
    int array1[100];
    int array2[100];
};
int isempty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    else
        return 0;
}
void push(struct queue *q,int jobid,int servtime)
{
    if(q->rear==-1)
    {
        q->rear++;
        q->array1[q->rear]=jobid;
        q->array2[q->rear]=servtime;
        q->front=q->rear;
    }
    else
    {
        q->rear++;
        q->array1[q->rear]=jobid;
        q->array2[q->rear]=servtime;
    }
}
int pop(struct queue *q)
{
    int temp;
    if(q->front==q->rear)
    {
        temp=q->array1[q->front];
        q->front=-1;
        q->rear=-1;
        return temp;
    }
    else
    {
        temp=q->array1[q->front];
        q->front++;
        return temp;
    }
}
int main()
{
    char A[50][50];
    int i=0,j=0,n=0,id=0,time=0,a=0;

    struct queue q;
    int isempty(struct queue *q);
    void push(struct queue *q,int jobid,int servtime);
    int pop(struct queue *q);

    q.front=-1;
    q.rear=-1;

    printf("Enter number of jobs: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter id:");
        scanf("%d",&id);
        printf("\nEnter name:");
        scanf("%s",A[i]);
        printf("\nEnter time:");
        scanf("%d",&time);
        push(&q,id,time);
    }

    printf("Enter time elapsed: ");
    scanf("%d",&time);

    j=q.array2[q.front];
    while(j<=time)
    {
        a=pop(&q);
        j=j+q.array2[q.front];
    }

    if(!isempty(&q))
    {
        for(i=q.front;i<=q.rear;i++)
        {
            printf("%d\n",q.array1[i]);
            printf("%s\n",A[i]);
        }
    }
    else
        printf("No job found");
    return 0;
}
