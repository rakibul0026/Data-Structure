#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* link;
};
node* searchsl(node* start, int item) {
    struct node* ptr = start; 
    struct node* loc= 0; 

    while (ptr != NULL) {
        if (item < ptr->data) {
            ptr=ptr->link; 
        } else if (item == ptr->data) {
            loc= ptr; 
        }else
         loc=NULL;
    }
     loc=NULL;
}
node* createNode(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}
void insert(node* &start, int data) {
    node* newNode = createNode(data);
    if (start == NULL) {
        start = newNode;
    } else {
        node* temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}
void display(node* start) {
    node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main() {
    
    node* start = NULL;
    insert(start, 90);
    insert(start, 80);
    insert(start, 70);
    insert(start, 60);
    insert(start, 50);

    cout << "Original list:" << endl;
    display(start);

    int item;
    cout<<"Enter item which was insert in the sorted list"<<endl;
    cin>>item; 
    node* loc = searchsl(start, item);
   if (loc != NULL) {
        cout << "Element " << item << " found at node with address: " << loc << endl;
    } else {
        cout << "Element " << item << " not found in the list." << endl;
    }

    return 0;
}
