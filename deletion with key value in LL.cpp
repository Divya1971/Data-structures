#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};
void push(struct node **href, int data)
{
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next=*href;
    *href=newnode;
}
void deleteNode(struct node **href, int data){
    struct node *temp= *href,*prev;
    if (temp!=NULL && temp->data==data){
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    
    if (temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void printlist(struct node *node){
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node=node->next;
    }
    printf("\n");
}
int main(){
    struct node *head= NULL;
    push(&head,45);
    push(&head,78);
    push(&head,85);
    printlist(head);
    deleteNode(&head,78);
    printlist(head);
}




