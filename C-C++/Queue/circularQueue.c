// By using structerd array

#include <stdio.h>
#define MAX 5
int FRONT = -1, REAR = -1;
struct Q
{
    int item;
    int priority;
} Queue[MAX];
void enqueue()
{
    int data, p;
    if (FRONT == 0 && REAR == MAX - 1)
    {
        printf("Overflow\n");
    }
    else if (REAR == -1 && FRONT == -1)
    {
        printf("Enter the item and its priority to insert\n");
        scanf("%d %d", &data, &p);
        FRONT = REAR = 0;
        Queue[REAR].item = data;
        Queue[FRONT].priority = p;
    }
    else if (REAR == MAX - 1)
    {
        int i;
        printf("Enter the item and its priority to insert\n");
        scanf("%d %d", &data, &p);
        // shifting left
        for (i = FRONT; i <= REAR; i++)
        {
            Queue[i - 1] = Queue[i];
        }
        FRONT--;
        REAR--;
        // finding the location
        for (i = REAR; i >= FRONT; i--)
        {
            if (Queue[i].priority < p)
                break;
        }
        int loc = i + 1;
        // shifting right
        for (i = REAR; i >= loc; i--)
        {
            Queue[i + 1] = Queue[i];
        }
        Queue[REAR].item = data;
        Queue[REAR].priority = p;
        REAR++;
    }
    else
    {
        int i;
        printf("Enter the item and its priority to insert\n");
        scanf("%d %d", &data, &p);
        // finding the location
        for (i = REAR; i >= FRONT; i--)
        {
            if (Queue[i].priority < p)
                break;
        }
        int loc = i + 1;
        // shifting right
        for (i = REAR; i >= loc; i--)
        {
            Queue[i + 1] = Queue[i];
        }
        Queue[REAR].item = data;
        Queue[REAR].priority = p;
        REAR++;
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
        value = Queue[FRONT].item;
        printf("Item removed successfully , removed item - %d\n", value);
        FRONT = REAR = -1;
    }
    else
    {
        value = Queue[FRONT].item;
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
        printf("Queue elements\n");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", Queue[i].item);
        }
        printf("\n");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", Queue[i].priority);
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