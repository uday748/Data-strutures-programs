#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enq();
void deq();
void display();
int main()
{
    int ch;
    while (1) 
	{
        printf("\n1.Enq 2.Deq 3.Display 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
		{
            case 1: enq(); break;
            case 2: deq(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void enq() {
    int ele;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter an element: ");
    scanf("%d", &ele);
    newNode->data = ele;
    newNode->next = NULL;

    if (rear == NULL) 
	{ 
        front = rear = newNode;
    } 
	else 
	{
        rear->next = newNode;
        rear = newNode;
    }
}

void deq() {
    if (front == NULL)
	{
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted Element is %d\n", front->data);
    front = front->next;
    free(temp);

    if (front == NULL) 
        rear = NULL;
}

void display()
{
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




