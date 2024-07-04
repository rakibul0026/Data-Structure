
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} node;

void insert(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    
    if (*head == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
    } else {
        node* last = (*head)->prev;
        
        new_node->next = *head;
        new_node->prev = last;
        
        last->next = new_node;
        (*head)->prev = new_node;
    }
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    node* first = NULL;

    insert(&first, 52);
    insert(&first, 63);
    insert(&first, 78);
    insert(&first, 80);
    insert(&first, 26);

    printf("The linked list is:\n");
    display(first);

    return 0;
}
