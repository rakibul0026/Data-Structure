#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;

void push(struct node *head, int value) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("not able to push the element\n");
        return;
    }
    ptr->data = value;
    ptr->next = head;
    head = ptr;
    printf("Item pushed: %d\n", value);
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Printing Stack elements:\n");
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 40);
    push(head, 80);
    display(head);
    return 0;
}
