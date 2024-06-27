
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void insert(node *s,int data){
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=NULL;
}
void display(node* s){
    while(s->next!=NULL){
        printf("%d->",s->next->data);
        s=s->next;
    }
    printf("NULL");
}

void specified_location(node* s, int data, int loc) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    node* temp = s;
    for (int i = 0; i < loc-1; i++) {
        if (temp->next == NULL) {
            printf("Location out of bounds\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}



int main(){
    node* first=(node*)malloc(sizeof(node));
    first->next=NULL;
    insert(first,52);
    insert(first,63);
    insert(first,78);
    insert(first,63);
    insert(first,26);
    printf("\nBefore the insertion\n");
    display(first);
    
    specified_location(first,34,1);
    printf("\nAfter the specified_location insertion\n");
    display(first);

    
}
