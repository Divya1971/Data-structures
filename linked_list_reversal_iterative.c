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
void deletenode( struct node **href, int key)
{
    struct node* temp= *href, *prev;
    if (temp!=NULL && temp->data==key)
    {
        (*href)=temp->next;
        free(temp);
        return;
    }
    if(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
        if(temp==NULL)
        return;
        else
        prev->next=temp->next;
        free(temp);
        return;
    }
}
void deletenodewithpos(struct node **href, int position)
{
    int i;
    if(*href==NULL)
    return;
    struct node* temp= *href;
    if(position==0)
    {
        (*href)=temp->next;
        free(temp);
        return;
    }
    for(i=0;temp!=NULL && i<position-1; i++)
    {
        if(temp==NULL || temp->next==NULL)
        {
            return;
        }
        struct node *next= temp->next->next;
        free(temp->next);
        temp->next=next;
        return;
    }
}
int getCountiterative(struct node* head)
{
    struct node* current =head;
    int count;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
int getCountrecursive(struct node* head)
{
    if(head==NULL)
    return 0;
    else
    return (1+getCountrecursive(head->next));
}
static void reverse1(struct node** href)
{
    struct node* prev=NULL;
    struct node* current= *href;
    struct node* next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *href=prev;
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
	printf("\n");
	printf("%d",getCountiterative(head));
	printf("\n");
	deletenode(&head,5);
	printll(head);
	deletenode(&head,1);
	printf("\n");
	printll(head);
	printf("\n");
	printf("%d\n",getCountrecursive(head));
	reverse1(&head);
	printll(head);
	return 0;
}
