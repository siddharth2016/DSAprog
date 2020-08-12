/* POSTFIX EVALUATION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top,capacity;
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
}
int pop(struct stack *stc)
{
    int c;
    if(!isempty(stc))
    {
        c=stc->array[stc->top];
        stc->top--;
        return c;
    }
}
int main()
{
    char A[100],chr;
    int i=0,j,cr,a,b,c;
    struct stack *s;
    struct stack* create(int cap);
    int isfull(struct stack *stc);
    int isempty(struct stack *stc);
    void push(struct stack *stc,int x);
    int pop(struct stack *stc);
    s=create(100);
    scanf("%s",A);
    while(A[i]!='\0')
    {
        chr=A[i];
        if('1'<=chr && '9'>=chr)
        {
            j=(int)chr;
            j=j-48;
            push(s,j);
        }
        else
        {
            a=pop(s);
            b=pop(s);
            switch(chr)
            {
            case '+':
                c=b+a;
                break;
            case '-':
                c=b-a;
                break;
            case '*':
                c=b*a;
                break;
            case '/':
                c=b/a;
                break;
            }
            push(s,c);
        }
        i++;
    }
    cr=pop(s);
    printf("%d",cr);
    return 0;
}
