#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void push(struct node **href,int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
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
struct node *mergeList (struct node *a, struct node *b){
    struct node *result = NULL;
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);

  if (a->data <= b->data) 
  {
     result = a;
     result->next = mergeList(a->next, b);
  }
  else
  {
     result = b;
     result->next = mergeList(a, b->next);
  }
  return(result);
}
void split(struct node *source,struct node **front,struct node **back){
    struct node *fast;
    struct node *slow;
    if(source==NULL || source->next==NULL){
        *front=source;
        *back=NULL;
    }
    else{
        slow=source;
        fast=source->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
    *front = source;
    *back= slow->next;
    slow->next=NULL;
    }
    
    
}
void MergeSort(struct node **href){
    struct node *head=*href;
    struct node *a;
    struct node *b;
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    split(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    
    *href=mergeList(a,b);
}
int main(){
  
    struct node *h1= NULL;
 
    push(&h1, 15);
    push(&h1, 10);
    push(&h1, 5);
    push(&h1, 20);
    push(&h1, 3);
    push(&h1, 2);
    MergeSort(&h1);
    printlist(h1);
    return 0;
}