#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};

void findInsertionPoint(node *start, int item, node *&loc) {
    loc = NULL; 
    if (start == NULL) {
        return;  
    }

    node *save = start;
    node *ptr = start->link;

    while (ptr != NULL && item > ptr->data) {
        save = ptr;
        ptr = ptr->link;
    }

    loc = save;
}

void insertSorted(node *&start, int item) {
    node *loc;
    findInsertionPoint(start, item, loc);

    node *newNode = new node;
    newNode->data = item;

    if (loc == NULL) {
        newNode->link = start;
        start = newNode;
    } else {
        newNode->link = loc->link;
        loc->link = newNode;
    }
}

void printList(node *start) {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main() {
    node *start = NULL;

    insertSorted(start, 5);
    insertSorted(start, 2);
    insertSorted(start, 8);
    insertSorted(start, 1);
    insertSorted(start, 7);

    printList(start);

    return 0;
}
