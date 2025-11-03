#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* first = NULL;
struct node* last = NULL;

void create();
void display();

int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void create() {
    int d;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &d);
    newnode->data = d;
    newnode->next = newnode->prev = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    
    first->prev = last;
    last->next = first;
}

void display() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = first;
    printf("Linked list: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("(Back to first %d)\n", temp->data);
}

