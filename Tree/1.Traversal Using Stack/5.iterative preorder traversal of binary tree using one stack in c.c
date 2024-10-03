#include <stdio.h>
#include<stdlib.h>
#include <stack>
typedef struct node {
    int data;
    node *left, *right;
}node;
struct node* create(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void iterativePreorder(node *root) {
    // Base Case
    if (root == NULL)
        return;
  // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);
  // Traverse the tree
    while (!nodeStack.empty()) {
        // Pop the top item from stack and print it
        node *current = nodeStack.top();
         printf ("%d ",current->data );
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (current->right)
            nodeStack.push(current->right);
        if (current->left)
            nodeStack.push(current->left);
    }
}
int main() {
    struct node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->right->right = create(5);

   printf("\nIterative preorder: ");
   iterativePreorder(root);

    printf("\n");

    return 0;
}
