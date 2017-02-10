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
int main(){
    struct node *res = NULL;
    struct node *h1= NULL;
    struct node *h2= NULL;
    push(&h1, 15);
    push(&h1, 10);
    push(&h1, 5);
    push(&h2, 20);
    push(&h2, 3);
    push(&h2, 2);
    res = mergeList(h1, h2);
    printlist(res);
    return 0;
}