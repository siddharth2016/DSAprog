/* SIMPLE QUEUE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    int front,rear,capacity;
    char *array;
};
struct queue* create(int cap)
{
    struct queue *qu;
    qu=malloc(sizeof(struct queue));
    qu->front=-1;
    qu->rear=-1;
    qu->array=malloc(sizeof(char)*cap);
    return qu;
}
int isempty(struct queue *qu)
{
    if(qu->front==-1)
        return 1;
    else
        return 0;
}
int isfull(struct queue *qu)
{
    if(qu->rear==qu->capacity-1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *qu,char x)
{
    if(!isfull(qu))
    {
        qu->rear++;
        qu->array[qu->rear]=x;
        if(qu->front==-1)
            qu->front=qu->rear;
    }
}
char dequeue(struct queue *qu)
{
    char ch;
    if(qu->front==qu->rear)
    {
        ch=qu->array[qu->front];
        qu->front=-1;
        qu->rear=-1;
        return ch;
    }
    else if(!isempty(qu))
    {
        ch=qu->array[qu->front];
        qu->front++;
        return ch;
    }
}
int main()
{
    char A[100],chr,p,B[100];
    struct queue *q;
    int i=0,j=0;
    struct queue* create(int cap);
    int isempty(struct queue *qu);
    int isfull(struct queue *qu);
    void enqueue(struct queue *qu,char x);
    char dequeue(struct queue *qu);
    q=create(100);
    scanf("%s",A);
    while(A[i]!='\0')
    {
        chr=A[i];
        if(('a'<=chr && 'z'>=chr) || ('A'<=chr && 'Z'>=chr))
        {
            enqueue(q,chr);
        }
        else
        {
            p=dequeue(q);
            B[j]=p;
            j++;
        }
        i++;
    }
    B[j]='\0';
    printf("%s",B);
    return 0;
}
