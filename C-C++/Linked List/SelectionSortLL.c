#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newnode, *new, *head, *temp;
;
struct Node *createNode(int data)
{
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}
void createNodes(int n)
{
    int data1;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &data1);
        newnode = createNode(data1);
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void printList(struct Node *root)
{
    temp = root;
    while (temp != NULL)
    {
        printf("%d", temp->data);

        printf(" -> ");

        temp = temp->next;
    }
    printf("NULL");
}
void selectionSort()
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *minNode = current;
        struct Node *temp = current->next;

        while (temp != NULL)
        {
            if (temp->data < minNode->data)
            {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != current)
        {
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
        }

        current = current->next;
    }
}
void main()
{
    int num;
    printf("Enter no of nodes : ");
    scanf("%d", &num);
    createNodes(num);
    printf("List is \n");
    printList(head);
    selectionSort();
    printf("\nSorted List \n");
    printList(head);
}