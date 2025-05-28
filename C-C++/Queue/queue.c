#include <stdio.h>
#define MAX 5
int Queue[MAX], FRONT = -1, REAR = -1;
void enqueue()
{
    int data;
    if (REAR == MAX - 1)
    {
        printf("Overflow\n");
    }
    else if (REAR == -1 && FRONT == -1)
    {
        printf("Enter the item to insert\n");
        scanf("%d", &data);
        FRONT = REAR = 0;
        Queue[REAR] = data;
    }
    else
    {
        printf("Enter the item to insert\n");
        scanf("%d", &data);
        REAR++;
        Queue[REAR] = data;
    }
}
void dequeue()
{
    int value;
    if (FRONT == -1)
    {
        printf("Underflow\n");
    }
    else if (FRONT == REAR)
    {
        value = Queue[FRONT];
        printf("Item removed successfully , removed item - %d\n", value);
        FRONT = REAR = -1;
    }
    else
    {
        value = Queue[FRONT];
        printf("Item removed successfully , removed item - %d\n", value);
        FRONT++;
    }
}
void display()
{
    if (FRONT == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}
void main()
{
    int choice;
    char y;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Choose an option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:

            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Exit....\n");
            break;
        }
        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &y);

    } while (y == 'Y' || y == 'y');
}