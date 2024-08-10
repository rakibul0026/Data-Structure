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
    rear->next=front;
   }else
   rear->next=new_node;
   rear=new_node;
   new_node->next=front;
}
void dequeue(){
  if(front==NULL){
    printf("The queue is empty");
  }else if(front==rear){
     printf("The deleted element is: %d\n", front->data);
        free(front);
        front = rear = NULL;
  }else
  {
   node* temp=front;
   printf("The delete element is:%d\n",temp->data);
   front=front->next;
   rear->next=front;
   free(temp);
  }

}
void display(){
    if(front==NULL){
        printf("Queue is Empty");
        return ;
    }
    node* temp = front;
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("front\n");

}
int main(){
    enqueue(1);
    enqueue(3);
    enqueue(5);
    enqueue(7);
    display();

    dequeue();
    display();
    return 0;

}
