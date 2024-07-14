
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int priorityQue[SIZE][2];
int p = -1;

void insert(int d, int g) {
    if (p == SIZE - 1) {
        printf("Overflow\n");
    } else {
        p++;
        priorityQue[p][0] = d;
        priorityQue[p][1] = g;
    }
}

void del() {
    if (p == -1) {
        printf("\nUNDERFLOW\n");
    } else {
        int i, idx = 0;
        int max = priorityQue[0][1];
        for (i = 1; i <= p; i++) {
            if (priorityQue[i][1] > max) {
                max = priorityQue[i][1];
                idx = i;
            }
        }
        printf("\nThe deleted element is %d with priority %d\n", priorityQue[idx][0], priorityQue[idx][1]);
        for (i = idx; i < p; i++) {
            priorityQue[i][0] = priorityQue[i + 1][0];
            priorityQue[i][1] = priorityQue[i + 1][1];
        }
        p--;
    }
}

void display() {
    int i;
    for (i = 0; i <= p; i++) {
        printf("\nElement: %d, Priority: %d\n", priorityQue[i][0], priorityQue[i][1]);
    }
}

int main() {
    insert(4, 1);
    insert(5, 2);
    insert(6, 0);
    insert(7, 3);
    
    display();
    
    del();
    display();
    
    del();
    display();
    
    return 0;
}
