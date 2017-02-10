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
//with value
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
//with pos
void deleteNodePos(struct node **href, int pos){
    struct node *temp=*href;
    
    if(*href==NULL){
        return;
    }
    if(pos==0){
        *href=temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp!=NULL && i<pos-1;i++)
    temp=temp->next;
    
    if(temp==NULL || temp->next==NULL)
    {
        return;
    }
    struct node *next=temp->next->next;
    temp->next=next;
    free(temp->next);
    return;
}
int main(){
    struct node *head= NULL;
    push(&head,45);
    push(&head,78);
    push(&head,85);
    printlist(head);
    deleteNode(&head,78);
    printlist(head);
    deleteNodePos(&head,1);
    printlist(head);
}




