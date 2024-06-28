
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node* s, int data) {
    while (s->next != NULL) {
        s = s->next;
    }
    s->next = (node*)malloc(sizeof(node));
    s->next->data = data;
    s->next->next = NULL;
}

void display(node* s) {
    if (s->next == NULL) {
        printf("List is empty\n");
        return;
    }
    s = s->next; 
    while (s != NULL) {
        printf("%d->", s->data);
        s = s->next;
    }
    printf("NULL\n");
}
void begin_delete(node* s) {
    if (s->next == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = s->next;
    s->next = s->next->next;
    free(temp);
}

int main() {
    node* first = (node*)malloc(sizeof(node));
    first->next = NULL; 

    insert(first, 52);
    insert(first, 63);
    insert(first, 78);
    insert(first, 80);
    insert(first, 26);
    printf("\nBefore the insertion\n");
    display(first);
    
    begin_delete(first);
    printf("\nAfter begin_delete\n");
    display(first);

   return 0;
}
