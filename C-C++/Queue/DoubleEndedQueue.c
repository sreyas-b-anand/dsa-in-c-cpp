#include <stdio.h>
#define MAX 7

int Deque[MAX], front = -1, rear = -1;

void enqueueFront()
{
    int item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Full!");
    }
    else if (front == -1)
    {
        printf("Enter the item to insert");
        scanf("%d", &item);
        front = 0;
        rear = 0;
        Deque[front] = item;
    }
    else if (front == 0)
    {
        printf("Enter the item to insert");
        scanf("%d", &item);
        front = MAX - 1;
        Deque[front] = item;
    }
    else
    {
        printf("Enter the item to insert");
        scanf("%d", &item);
        Deque[--front] = item;
    }
}

void enqueueRear()
{
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Full!");
    }
    else if (rear == -1)
    {
        printf("Enter the item to insert");
        scanf("%d", &item);
        front = 0;
        rear = 0;
        Deque[rear] = item;
    }
    else if (rear == MAX - 1)
    {
        printf("Enter the item to insert");
        scanf("%d", &item);
        rear = 0;
        Deque[rear] = item;
    }
    else
    {

        printf("Enter the item to insert");
        scanf("%d", &item);
        Deque[++rear] = item;
    }
}

void dequeueFront()
{
    if (front == -1)
    {
        printf("Deque Empty!");
    }
    else if (front == rear)
    {
        printf("Deleted item - %d", Deque[front]);
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        printf("Deleted item - %d", Deque[front]);
        front = 0;
    }
    else
    {
        printf("Deleted item - %d", Deque[front++]);
    }
}

void dequeueRear()
{
    if (front == -1)
    {
        printf("Deque Empty!");
    }
    else if (front == rear)
    {
        printf("Deleted item %d", Deque[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("Deleted item %d", Deque[rear]);
        rear = MAX - 1;
    }
    else
    {
        printf("Deleted item %d", Deque[rear--]);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Deque Empty!");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", Deque[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", Deque[rear]);
    }
}

void main()
{
    int choice, data;
    do
    {
        printf("\n\nMenu: \n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            enqueueFront();
            break;
        case 2:

            enqueueRear();
            break;
        case 3:

            dequeueFront();
            break;
        case 4:

            dequeueRear();
            break;
        case 5:

            display();
            break;
        case 6:

            break;
        default:

            break;
        }
    } while (choice != 6);
}