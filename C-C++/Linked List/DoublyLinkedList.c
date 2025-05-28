#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode, *head = NULL, *temp , *tail;
void createNodes(int n)
{
    printf("\nCreating %d nodes...\n" , n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL && tail == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    printf("\n %d nodes created successfully\n" , n);
}
void insertFront(int item)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data =item;
	newnode->next = NULL;
    newnode->prev = NULL;
	if (head == NULL && tail == NULL)
	{
		head = tail = newnode;
	}
	else{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}

}
void insertRear(int item)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data =item;
	newnode->next = NULL;
    newnode->prev = NULL;
	if (head == NULL && tail == NULL)
	{
		head = tail =newnode;
	}
	else{
		tail->next = newnode;
		newnode->prev = tail;
		tail=newnode;
	}
}
void insertAtPos(int item , int pos)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data =item;
	newnode->next = NULL;
    newnode->prev = NULL;
    if(newnode == NULL)
    {
    	printf("Invalid\n");
    	return;
    }
    else{
    if(pos == 1)
    {
    	insertFront(item);
    	return;
    }
    	int count = 0;
    	temp = head;
    	while(temp != NULL)
    	{
    		count++;
    		temp= temp->next;
    	}
    	if(pos > count + 1 || pos <1)
    	{
    		printf("Invalid\n");
    	}
    	else{
    		temp = head;
    		for(int i = 1 ;i< pos - 1;i++)
    		{
    			temp = temp->next;
    		}
    		newnode->next = temp->next;
    		temp->next = newnode;
    		newnode->prev = temp;
    		if(newnode->next != NULL)
    		{
    			newnode->next->prev = newnode;
    		} 
    		else{
    			return;
    		}
    	}
    }
}
void deleteFront() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next; 
   
    if (head != NULL) {
        head->prev = NULL;
    } else {
        
        tail = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (tail == NULL) {
        printf("List empty\n");
        return;
    }

    temp = tail;
    tail = tail->prev;

   
    if (tail != NULL) {
        tail->next = NULL;
    } else {
       
        head = NULL;
    }

    free(temp); 
}

void deleteAtPos(int pos)
{
	if(head == NULL)
	{
		printf("List empty\n");
	}
	else{
	if(pos == 1)
	{
		deleteFront();
		return;
	}
		int count = 0;
    	temp = head;
    	while(temp != NULL)
    	{
    		count++;
    		temp=temp->next;
    	}
    	if(pos > count || pos <1)
    	{
    		printf("Invalid\n");
    	} 
    	else{
    		temp = head;
    		for(int i = 1 ;i< pos;i++)
    		{
    			temp = temp->next;
    		}
    		temp->prev->next = temp->next;
    		temp->next->prev = temp->prev;
    		free(temp);
    	}
	}
}
void display()
{
	temp=head;
	if(temp == NULL)
	{
		printf("List empty\n");
	}
	else{
		while(temp!= NULL)
		{
			printf("%d <-> ",temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
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