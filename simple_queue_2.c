/* simple queue 2 */
#include <stdio.h>
#include <string.h>
struct queue
{
        int front;
        int rear;
        int capacity;
        char array[100];
};
int isempty(struct queue *q)
{
    if(q->front==-1)
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
void enqueue(struct queue *q,char x)
{
    if(!isfull(q))
    {
        q->rear++;
        q->array[q->rear]=x;
        if(q->front==-1)
            q->front=q->rear;
    }
}
char dequeue(struct queue *q)
{
    char ch;
    if(q->front==q->rear)
    {
        ch=q->array[q->front];
        q->front=-1;
        q->rear=-1;
    }
    else if(!isempty(q))
    {
        ch=q->array[q->front];
        q->front++;
    }
    return ch;
}
int main()
{
    struct queue q;
    char A[100],chr;
    int i=0;
    int isempty(struct queue *q);
    int isfull(struct queue *q);
    void enqueue(struct queue *q,char x);
    char dequeue(struct queue *q);
    q.front=-1;
    q.rear=-1;
    q.capacity=100;
    scanf("%s",A);
    while(A[i]!='\0')
    {
        chr=A[i];
        if('A'<=chr && 'Z'>=chr)
            enqueue(&q,chr);
        else if(chr=='*')
        {
            printf("%c",dequeue(&q));
        }
        i++;
    }
    return 0;
}
