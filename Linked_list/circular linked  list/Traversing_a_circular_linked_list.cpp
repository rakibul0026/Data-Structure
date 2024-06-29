#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node** s, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    
    if (*s == NULL) {
        new_node->next = new_node;
        *s = new_node;
    } else {
        node* temp = *s;
        while (temp->next != *s) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *s;
    }
}

void display(node* s) {
    if (s == NULL) 
        return;
    node* temp = s;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}



int main() {
    node* first = NULL;

    insert(&first, 52);
    insert(&first, 63);
    insert(&first, 78);
    insert(&first, 80);
    insert(&first, 26);

    printf("the linked list is: \n");
    display(first);
    return 0;
}
