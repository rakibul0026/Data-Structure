#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

struct node* head = NULL;

void insert(int data) {
    struct node* temp = (node*)malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
}

void display() {
    struct node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insert(3);
    insert(5);
    insert(7);
    insert(8);

    printf("The linked list is:\n");
    display();

   
    return 0;
}
