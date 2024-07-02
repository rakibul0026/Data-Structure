
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node* head, int data) {
    node* s = head;
    while (s->next != head) {
        s = s->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    s->next = new_node;
}

void display(node* head) {
    if (head->next == head) {
        printf("List is empty\n");
        return;
    }
    node* s = head->next; 
    do {
        printf("%d->", s->data);
        s = s->next;
    } while (s != head);
    printf("HEAD\n");
}

void delete_last(node* head) {
    if (head == NULL) {
        return;
    } else if (head->next == head) {
        free(head);
    } else {
        node* ptr = head;
        node* preptr = NULL;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr != NULL) {
            preptr->next = head;
        }
        free(ptr);
    }
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = head; 

    insert(head, 52);
    insert(head, 63);
    insert(head, 78);
    insert(head, 80);
    insert(head, 26);

    printf("\nDisplay the linked list:\n");
    display(head);

    delete_last(head);
    printf("\nAfter deleting the last node, the linked list:\n");
    display(head);

    return 0;
}
