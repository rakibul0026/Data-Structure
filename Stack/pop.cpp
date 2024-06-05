#include <iostream>
using namespace std;

void push(int item, int stack[], int &top, int Maxstk) {
    if (top == Maxstk - 1) {
        cout << "Overflow\n";
    } else {
        top++;
        stack[top] = item;
    }
}

void pop(int stack[], int &top) {
    if (top == -1) {
        cout << "Underflow\n";
    } else {
        cout << "Popped: " << stack[top] << "\n";
        top--;
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    const int Maxstk = 100; 
    int stack[Maxstk]; 
    int top = -1;      
    int item;

    for (int i = 0; i < 3; i++) {
        cout << "Enter item " << (i + 1) << " to be inserted into the stack: ";
        cin >> item;
        push(item, stack, top, Maxstk);
    }
    display(stack, top);  
    pop(stack, top);
    display(stack, top);

    return 0;
}
