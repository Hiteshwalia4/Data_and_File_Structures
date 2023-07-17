#include <stdio.h>
struct node{
char data;
struct node *next;
struct node *prev;
};
struct node *temp,*temp2,*newNode,*start=NULL;
void display_list(){
  temp2=start;
  while(temp2!=NULL){
    printf("<--%c-->",temp2->data);
    temp2=temp2->next;
  }  
}
int main(void) {
  int choice=1,flag=1;
  while(choice){ 
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data: ");
  scanf("%c",&newNode->data);
  getchar();
  newNode->next=NULL;  
  newNode->prev=NULL;  
  if(start==NULL)
    start=newNode;
  else{
    newNode->prev=temp;
    temp->next=newNode;
  }
  temp=newNode;
    
  printf("Do want to enter more nodes(1/0): ");
  scanf("%d",&choice);
  getchar();
  }
  display_list();

  temp2=start;
  while(temp!=NULL && temp2!=NULL && temp!=temp2){
    if(temp2->data==temp->data){
      temp2=temp2->next;
      temp=temp->prev;
      flag=0;
    }
    else{
      flag=1;
      break;
    }
  }
  if(flag==0)
    printf("\nLinked List is Palindrome :)");
  else
    printf("\nLinked List is Not Palindrome :(");
  return 0;
}
