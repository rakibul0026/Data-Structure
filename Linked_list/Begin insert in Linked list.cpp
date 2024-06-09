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
void begin_insert(node *s, int item) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = s->next;
    s->next = new_node;
}

int main() {
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    
    insert(first, 3);
    insert(first, 5);
    insert(first, 7);
    insert(first, 8);
    
    printf("Before the insertion, the list is:\n");
    display(first);
    
    int item;
    printf("Enter the item to insert at the beginning: ");
    scanf("%d", &item);
    
    begin_insert(first, item);
    printf("After the insertion, the list is:\n");
    display(first);
    return 0;
}
