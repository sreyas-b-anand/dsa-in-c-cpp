#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *head = NULL, *temp, *prev;

void createNodes(int n)
{
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertFront(int item)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = head;
    head = newnode;
}

void insertRear(int item)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAtPos(int item, int pos)
{
    int count = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteRear()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void deleteAtPos(int pos)
{
    int count = 1;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position\n");
        }
        else
        {
            struct node *del = temp->next;
            temp->next = del->next;
            free(del);
        }
    }
}

int main()
{
    int choice, dataItem, position;
    char cont;

    createNodes(3);

    do
    {
        printf("\n1.Insert at Front\n2.Insert at Rear\n3.Insert at Position\n4.Delete at Front\n5.Delete at Rear\n6.Delete at Position\n7.Display\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &dataItem);
            insertFront(dataItem);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &dataItem);
            insertRear(dataItem);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &dataItem);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPos(dataItem, position);
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteRear();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAtPos(position);
            break;
        case 7:
            display();
            break;
        default:
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
