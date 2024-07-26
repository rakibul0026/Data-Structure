#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
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

struct node *Delete(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
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
            delete root;
            root = NULL;
        }
        else if (root->left = NULL) 
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->right == NULL) 
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            struct node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
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
    
    printf("Before the deletion:\n");
    Inorder(root);

    printf("\nBefore the deletion:\n");
    root =Delete(root, 4);
    Inorder(root);
 
}
