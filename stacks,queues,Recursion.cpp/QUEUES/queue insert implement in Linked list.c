
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;

}node;
node *front=NULL;
node* rear=NULL;

void enqueue(int data){
   node* new_node=(node*)malloc(sizeof(node));
   new_node->data=data;
  
   if(front==NULL){
    front=rear=new_node;
   }else
   rear->next=new_node;
   rear=new_node;
   new_node->next=NULL;
}

void display(){
    if(front==NULL){
        printf("Queue is Empty");
        return ;
    }
    node *temp=front;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main(){
    enqueue(1);
    enqueue(3);
    enqueue(5);
    enqueue(7);
    display();

}
