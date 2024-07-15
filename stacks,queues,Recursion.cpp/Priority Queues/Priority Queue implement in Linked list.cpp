
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int priority;
    struct node* next;
};
struct node* head = NULL;
void enqueue(int data, int priority) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
     if(head==NULL){
        head=new_node;
      }
   else if (head == NULL || head->priority < new_node->priority) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL && temp->next->priority >= new_node->priority) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void Dequeue() {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}
int peek() {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return -1; 
    }
    return head->data;
}
void printQueue(struct node* head) {
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}
int main() {
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 1);
    enqueue(40, 3);

    printf("Queue after enqueues:\n");
    printQueue(head);

    printf("Peek: %d\n", peek());

    Dequeue();
    Dequeue();

    printf("Queue after dequeues:\n");
    printQueue(head);
    return 0;
}
