#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *new_node;

    printf("Enter the data of 5 nodes:\n");

    for (int i = 0; i < 5; i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        scanf("%d", &new_node->data);
        new_node->next = head;
        head = new_node;
    }

    
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    
    return 0;
}
