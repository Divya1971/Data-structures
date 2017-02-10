#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
  struct node *prev;
};
//insert at the beginning
void insertAtBegin(struct node **href,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*href;
    newnode->prev=NULL;
     if((*href) !=  NULL)
      (*href)->prev = newnode ;
    *href=newnode;
}
//insert after a given node
void insertAfter(struct node *prev_node,int data){
    if (prev_node == NULL)
    {
        printf("oops!!!");
        return;
    }
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=prev_node->next;
    newnode->prev=prev_node;
    prev_node->next=newnode;
    if(newnode->next!=NULL)
    newnode->next->prev=newnode;
    
}
//append a DLL
void append(struct node **href,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *last=*href;
    
    newnode->data=data;
    newnode->next=NULL;
     if (*href == NULL)
    {
        newnode->prev = NULL;
        *href = newnode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    newnode->prev=last;
    return;
}

void printList(struct node *node)
{
    struct node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
int main() {
     struct node* head = NULL;
    append(&head, 6);
    insertAtBegin(&head, 7);
    insertAtBegin(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printList(head);
	return 0;
}
