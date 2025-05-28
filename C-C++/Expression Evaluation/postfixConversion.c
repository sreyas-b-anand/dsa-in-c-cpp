#include <stdio.h>
#include <stdbool.h>
int top = -1;
char Stack[100];
char expression[100], postfix[100];
bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}
void push(char c)
{
    if (top == 100 - 1)
    {
        return;
    }
    Stack[++top] = c;
}
char pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return Stack[top--];
    }
}
bool isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return true;
    }
    return false;
}
char peek(){
    return Stack[top];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;

        break;

    default:
        return -1;
    }
}
void convert(){
    int i =0 , j= 0;
    while(expression[i] != '\0'){
        if(expression[i] == '('){
            push(expression[i++]);
            
        }
        else if(isOperand(expression[i])){
            postfix[j++]=expression[i++];
            
        }
        else if(expression[i] == ')'){
            while (!isEmpty() && peek() != '(' )
            {
                postfix[j++] = pop();
            }
            pop();
            i++;
        }else{
            while(!isEmpty() && precedence(expression[i]) <= precedence(peek())){
                postfix[j++] = pop();
            }
            push(expression[i++]);
        }
    }
    while(expression[i] != '\0' ){
        postfix[j++] = expression[i++];
    }
}
void main(){
    printf("Enter expression : ");
    fgets(expression , 20 , stdin);
    convert();
    printf("%s" , postfix);
}