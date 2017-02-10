#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
//insert a node
void push(struct node **head,int data){
    struct node *newnode=(struct node*)malloc (sizeof(struct node));
    struct node *temp=*head;
    newnode->data=data;
    newnode->next=*head;
    if((*head)!=NULL){
        while(temp->next!=(*head)){
            temp=temp->next;
            
        }
        temp->next=newnode;
    }
    else{
        newnode->next=newnode;
    }
    (*head)=newnode;
}

void printlist(struct node *head){
    struct node *temp=head;
    if(head!=NULL){
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
        
    }printf("\n");
}
int main() {
	struct node *head=NULL;
	push(&head,23);
	push(&head,13);
	push(&head,3);
	push(&head,1313);
	push(&head,134);
	printlist(head);
	return 0;
}
