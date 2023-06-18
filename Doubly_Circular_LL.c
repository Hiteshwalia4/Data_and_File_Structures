#include <stdio.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
};
struct node *tail=NULL,*start;
struct node *newNode,*temp;
void allocate_memory(){
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data of node: ");
  scanf("%d",&newNode->data);
  newNode->next=NULL;
  newNode->prev=NULL;
}
void node_insert_end(){
  allocate_memory();
  if(tail==NULL){
      tail=newNode;
      newNode->next=tail;
      newNode->prev=tail;
  }
  else{
    newNode->next=tail->next;
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}
}
void node_insert_beg(){
  allocate_memory();
  if(tail==NULL){
    tail=newNode;
    newNode->next=tail;  
    newNode->prev=tail;  
  }
  else{
    newNode->next=tail->next;
    newNode->prev=tail;
    tail->next->prev=newNode;
    tail->next=newNode;
  }
}
void node_insert_specific(){
  int i=1,pos;
  allocate_memory();
  if(tail==NULL){
    tail=newNode;
    newNode->next=tail;  
    newNode->prev=tail;  
  }
  else{
  printf("Enter Position where you want to insert node: ");
  scanf("%d",&pos);
    temp=tail->next;
    while(i<pos-1){
      temp=temp->next;
      i++;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
  }
}
void node_delete_end(){
  struct node *temp2=tail;
  if(tail==tail->next)
    tail=NULL;
  else{ 
  temp=tail->next;
  temp->prev=tail->prev;
  tail->prev->next=temp;
  tail=tail->prev;
  }
  free(temp2);
}
void node_delete_beg(){
  if(tail==tail->next){
    free(tail);
    tail=NULL;
  }
  else{ 
  temp=tail->next;
  tail->next=temp->next;
  temp->next->prev=tail;
  free(temp);
  }
} 
void node_delete_specific(){
  int i=1,pos;
  temp=tail->next;
  struct node *var;
  printf("Enter Position of node to delete: ");
  scanf("%d",&pos);
  while(i<pos-1){
    temp=temp->next;
    i++;
  }    
  var=temp->next;
  temp->next=var->next;
  var->next->prev=temp;
  free(var);
}
void print_list(){
  struct node *temp2=tail->next;
  if(tail==NULL)
    printf("\nList is empty...");
  else{
  printf("\nData of Linked List: ");
  while(temp2->next!=tail->next){
    printf("<--%d-->",temp2->data);
    temp2=temp2->next;
  }
  printf("<--%d-->",temp2->data);
  }
}
void length(){
  if(tail==NULL)
    printf("List is Empty..");
  else{ 
  temp=tail->next;
  int count=0;
  while(temp!=tail){
    count++;
    temp=temp->next;
  }
  printf("Length of List is: %d",count+1);
  }
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
  printf("\n8.Exit");
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
    printf("Program Terminated...");
    break;
  }  
  }
  return 0;
}
