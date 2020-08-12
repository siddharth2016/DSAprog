/* STACK OPERATIONS*/
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int capacity;
    int *array;
};
struct stack* create(int cap)
{
    struct stack *stc;
    stc=malloc(sizeof(struct stack));
    stc->top=-1;
    stc->capacity=cap;
    stc->array=malloc(sizeof(int)*cap);
    return stc;
}
int isfull(struct stack *stc)
{
    if(stc->top==stc->capacity-1)
        return 1;
    else
        return 0;
}
int isempty(struct stack *stc)
{
    if(stc->top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack *stc,int x)
{
    if(!isfull(stc))
    {
        stc->top++;
        stc->array[stc->top]=x;
    }
    else
        printf("Stack overflow\n");
}
int pop(struct stack *stc)
{
    int ch;
    if(isempty(stc))
        {printf("Stack underflow\n");
        return;}
    else
    {
        ch=stc->array[stc->top];
        stc->top--;
        return ch;
    }
}
int main()
{
    int choice,i=1,a,y;
    struct stack* create(int cap);
    int isfull(struct stack *stc);
    int isempty(struct stack *stc);
    void push(struct stack *stc,int x);
    int pop(struct stack *stc);
    struct stack *s;
    s=create(20);
    while(i==1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d",&a);
            push(s,a);
            break;
        case 2:
            y=pop(s);
            printf("%d\n",y);
            break;
        case 3:
            i=0;
            break;
        }
    }
    return 0;
}
