#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *newnode=NULL;
struct node *top=NULL;
struct node *temp=NULL;
void push();
void pop();
void display();
int ele;
void main()
{
 int ch;
 while(1)
{
 printf("\nstack operations\n");
 printf("1.push 2.pop 3.display 4.exit\n");
 printf("Enter your choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:push();
 break;
 case 2:pop();
 break;
 case 3:display();
 break;
 default: exit(0);
 break;
 }
 }
}
void push()
{
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("Enter data\n");
 scanf("%d",&ele);
 if(top==NULL)
 {
 newnode->data=ele;
 newnode->next=NULL;
 top=newnode;
 }
 else
 {
 newnode->data=ele;
 newnode->next=top;
 top=newnode;
 }
}
void pop()
{
 if(top==NULL)
 printf("Stack is empty");
 else
 {
 temp=top;
 ele=top->data;
 printf("Deleted element is %d\n",ele);
 top=top->next;
 temp->next=NULL;
 free(temp);
 }
}
void display()
{
 if(top==NULL)
 printf("Stack is empty");
 else
 {
 printf("The stack elements are:\n");
 temp=top;
 while(temp!=NULL)
 {
 printf("%d->", temp->data);
 temp=temp->next;
 }
 printf("NULL");
 }
}
