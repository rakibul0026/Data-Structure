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

void display(node *s) {
    while (s->next != NULL) {
        printf("%d->", s->next->data);
        s = s->next;
    }
    printf("NULL");
}

void deleteNode(node *s, int data) {
    node *temp;
    while (s->next != NULL) {
        if (s->next->data == data) {
            temp = s->next;
            s->next = s->next->next;
            free(temp);
            return;
        }
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
    display(first);

    printf("\nEnter the item which node was deleting\n");
    int item;
    scanf("%d",&item);
    deleteNode(first, item);
    printf("List after deleting node with data :\n");
    display(first);

    return 0;
}
