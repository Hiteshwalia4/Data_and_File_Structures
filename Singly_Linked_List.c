#include <stdio.h>
struct node{
  int data;
  struct node *next;
};
struct node *start=NULL;
struct node *newNode,*temp;

void allocate_memory(){
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data of node: ");
  scanf("%d",&newNode->data);
  newNode->next=NULL;
}
void node_insert_end(){
  allocate_memory();
  if(start==NULL)
      start=newNode;
  else{
    temp=start;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
  }  
}
void node_insert_beg(){
  allocate_memory();
  if(start==NULL)
    start=newNode;
  else{
    newNode->next=start;
    start=newNode;
  }
}
void node_insert_specific(){
  int i=1,pos;
  temp=start;
  allocate_memory();
  if(start==NULL)
    start=newNode;
  
  else{
  printf("Enter Position where you want to insert node: ");
  scanf("%d",&pos);
  if(pos==1){
   newNode->next=start;
    start=newNode;
  }  
  else{
    while(i<pos-1){
      temp=temp->next;
      i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
  }
  }
}

void node_delete_end(){
  struct node *prev;
  temp=start;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  free(temp);
}
void node_delete_beg(){
  temp=start;
  start=temp->next;
  free(temp);
} 
void node_delete_specific(){
  int i=1,pos;
  struct node *var;
  temp=start;
  printf("Enter Position of node to delete: ");
  scanf("%d",&pos);
  if(pos==1){
   start=temp->next;
    free(temp);
  }
  else{
  while(i<pos-1){
    temp=temp->next;
    i++;
  }
  var=temp->next;
  temp->next=var->next;
  free(var);
  }
}
void print_list(){
  struct node *temp2=start;
  printf("\nData of Linked List: ");
  while(temp2!=NULL){
    printf("%d-->",temp2->data);
    temp2=temp2->next;
  }
}
void length(){
  temp=start;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  printf("Length of List is: %d",count);
}
void reverse_list(){
  struct node *prev=NULL,*curr=start,*nxt;
  while(curr!=NULL){
     nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
  }
  start=prev;
}
int main(void) {
  int choice;
  while(1){
  printf("\n\n1.Insert New Node at end");  
  printf("\n2.Insert New Node at begining"); 
  printf("\n3.Insert New Node at specific pos"); 
  printf("\n4.Delete Node from end");
  printf("\n5.Delete Node from begining");
  printf("\n6.Delete Node from specific pos");
  printf("\n7.Length of List");
  printf("\n8.Reverse a List");
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
  if(choice==7)
    length();
    
  if(choice==8){
    reverse_list();
    print_list();
  }
    
  if(choice==9){
    printf("Program Terminated...");
    break;
  }  
  }
  return 0;
}
