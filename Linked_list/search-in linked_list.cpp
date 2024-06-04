
#include <stdio.h>
#include <stdlib.h>

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

void display(node *s) {
    while (s->next != NULL) {
        printf("%d\n", s->next->data);
        s = s->next;
    }
}

void search(node *s, int data) {
    int count = 0;
    while (s->next != NULL) {
        if (s->next->data == data) {
            count++;
        }
        s = s->next;
    }
    printf("Total %d result(s) found.\n", count);
}

int main() {
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    int item;

    insert(first, 9);
    insert(first, 5);
    insert(first, 11);
    insert(first, 4);
    insert(first, 5); 

    printf("Original list:\n");
    display(first);

    printf("Enter the search item: ");
    scanf("%d", &item);
    search(first, item);
return 0;
}
