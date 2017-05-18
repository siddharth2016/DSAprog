/* SIMPLE STACK */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top,capacity;
    char *array;
};
struct stack* create(int cap)
{
    struct stack *stc;
    stc=malloc(sizeof(struct stack));
    stc->top=-1;
    stc->capacity=cap;
    stc->array=malloc(sizeof(char)*cap);
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
void push(struct stack *stc,char x)
{
    if(!isfull(stc))
    {
        stc->top++;
        stc->array[stc->top]=x;
    }
}
char pop(struct stack *stc)
{
    char c;
    if(!isempty(stc))
    {
        c=stc->array[stc->top];
        stc->top--;
        return c;
    }
}
int main()
{
    char A[100],chr,ch;
    int i=0;
    struct stack *s;
    struct stack* create(int cap);
    int isfull(struct stack *stc);
    int isempty(struct stack *stc);
    void push(struct stack *stc,char x);
    char pop(struct stack *stc);
    s=create(100);
    scanf("%s",A);
    for(i=0;i<strlen(A);i++)
    {
        chr=A[i];
        if('A'<=chr && 'Z'>=chr)
            push(s,chr);
        else if(chr=='*')
        {
            ch=pop(s);
            printf("%c",ch);
        }
    }
    return 0;
}
