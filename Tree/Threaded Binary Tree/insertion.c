#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    bool lthread;
    bool rthread;
} node;

node* insert(node* root, int data) {
    node* ptr = root;
    node* par = NULL;

   while (ptr != NULL) {
        if (data == ptr->data) {
            printf("Duplicate Data\n");
            return root;
        }
        par = ptr;
        if (data < ptr->data) {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        } else {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->lthread = true;
    temp->rthread = true;

    if (par == NULL) {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    } else if (data < par->data) {
        temp->left = par->left;
        temp->right = par;
        par->lthread = false;
        par->left = temp;
    } else {
        temp->right = par->right;
        temp->left = par;
        par->rthread = false;
        par->right = temp;
    }

    return root;
}

node* inorderSuccessor(node* ptr) {
    if (ptr->rthread)
        return ptr->right;

    ptr = ptr->right;
    while (!ptr->lthread)
        ptr = ptr->left;

    return ptr;
}

void inorder(node* root) {
    if (root == NULL) {
        printf("Tree is Empty\n");
        return;
    }

    node* ptr = root;
    while (!ptr->lthread)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
    printf("\n");
}

int main() {
    node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 90);
    root = insert(root, 100);

    inorder(root);
    return 0;
}
