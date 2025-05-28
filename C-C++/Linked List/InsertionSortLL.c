#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newnode, *new, *head , *temp;
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
void insertionSort()
{
    struct Node *sorted = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *nextNode = current->next;

        if (sorted == NULL || current->data < sorted->data)
        {

            current->next = sorted;
            sorted = current;
        }
        else
        {

            temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data){
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    head = sorted;
}
void main()
{
    int num;
    printf("Enter no of nodes : ");
    scanf("%d", &num);
    createNodes(num);
    printf("List is \n");
    printList(head);
    insertionSort();
    printf("\nSorted List \n");
    printList(head);
}