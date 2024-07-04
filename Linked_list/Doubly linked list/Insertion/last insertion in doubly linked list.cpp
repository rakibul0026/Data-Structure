
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

void last_insert(int item) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
    int main() {
    insert(3);
    insert(5);
    insert(7);
    insert(8);

    printf("Before the insertion, the list is:\n");
    display();

    last_insert(26);
    printf("After the last insertion, the list is:\n");
    display();
    return 0;
}
