#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

void insert(node **head, int item) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    if (*head == NULL) {
        new_node->next = new_node;
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        new_node->next = *head;
        temp->next = new_node;
        *head = new_node;
    }
}

void traverse(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteAt_First(node **head) {
    if (*head == NULL) {
        printf("List is already empty!!!\n");
        return;
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        node *temp = *head;
        node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

int main() {
    node *head = NULL;
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    printf("The main linked list is : ");
    traverse(head);

    deleteAt_First(&head);
    printf("After deleting the first node, the list is : ");
    traverse(head);

    return 0;
}
