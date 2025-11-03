#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;	
};
struct node*first=NULL;
struct node*last=NULL;
void create();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.create\n2.display\n3.exit\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: create; break;
			case 2: display; break;
			case 3: exit(0);
			default: printf("invalid choice! try agaim.\n");
		}
	}
	return 0;
}
void create()
{
	int d;
	struct node *newnode= (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory not allotted\n");
	}
	printf("enter data: ");
	scanf("%d",&d);
	newnode->data=d;
	newnode->next=NULL;
	if(first==NULL){
	first = last = newnode;
	}
	 else
	 {
	 	last->next=newnode;
	 	last=newnode;
	 	
	 }
}
void display()
{
	if(first == NULL)
		printf("List is empty!\n");
	struct node*temp=first;
	printf("Linked list: ");
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

