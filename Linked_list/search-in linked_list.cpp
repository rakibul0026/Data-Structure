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
    s->next->next=NULL;
    s->next->data=data;

}
void display(node* s){
   while(s->next!=NULL){
   printf("%d->",s->next->data);
   s=s->next;
   }
   printf("NULL");

}
int  search(node*s,int item){
    int index=0;
    while(s->next!=NULL){
        if(s->next->data==item){
           return index;
        }
        s=s->next;
        index++;
    }
    return -1;
}
void Begin_insert(node*s,int data){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=s;
    s=new_node;
}
int main(){
    node *first=(node*)malloc(sizeof(node));
    first->next=NULL;

    insert(first,30);
    insert(first,40);
    insert(first,50);
    insert(first,60);
    
    printf("Before the insertion the list is:\n");
    display(first);

    Begin_insert(first,45);

    printf("\nAfter the insertion the list is:\n");
    display(first);

    search(first,60);

    int index = search(first, 60);
    if (index != -1) {
        printf("\nItem 60 found at index: %d\n", index);
    } else {
        printf("\nItem 60 not found\n");
    }



}
