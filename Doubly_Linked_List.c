#include <stdio.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
struct node *newNode,*temp,*start=NULL;
void allocate_memory(){
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data of node: ");
  scanf("%d",&newNode->data);
  newNode->next=NULL;
  newNode->prev=NULL;
}
int length_of_list(){
  temp=start;
  int count=0;
  while(temp!=NULL){
    temp=temp->next;
    count++;
  }
  return count;
}
void print_list(){
  temp=start;
  if(temp==NULL)
    printf("\nList is empty!!");
  else{
  printf("\nList is: ");
  while(temp!=NULL){
    printf("<--%d-->",temp->data);
    temp=temp->next;
  }
  }
}
void node_insert_beg(){
  allocate_memory();
  if(start==NULL)
    start=newNode;
  else{
    newNode->next=start;
    start->prev=newNode;
    start=newNode;
  }
}
void node_insert_end(){
  temp=start;
  allocate_memory();
  if(start==NULL)
    start=newNode;
  else{
    while(temp->next!=NULL)
      temp=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
  }
}
void node_insert_specific(){
  int i=1,pos;
  temp=start;
  allocate_memory();
  if(start==NULL)
    start=newNode;
  else{
    printf("Enter position where you want to insert: ");
    scanf("%d",&pos);
    if(pos==1){
      newNode->next=start;
      start->prev=newNode;
      start=newNode;
    }
    else{
      while(i<pos-1){
        temp=temp->next;
        i++;
      }
      newNode->next=temp->next;
      newNode->prev=temp;
      temp->next->prev=newNode;
      temp->next=newNode;
    }
  }
}
void node_delete_end(){
  struct node *prev2;
  int length=length_of_list();
  temp=start;
  if(length==1){
    free(temp);
    start=NULL;
  }
  else{
  while(temp->next!=NULL){
    prev2=temp;
    temp=temp->next;
  }
  prev2->next=NULL;
  free(temp);
  }
}
void node_delete_beg(){
  int length=length_of_list();
  temp=start;
  if(length==1){
    free(temp);
    start=NULL;
  }
  else{
  temp->next->prev=NULL;
  start=temp->next;
  free(temp);
  }
}
void node_delete_specific(){
  int i=1,pos;
  struct node *var;
  temp=start;
  printf("Enter Position of node to delete: ");
  scanf("%d",&pos);
  if(pos==1){
   start=temp->next;
    temp->next->prev=NULL;
    free(temp);
  }
  else{
  while(i<pos){
    temp=temp->next;
    i++;
  }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
  }
}
void reverse_list(){
  temp=start;
  while(temp->next!=NULL)
    temp=temp->next;

  printf("Reversed List is: ");
  while(temp!=NULL){
    printf("<--%d-->",temp->data);
    temp=temp->prev;
  }
}
int main(void) {
  int choice;
  while(1){
    printf("\n\n1.Insert node at end");
    printf("\n2.Insert node at beg");
    printf("\n3.Insert node at specific pos");
    printf("\n4.Delete node at end");
    printf("\n5.Delete node at beg");
    printf("\n6.Delete node at specific pos");
    printf("\n7.Reverse List");
    printf("\n8.Length of List");
    printf("\n9.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    if(choice==1){
      node_insert_end();
      printf("\nNode Inserted Successfully :)");
      print_list();
    }
    if(choice==2){
      node_insert_beg();
      printf("\nNode Inserted Successfully :)");
      print_list();  
    }
    if(choice==3){
      node_insert_specific();
      printf("\nNode Inserted Successfully :)");
      print_list();
    }
    if(choice==4){
      node_delete_end();
      printf("\nNode Deleted Successfully :)");
      print_list();
    }
    if(choice==5){
      node_delete_beg();
      printf("\nNode Deleted Successfully :)");
      print_list();
    }
    if(choice==6){
      node_delete_specific();
      printf("\nNode Deleted Successfully :)");
      print_list();
    }
    if(choice==7){
      reverse_list();
    }
    if(choice==8){
      int len=length_of_list();
      printf("Length of List is: %d",len);
    }
    if(choice==9){
      printf("Program Terminated...");
      break;
    }
  }
  return 0;
}
