
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;

};
int main(){
    struct node *head=0;
    struct node *new_node;
     struct node *temp;

    cout<<"Enter the value of 5 node"<<endl;
    for(int i=0;i<5;i++){
        new_node=new node;
        cin>>new_node->data;
        new_node->next=head;
        head=new_node;
    }
     new_node=new node;
    cout<<"Enter which node data was insert"<<endl;
    cin>>new_node->data;
    new_node->next=NULL;
    
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    temp=new_node;


   struct node * current=head;
   while(current!=NULL){
   
    cout<<"->"<<current->data;
     current=current->next;
   }


}
