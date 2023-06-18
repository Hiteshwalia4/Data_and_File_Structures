#include <stdio.h>
struct node{
int data;
struct node *next;
};
struct node *top=NULL,*temp,*newNode;
void push(int el){
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=el;
  newNode->next=NULL;
  if(top==NULL)
    top=newNode;
  else{
    newNode->next=top;
    top=newNode;
  }
}
void pop(){
  if(top==NULL)
    printf("\nCan't delete as");
  else{ 
  temp=top;
  top=top->next;
  printf("\nPopped item is: %d",temp->data);
  free(temp);
  }
}
void display_stack(){
  temp=top;
  if(top==NULL)
    printf("\nStack is empty...");
  else{ 
  printf("\nStack is: ");
  while(temp!=NULL){
    printf("%d| ",temp->data);
    temp=temp->next;
  }
  }
}
int main(void) {
  int choice;
  while(1){
    printf("\n\n1.Insert Item in Stack");
    printf("\n2.Delete Item from Stack");
    printf("\n3.Print Items of Stack");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    if(choice==1){
      int el;
      printf("\nEnter item: ");
      scanf("%d",&el);
      push(el);
      display_stack();
    }
    if(choice==2){
      pop();
      display_stack();
    }
    if(choice==3){
      display_stack();
    }    
    if(choice==4){
      printf("Program Terminated...");
      break;
    }
  }
  return 0;
}
