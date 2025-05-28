#include <stdio.h>
#define MAX 5
int Stack[MAX], top = -1;
void push()
{
    int data;
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter the item to insert\n");
        scanf("%d", &data);
        Stack[++top] = data;
    }
}
void pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        value = Stack[top];
        top--;
        printf("Item removed successfully , removed item - %d\n", value);
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack Empty!\n");
    }
    else
    {
        printf("Stack elements are : ");
        for (int i = top; i >= 0; i--)
        {

            printf("%d ", Stack[i]);
        }
    }
    printf("\n");
}
void peek()
{
    if (top == -1)
    {
        printf("Stack Empty!\n");
    }
    else
    {
        printf("%d", Stack[top]);
    }
}
void main()
{
    int choice;
    char y;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Choose an option : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:

            pop();
            break;
        case 3:

            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Exit....");
            break;
        }
        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &y);

    } while (y == 'Y' || y == 'y');
}