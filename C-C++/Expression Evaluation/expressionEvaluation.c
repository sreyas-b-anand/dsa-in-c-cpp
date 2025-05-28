#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
int stack[MAX];

int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack[++top] = data;
    }
}

int pop()
{
    if (isEmpty())
    {

        return 0;
    }
    else
    {
        return stack[top--];
    }
}
int evaluate(char postfix[])
{
    int i = 0, result, num, operand1, operand2;
    
   
}
int main()
{
    char expression[20];
    printf("Enter the expression : ");
    fgets(expression, 20, stdin);
    evaluate(expression);
}