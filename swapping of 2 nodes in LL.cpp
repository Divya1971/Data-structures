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
void swapNode(struct node **href,int x,int y){
    if (x==y){
        return;
    }
     struct node *currX= *href, *prevX=NULL;
    struct node *currY =*href, *prevY=NULL;
    while(currX!=NULL && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }
    while(currY!=NULL && currY->data!=y)
    {
        prevY=currY;
        currY=currY->next;
    }
   
    if (prevX!=NULL)
    {
        prevX->next=currY;
    }
    else
    {
    *href=currY;
    }
    if(prevY!=NULL)
    {
        prevY->next=currX;
    }
    else
    {
        *href=currX;
    }
    struct node *temp =currY->next;
    currY->next=currX->next;
    currX->next=temp;
    return;
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
	swapNode(&head,45,72);
	printlist(head);
	return 0;
}
