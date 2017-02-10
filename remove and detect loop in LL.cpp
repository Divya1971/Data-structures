//doubt in logic 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void detectandDeleteLoop(struct node *head){
    struct node *slow=head;
    struct node *fast=head->next;
    while(fast && fast->next){
        if (slow==fast)
        break;
        slow=slow->next;
        fast=fast->next->next;
    }
    if (slow==fast){
        slow=head;
        while(slow!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
void push(struct node** head_ref, int new_data)
{
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
    struct node* head = NULL;
     push(&head, 50);
     push(&head, 20);
     push(&head, 15);
     push(&head, 4);
     push(&head, 10);
    
     head->next->next->next->next->next = head->next->next;
     
     detectandDeleteLoop(head);
     printList(head);
 
     return(0);
}