//Height of Binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

struct node* create(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void postorder(struct node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data); 
}

void inorder(struct node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data); 
    inorder(node->right);
}

void preorder(struct node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data); 
    preorder(node->left);
    preorder(node->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcHeight(node* root) {
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

int main() {
    struct node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->right->right = create(5);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    int height = calcHeight(root);
    printf("\nHeight of the tree: %d\n", height);

    return 0;
}
