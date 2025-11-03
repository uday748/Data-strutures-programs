#include <stdio.h> 
#include <stdlib.h> 
// Node structure for doubly linked list 
struct node { 
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

struct node *head = NULL; 
struct node *tail = NULL; 
int count = 0; 

void create(); 
void display(); 
void insert(); 
 
int main() { 
    int ch; 
    while (1) { 
        printf("\n1. Create\n2. Display\n3. Insert\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) { 
            case 1: create(); break; 
            case 2: display(); break; 
            case 3: insert(); break; 
            case 4: exit(0); 
            default: printf("Invalid choice! Try again.\n"); 
        } 
    } 
    return 0; 
} 
 

void create() { 
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    if (newnode == NULL) { 
        printf("Memory allocation failed!\n"); 
        return; 
    } 
 
    printf("Enter data: "); 
    scanf("%d", &newnode->data); 
 
    newnode->prev = tail; 
    newnode->next = NULL; 
 
    if (head == NULL) { 
        head = tail = newnode; 
    } else { 
        tail->next = newnode; 
        tail = newnode; 
    } 
    count++; 
} 
 

void display() { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct node* temp = head; 
    printf("Doubly Linked List: "); 
    while (temp != NULL) { 
        printf("%d <-> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
// Function to insert a node at a given position 
void insert() { 
    int i,pos, x; 
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    if (newnode == NULL) { 
        printf("Memory allocation failed!\n"); 
        return; 
    } 
 
    printf("Enter position to insert (1-%d): ", count + 1); 
    scanf("%d", &pos); 
    printf("Enter data: "); 
    scanf("%d", &x); 
 
    newnode->data = x; 
 
    if (pos < 1 || pos > count + 1) { 
        printf("Invalid position!\n"); 
        free(newnode); 
        return; 
    } 
 
    if (pos == 1) { 
        newnode->prev = NULL; 
        newnode->next = head; 
        if (head != NULL) { 
            head->prev = newnode; 
        } 
        head = newnode; 
        if (tail == NULL) { 
            tail = newnode; 
        } 
    } else if (pos == count + 1) { 
        newnode->prev = tail; 
        newnode->next = NULL; 
        tail->next = newnode; 
        tail = newnode; 
    } else { 
        struct node* temp = head; 
          for (i = 1; i < pos - 1; i++) { 
            temp = temp->next; 
        } 
        newnode->prev = temp; 
        newnode->next = temp->next; 
        temp->next->prev = newnode; 
        temp->next = newnode; 
    } 
    count++; 
}
