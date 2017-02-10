#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void rotateLL(struct node **head,int k){
    struct node *current=*head;
    int count=1;
    if(k==0)
    return;
    while(count<k && current!=NULL){
        current=current->next;
        count++;
    }
    if(current==NULL)
    return;
    struct node *kthnode=current;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=*head;
    *head=kthnode->next;
    kthnode->next=NULL;
    
}
void push(struct node **head_ref, int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);  
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }printf("\n");
}    
int main(void)
{
    struct node *res=NULL;
    struct node* first = NULL;

    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
     push(&first, 14);
    push(&first, 90);
    printList(first);
  
    rotateLL(&first,3);
    printList(first);
 
   return 0;
}