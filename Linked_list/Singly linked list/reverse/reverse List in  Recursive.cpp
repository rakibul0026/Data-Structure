
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
node* reverseListRecursive(node* current, node* prev) {
    if (current == NULL) {
        return prev;
    }
    node* next = current->next;
    current->next = prev;
    return reverseListRecursive(next, current);
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

    first->next = reverseListRecursive(first->next, NULL);
    printf("Reversed list (Recursive):\n");
    display(first);

    return 0;
}
