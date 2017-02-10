#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
// functions which do not modify head pointer
void addtoAll(struct node *node, int data){
    while(node!=NULL){
        node->data=node->data+ data;
        node=node->next;
    }    
}
//functions that modify head pointer

//Make head pointer global
struct node *head= NULL;
void deleteFirst(){
    
    if(head!=NULL){
        struct node *temp =head;
        head=head->next;
        free(temp);
    }
}
//Return head pointer
struct node *deleteFirst(struct node *href){
    
    if(href!=NULL){
        struct node *temp=href;
        href=href->next;
        free(temp);
    }
    return head;
}
//use double pointer
void deleteFirst(struct node **href){
    if (*href!=NULL){
         struct node *temp= *href;
         *href=*href->next;
         free(temp);
    }
   
    
}
int main() {
	// your code goes here
	return 0;
}
