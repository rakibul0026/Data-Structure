#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node* s, int data) {
    node* temp = s;
    while (temp->next != s) {
        temp = temp->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s;
    temp->next = new_node;
}

void display(node* s) {
    node* temp = s;
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != s);
    printf("NULL\n");
}

void specified_location(node* s, int data, int loc) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    node* temp = s;
    for (int i = 1; i < loc-1; i++) {
        if (temp->next == s) {
            printf("Location out of bounds\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

int main() {
    node* first = (node*)malloc(sizeof(node));
    first->data = 0;  
    first->next = first;

    insert(first, 52);
    insert(first, 63);
    insert(first, 78);
    insert(first, 63);
    insert(first, 26);

    printf("\nBefore the insertion\n");
    display(first->next); 
    
    specified_location(first, 34, 1); 
    printf("\nAfter the specified_location insertion\n");
    display(first->next); 

    return 0;
}
