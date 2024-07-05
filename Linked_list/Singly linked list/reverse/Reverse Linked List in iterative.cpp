
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void insert(node *s, int data) {
    while (s->next != NULL) {
        s = s->next;
    }
    s->next = (node*)malloc(sizeof(node));
    s->next->next = NULL;
    s->next->data = data;
}
void display(node *s) {
    while (s->next != NULL) {
        printf("%d->", s->next->data);
        s = s->next;
    }
    printf("NULL\n");
}

node* reverseListIterative(node* head) {
    node* prev = NULL;
    node* current = head->next;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    return head;
}

int main() {
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    
    insert(first, 3);
    insert(first, 5);
    insert(first, 7);
    insert(first, 8);
    
    printf("Original list:\n");
    display(first);

    first = reverseListIterative(first);
    printf("Reversed list (Iterative):\n");
    display(first);

    return 0;
}
