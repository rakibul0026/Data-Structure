#include <stdio.h>
#include <stdlib.h>

typedef struct mylist {
    int data;
    struct mylist *previous;
    struct mylist *next;
} node;

void insert(node *head, int data) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = (node*)malloc(sizeof(node));
    head->next->data = data;
    head->next->next = NULL;
    head->next->previous = head;  
}

void traversing(node *head) {
    node *temp = head;
   while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    node *first = (node*)malloc(sizeof(node));
    first->data = 0;  
    first->next = NULL;
    first->previous = NULL;

    insert(first, 9);
    insert(first, 5);
    insert(first, 11);
    insert(first, 4);

    
    printf("Original list:\n");
    traversing(first);
    return 0;
}
