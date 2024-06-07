#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};

void findInsertion_point(node *start, int item, node *&loc) {
    loc = NULL;
    if (start == NULL|| item <= start->data) {
        return;
    }
    node *save = start;
    node *ptr = start->link;
    while (ptr != NULL && item >=ptr->data) {
        save = ptr;
        ptr = ptr->link;
    }
    loc = save;
}

void insertSorted(node *&start, int item) {
    node *loc;
    findInsertion_point(start, item, loc);

    node *new_node = new node;  
    new_node->data = item;
    
    if (loc == NULL) {
        new_node->link = start; 
        start = new_node;
    } else {
        new_node->link = loc->link;
        loc->link = new_node;
    }
}

void print(node *start) {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;  
}

int main() {
    node *start = NULL;
    int item;

    insertSorted(start, 1);
    insertSorted(start, 7);
    insertSorted(start, 9);
    insertSorted(start, 10);

    print(start);

    cout << "Enter the item to insert: ";
    cin >> item;

    insertSorted(start, item);

    print(start);

    return 0;
}
