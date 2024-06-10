#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
void push_linkstack(struct node *top, int item) {
    struct node *new_node = ( node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("not able to push the element\n");
        return;
    }
    new_node->data = item;
    new_node->next = top;
    top = new_node;
    printf("Item pushed: %d\n", item);
}
void pop_Linkstack(){
    struct node* temp;
    node* top;
    if(top==NULL){
        printf("Underflow");
    }else{
        printf("Popped Item is: %d",top->data);
        top=top->next;
        free(temp);
    }
}
int main() {
    node *top =  NULL;

    push_linkstack(top, 10);
    push_linkstack(top, 20);
    push_linkstack(top, 40);
    push_linkstack(top, 80);

    pop_Linkstack();

    return 0;
}
