
#include<stdio.h>
#include<stdlib.h>

typedef struct mylist {
    int data;
    struct mylist *next;
} node;

void insert(node *s, int data) {
    while (s->next != NULL) {
        s = s->next;
    }
    s->next = (node*)malloc(sizeof(node));
    s->next->data = data;
    s->next->next = NULL;
}

void Traversing(node *s) {
    while (s->next != NULL) {
        printf("%d\n", s->next->data);
        s = s->next;
    }
}

int main() {
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;

    insert(first, 9);
    insert(first, 5);
    insert(first, 11);
    insert(first, 4);

    printf("Original list:\n");
    Traversing(first);
    return 0;
}
