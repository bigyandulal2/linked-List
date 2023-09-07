#include <stdio.h>
#include<stdlib.h>
int count=0;
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
      tail->prev->next=newnode;
      newnode->prev=tail->prev;
      newnode->next=tail;
      tail->prev=newnode;
      tail=newnode;
    return head; 
  }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return head;    
  }
}
struct Node *delete(struct Node *head,int pos){
  if(head==NULL){
    printf("linked list is empty");
    return head;
  }
  else{
    struct Node *tail=head;
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        free(tail);
       return head;
    }
    for(int i=1;i<pos;i++){
     if(tail->next!=NULL){
       tail=tail->next;
     }
    }
   if(tail->next!=NULL){
     tail->prev->next=tail->next;
     tail->next->prev=tail->prev;
     free(tail);
     return head;
   }
    if(count>=pos){
    tail->prev->next=NULL;
    free(tail);
    return head;}
    else{
      printf("there are only %d linked list\n ",count);
      printf("but you have %d pos  which is  more than %d linked list\n",pos,count);
      return head;
    }   
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
    count++;
  }
  printf("\n");
}
int main(void) {
 struct Node *head=NULL;
 head=insert(head,1,43);
 head=insert(head,1,10);
 head=insert(head,4,34);
 head=insert(head,2,26);
 head=insert(head,10,89);
display(head);
  printf("after deleting linked list, outputs are \n");
  head=delete(head, 15);
  display(head);
  return 0;
}