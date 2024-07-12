#include <stdio.h>
#include <stdlib.h>

const int n = 100;
int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % n == front) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("The deleted element is: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("The deleted element is: %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements are: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[i]);
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
