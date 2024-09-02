//Deleting in BST
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
struct node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
node* findmin(node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node *Delete(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            temp = temp->left;
            free(temp);
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            temp = temp->right;
            free (temp);
        }
        else
        {
            node * temp=findmin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 12);

    inorder(root);
     
    printf("\nDelete 12\n");
    Delete(root, 12);
    inorder(root);

    return 0;
}
