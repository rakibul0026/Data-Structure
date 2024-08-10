#include <stdio.h>
#include <stdlib.h>

const int n = 100;
int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == n - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("%d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    
    dequeue();
    display();
    
    return 0;
}
