
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int priority; 
    struct node* next;
};
struct node* newNode(int d, int p) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}
struct node* insert(struct node* head, int d, int p) {
    struct node* temp = newNode(d, p);
    if (head == NULL || head->priority > p) {
        temp->next = head;
        head = temp;
    } else {
        struct node* start = head;
        while (start->next != NULL && start->next->priority <= p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
    return head;
}
struct node* deleteNode(struct node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
void printQueue(struct node* head) {
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

int main() {
    struct node* pq = NULL;
    pq = insert(pq, 4, 1);
    pq = insert(pq, 5, 2);
    pq = insert(pq, 6, 3);
    pq = insert(pq, 7, 0);

    printf("Priority Queue:\n");
    printQueue(pq);

    pq = deleteNode(pq);

    printf("\nPriority Queue after deleting highest priority element:\n");
    printQueue(pq);
    return 0;
}
