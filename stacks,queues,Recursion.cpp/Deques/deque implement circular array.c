#include <stdio.h>
#include <stdlib.h>

const int n = 100;
int deque[n];
int front = -1, rear = -1;

void insert_rear(int x)
{
    if ((rear + 1) % n == front)
    {
        printf("Overflow\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear = (rear + 1) % n;
        deque[rear] = x;
    }
}

void insert_front(int x)
{
    if ((rear + 1) % n == front)
    {
        printf("Overflow\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else
    {
        front = (front - 1 + n) % n;
        deque[front] = x;
    }
}

void delete_front()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d\n", deque[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d\n", deque[front]);
        front = (front + 1) % n;
    }
}

void delete_rear()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d\n", deque[rear]);
        front = rear = -1;
    }
    else
    {
        printf("%d\n", deque[rear]);
        rear = (rear - 1 + n) % n;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", deque[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", deque[rear]);
    }
}

int main()
{
    insert_rear(1);
    insert_rear(5);
    insert_rear(6);
    insert_rear(9);
    display();

    delete_front();
    display();

    insert_front(10);
    display();

    delete_rear();
    display();

    return 0;
}
