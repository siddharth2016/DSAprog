#include<stdio.h>
#include<stdlib.h>
typedef struct arraystack
{
int top;
unsigned capacity;
int *array;
}arraystack;

arraystack* createstack(int cap)
{
arraystack *n;
n=(arraystack*)malloc(sizeof(arraystack));
n->capacity=cap;
n->top=-1;
n->array=malloc(sizeof(int)*n->capacity);
return n;
}

int isfull(arraystack *stack)
{
if(stack->array == stack->capacity-1)
return 1;
else
return 0;
}

int isempty(arraystack *stack)
{
if(stack->top == -1)
return 1;
else
return 0;
}


void push(arraystack *stack, int item)
{
if(!isfull(stack))
{
stack->top++;
stack->array[stack->top]=item;
}
}

int pop(arraystack *stack)
{
int item;
if(!isempty(stack));
{
item=stack->array[stack->top];
stack->top--;
return item;
}
return -1;
}

int main()
{
int choice, item;
arraystack *stack;
stack = createstack(4);


while(1)
{

printf("1. Push\n2. Pop\n3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter a number : ");
        scanf("%d",&item);
        push(stack,item);
        break;
case 2: item=pop(stack);
        if(item==1)
        {
        printf("Stack is empty");
        }
        else
        {
        printf("Popped value is %d",item);
        }
        break;
case 3: exit(0);
}
}
getch();
}
