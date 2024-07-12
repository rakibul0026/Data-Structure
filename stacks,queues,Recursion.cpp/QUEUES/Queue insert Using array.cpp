
#include <iostream>
using namespace std;

const int n = 100; 
int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == n - 1) {
        cout << "Overflow";
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty";
    } else {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
   
    return 0;
}
