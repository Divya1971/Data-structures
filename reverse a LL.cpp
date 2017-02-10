#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void push(struct node **href,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*href;
    *href=newnode;
}
void printlist(struct node *node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
        
    }printf("\n");
}
static void reverse (struct node **href){
    struct node *prev=NULL;
    struct node *current=*href;
    struct node *next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }*href=prev;
}

void recursivereverse(struct node **href){
    struct node *first=*href;
    struct node *rest;
    rest=first->next;
    if (*href==NULL){
        return;
    }
    if (rest==NULL){
        return;
    }
    recursivereverse(&rest);
    first->next->next=first;
    first->next=NULL;
    *href=rest;
}
// another method
void reverseUtil(node *curr, node *prev, node **href);
void reverseNode(struct node **href){
    if(!href)
    return;
    //doubt in args
    reverseUtil(*href,NULL,href);
    
    
}
void reverseUtil(node *curr, node *prev, node **href){
    if(!curr->next)
    {
        *href=curr;
        curr->next=prev;
        return;
    }
    struct node *next= curr->next;
    curr->next=prev;
    reverseUtil(next,curr,href);
    
}
int main() {
	// your code goes here
	struct node *head=NULL;
	push(&head,45);
	push(&head,54);
	push(&head,51);
	push(&head,64);
	push(&head,72);
	push(&head,14);
	printlist(head);
	reverse(&head);
	printlist(head);
    recursivereverse(&head);
	printlist(head);
	reverseNode(&head);
	printlist(head);
	return 0;
}
