/* INFIX TO POSTFIX */
// SIDDHARTH CHANDRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int capacity;
    char *array;
};
struct stack* create(int cap)           //Function for returning a memory location of created stack
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
    char item;
    if(!isempty(stc))
    {
        item=stc->array[stc->top];
        stc->top--;
        return item;
    }
}
int priority(char a)            //function for checking the priority of the operators
{
    if(a=='/')
        return 5;
    else if(a=='*')
        return 4;
    else if(a=='+')
        return 3;
    else if(a=='-')
        return 2;
    else if(a=='(')
            return 1;
}
int main()
{
    int j=0,i=0;
    char post[50]={'0'},A[50],chr,ch;
    struct stack *s;
    struct stack* create(int cap);
    int isfull(struct stack *stc);
    int isempty(struct stack *stc);
    void push(struct stack *stc,char x);
    char pop(struct stack *stc);
    s=create(50);
    gets(A);
    while(A[i]!='\0')
    {
        chr=A[i];

        if((chr>='a' && chr<='z') || (chr>='A' && chr<='Z'))
        {
            post[j]=chr;
            j++;
        }
        else if(chr=='(')
            push(s,chr);
        else if(chr==')')
        {
            while(s->array[s->top]!='(')
            {
                ch=pop(s);
                post[j]=ch;
                j++;
            }
            pop(s);
        }
        else
        {
            while(priority(s->array[s->top])>=priority(chr) && s->top!=-1)
            {
                ch=pop(s);
                post[j]=ch;
                j++;
            }
            push(s,chr);
        }
        i++;
    }
    while(!isempty(s))
    {
        ch=pop(s);
        post[j]=ch;
        j++;
    }
    post[j]='\0';
    printf("%s",post);
    return 0;
}
