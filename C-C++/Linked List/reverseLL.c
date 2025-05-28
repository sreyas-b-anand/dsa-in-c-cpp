#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newnode, *new, *head, *temp, *current, *next, *prev;
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
void reverse()
{
    current = head->next;
    prev = head;
    next = current->next;
    while (next != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    current->next = prev;
    head->next = NULL;
}
void main()
{
    int num;
    printf("Enter no of nodes : ");
    scanf("%d", &num);
    createNodes(num);
    printf("List is \n");
    printList(head);
    printf("\nreverse \n");
    reverse();
    printList(current);
}