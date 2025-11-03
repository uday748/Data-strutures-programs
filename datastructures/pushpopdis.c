#include<stdio.h>
int stack[5],i,top=-1,ele;
void push()
{
	if(top==4)
	printf("stack is over flow");
	else
	{
		top++;
		printf("Enter an element");
		scanf("%d",&ele);
		stack[top]=ele;
	}
}void pop()
{
	if(top==-1)
	printf("Stack is underflow");
	else
	{
		ele=stack[top];
		printf("Deleted elements is %d",ele);
		top--;
	}
}
void display()
{
	for(i=top;i>=0;i--)
	printf("%d\n",stack[i]);
	
}
int main()
{
	
	{
      	int ch;
	    printf("1.push 2. pop 3.display\n");
     	printf("Enter your choice");
    	scanf("%d",&ch);
     	switch(ch)
     	{
	     	case 1:push();
		    break;
	    	case 2:pop();
	    	break;
		    case 3:display();
		   break;
       }
   }
}
