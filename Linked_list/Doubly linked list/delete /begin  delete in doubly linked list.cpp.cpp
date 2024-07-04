
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* head = NULL;
void insert(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void begin_delete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

int main() {
    insert(5);
    insert(6);
    insert(8);
    insert(10);
    insert(26);
    printf("Before the deletion\n");
    display();

    begin_delete();
    printf("After begin_delete\n");
    display();

    return 0;
}
