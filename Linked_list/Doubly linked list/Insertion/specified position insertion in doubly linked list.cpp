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

void specified_location(int data, int loc) {
    if (loc <= 0) {
        printf("Location should be 1 or greater\n");
        return;
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    if (loc == 1) {
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        return;
    }

    node* temp = head;
    for (int i = 1; i < loc-1; i++) {
        if (temp->next == NULL) {
            printf("Location out of bounds\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

int main() {
    insert(3);
    insert(5);
    insert(7);
    insert(8);

    printf("Before the insertion, the list is:\n");
    display();
    specified_location(10, 1);
    printf("After the specified_location insertion, the list is:\n");
    display();

    return 0;
}
