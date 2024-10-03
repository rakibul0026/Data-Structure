#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* stack[MAX_STACK_SIZE];
int top = -1;

void push(node* tree_node)
{
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = tree_node;
}

node* pop()
{
    if (top < 0) {
        return NULL;
    }
    return stack[top--];
}

node* peek()
{
    if (top < 0) {
        return NULL;
    }
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void iterativePostorder(struct node *root)
{
    while (1)
    {
        if (root)
        {
            push(root);
            root = root->left;
        }
        else
        {
            if (isEmpty())
                break;
            else
            {
                if(peek()->right == NULL){
                    root = pop();
                    printf("%d ", root->data);
                    while(!isEmpty() && root == peek()->right){
                        printf("%d ", pop()->data);
                    }
                }
                if (isEmpty())
                    root = NULL;
                else
                    root = peek()->right;
            }
        }
    }
}

int main()
{
    struct node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->right->right = create(5);

    printf("\nIterative Postorder: ");
    iterativePostorder(root);

    printf("\n");

    return 0;
}

