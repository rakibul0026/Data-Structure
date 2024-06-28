
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node* s, int data) {
    while (s->next != NULL) {
        s = s->next;
    }
    s->next = (node*)malloc(sizeof(node));
    s->next->data = data;
    s->next->next = NULL;
}

void display(node* s) {
    if (s->next == NULL) {
        printf("List is empty\n");
        return;
    }
    s = s->next; 
    while (s != NULL) {
        printf("%d->", s->data);
        s = s->next;
    }
    printf("NULL\n");
}
void lastnode_delete(node*s){

    struct node *ptr, *preptr;  
    if(s==NULL)  
    {  
       return;
    }  
    else if (s->next == NULL)  
    {  
        s= NULL;  
        delete(s);  
    }  
    else   
    {  
        ptr = s;  
        while(ptr->next->next!= NULL)  {
           ptr = ptr->next;
        }
       
        ptr->next=NULL;
    
    }  
}  

int main() {
    node* first = (node*)malloc(sizeof(node));
    first->next = NULL; 

    insert(first, 52);
    insert(first, 63);
    insert(first, 78);
    insert(first, 80);
    insert(first, 26);
    printf("\nBefore the insertion\n");
    display(first);
    
   lastnode_delete(first);
    printf("\nAfter lastnode_delete\n");
    display(first);

   return 0;
}
