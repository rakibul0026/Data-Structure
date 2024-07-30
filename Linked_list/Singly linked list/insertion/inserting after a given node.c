
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

void specified_insert(node *s, int item, int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;

    while (s != NULL && s->data != data) {
        s = s->next;
    }
    if (s != NULL) {
        new_node->next = s->next;
        s->next = new_node;
    } else {
      
        printf("Node with data %d not found.\n", data);
    }
}

int main() {
   
node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    insert(first, 3);
    insert(first, 5);
    insert(first, 7);
    insert(first, 8);

    printf("Afer  the operation, the list is:\n");
    display(first);

    int item, data;
    printf("Enter the node data and insertion item : ");
    scanf("%d %d", &data ,&item);

    specified_insert(first, item, data);

    printf("After the operation, the list is:\n");
    display(first);
    return 0;
}
