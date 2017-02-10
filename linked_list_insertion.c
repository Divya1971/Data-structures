#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node** href, int nd)
{
   
    struct node* new_node= (struct node*) malloc(sizeof(struct node));
    new_node->data=nd;
    new_node->next=(*href);
    (*href)=new_node;
}
void insert(struct node *prev_node, int nd)
{
     if(prev_node==NULL)
    printf("no");
    struct node* new_node= (struct node*) malloc(sizeof(struct node));
     new_node->data=nd;
     new_node->next=prev_node->next;
     prev_node->next=new_node;
}
void append( struct node** href,int nd)
{
    struct node *last=(*href);
    struct node* new_node= (struct node*) malloc(sizeof(struct node));
    new_node->data=nd;
    new_node->next=NULL;
    if(*href==NULL)
    (*href)=new_node;
    else
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
}
void printll(struct node *n)
{
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
}
int main() {
	// your code goes here
	struct node* head=NULL;
	push(&head,3);
	push(&head,5);
	
	append(&head,9);
	append(&head,1);
	insert(head->next,6);
	printll(head);
	
	return 0;
}
