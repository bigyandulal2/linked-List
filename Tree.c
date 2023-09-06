#include <stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *prev,*next;
};

struct Node *insert(struct Node *head,int pos,int key){
  struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=key;
  newnode->prev=newnode->next=NULL;
   if(head==NULL){
      head=newnode;
     return head;
   }
  else{
    struct Node *tail=head;
    if(pos==1){
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
      return head;
    }
    for(int i=1;i<pos;i++){
      if(tail->next!=NULL){
      tail=tail->next;
      }
    }
    if(tail->next!=NULL){
   tail->next->prev=newnode;
    newnode->next=tail->next;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return head; 
  }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return head;    
  }
}
void display(struct Node *head){
  if(head==NULL){
    printf("Node is empty\n");
    return;
  }
  printf("displaying the nodes\n");
  
  while(head!=NULL){
    printf("%d\t",head->data);
    head=head->next;
  }
}
int main(void) {
 struct Node *head=NULL;
 head=insert(head,2,43);
 head=insert(head,3,10);
 head=insert(head,4,34);
 head=insert(head,1,26);
 head=insert(head,10,89);
display(head);
  return 0;
}