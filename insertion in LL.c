#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};
// insert at front
void push(struct node **href,int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next=(*href);
    (*href)= newnode;
    
}
void insertAfter(struct node *prev, int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    if (prev==NULL){
        printf("oops!\n");
        return;
    }
    newnode->data= data;
    newnode->next=prev->next;
    prev->next=newnode;
}
void append(struct node **href, int data){
    struct node *newnode= (struct node*)malloc (sizeof(struct node));
    newnode->data= data;
    newnode->next= NULL;
    struct node *last=*href;
    if(*href==NULL){
        *href=newnode;
        
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
    return;
}

void printlist(struct node *node){
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}
int main() {
    struct node *head=NULL;
    insertAfter(head,42);
    push(&head,45);
    push(&head,78);
    insertAfter(head->next,42);
    append(&head,75);
    append(&head,19);
    printlist(head);
    // your code goes here
	return 0;
}

