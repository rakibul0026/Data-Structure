#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
struct node* create(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node*  Insert(struct node* node, int data) {
    if (node == NULL) 
        return create(data);

    if (data < node->data) 
        node->left = Insert(node->left, data);
    else if (data > node->data) 
        node->right = Insert(node->right, data);

    return node;
}
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}


void Inorder(node* root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
    

}
struct node *FindMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int main(){
    node* root=NULL;
    root=Insert(root,3);
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,9);

    Inorder(root);

  struct node* found = search(root, 4);
    if (found != NULL)
        printf("\nFound 4\n");
    else
        printf("\n4 not found\n");

    return 0;
 
}
