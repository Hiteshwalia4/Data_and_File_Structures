#include <stdio.h>
struct node{
int data;
struct node *next;
};
struct node *newNode,*temp,*start=NULL;
void print_list(){
  struct node *temp2;
  printf("\nList is: ");
  temp2=start;
  while(temp2!=NULL){
    printf("%d-->",temp2->data);
    temp2=temp2->next;
  }
}
int main(void) {
  int choice=1;
  while(choice){
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data of node: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;

    if(start==NULL){
      start=newNode;
      temp=newNode;
    }
    else{
      temp->next=newNode;
      temp=newNode;
    }
    printf("\nDo you want to enter more nodes(1=Yes,0=No): ");
    scanf("%d",&choice);
  }
  print_list();
  
  struct node *i=start,*j; 
  while(i!=NULL){
    j=i->next;
    while(j!=NULL){
      if(i->data > j->data){
        int c=i->data;
        i->data=j->data;
        j->data=c;
      }
      j=j->next;
    }
    i=i->next;
  }
  printf("\n\n---List After sorting---");
  print_list();

  struct node *prev;
  i=start;
  int flag=1;
  newNode=(struct node*)malloc(sizeof(struct node)); 
  printf("\n\nEnter data of node to insert: ");
  scanf("%d",&newNode->data);
  newNode->next=NULL;
  
  while(newNode->data > i->data){
    prev=i;
    i=i->next;
    flag=0;
  }
  if(flag==1){
    newNode->next=i;
    start=newNode;
  }
  else{ 
  prev->next=newNode;
  newNode->next=i;
  }

  printf("\nNode Inserted Successfully :)");
  print_list();
  return 0;
}
