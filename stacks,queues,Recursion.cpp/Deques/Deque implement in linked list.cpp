
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* front = NULL;
node* rear = NULL;

void enqueueFront(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = front;
    new_node->prev = NULL;

    if (front == NULL) {
        front = rear = new_node;
    } else {
        front->prev = new_node;
        front = new_node;
    }
}

void enqueueRear(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = rear;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeueFront() {
    if (front == NULL) {
        printf("The queue is empty\n");
        return;
    } else {
        node* temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;
        }
        printf("The deleted element from front is: %d\n", temp->data);
        free(temp);
    }
}

void dequeueRear() {
    if (rear == NULL) {
        printf("The queue is empty\n");
        return;
    } else {
        node* temp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL;
        }
        printf("The deleted element from rear is: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueueFront(1);
    enqueueRear(3);
    enqueueFront(5);
    enqueueRear(7);
    display();

    dequeueFront();
    display();

    dequeueRear();
    display();

    return 0;
}
