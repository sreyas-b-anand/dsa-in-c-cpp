#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL , *newnode , *temp;
void push(int item)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	if(!newnode)
	{
		printf("insufficient memory space\n");
	}
	else{
	   newnode->data = item;
	   newnode->next = top;
	   top= newnode;
	}
} 
void pop()
{
	temp = top;
	if(top == NULL)
	{
		printf("Underflow\n");
		
	}
	else{
		printf("Deleted item = %d" , temp->data);
		top=top->next ;
		free(temp);
	}
}
void display(){
	temp = top;
	if(top== NULL){
		printf("List empty\n");
		return;
	}
	else{
	 while(temp!= NULL)
	 {
	 	printf("%d\n" , temp->data);
	 	temp=temp->next;
	 }
	}
}
 void main()
{
 int ch;
 
 do
 {
  printf("\nMenu\n----\n1.Push\n2.Pop\n3.display\n4.Exit");
  printf("\nEnter the choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
        printf("Enter the data to push:");
        int data;
        scanf("%d",&data);
        push(data);
         break;
   case 2: 
        pop();
        break;
   case 3:
    display();
    break;
   case 4:
    exit(0);
   default:
    printf("There is no such operation:");
  }
 }
 while(1);
}