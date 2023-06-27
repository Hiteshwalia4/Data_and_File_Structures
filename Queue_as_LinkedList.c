#include <stdio.h>
struct node{
  int data;
  struct node *next;
};
struct node *front=NULL,*rear=NULL,*newNode,*temp;
void enqueue(int el){
  newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=el;
  newNode->next=NULL;
  if(rear==NULL){
    rear=newNode;
    front=newNode;
  }
  else{
    rear->next=newNode;
    rear=newNode;
  }
}
void dequeue(){
  temp=front;
  printf("\nDequeued element is: %d",front->data);
  front=front->next;
  free(temp);
}
void peek(){
  if(front==NULL && rear==NULL)
    printf("\nQueue is Empty..");
  else
    printf("\nTopmost element is: %d",front->data);
}
void print_queue(){
  if(front==NULL && rear==NULL)
    printf("\nQueue is Empty..");
  else{ 
  temp=front;
  printf("\nQueue is: ");
  while(temp!=NULL){
    printf("%d--",temp->data);
    temp=temp->next;
  }
}
}
int main(void) {
int choice;
  while(1){
    printf("\n\n1.Insert Item in Queue");
    printf("\n2.Delete Item from Queue");
    printf("\n3.Print Topmost element");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    if(choice==1){
      int el;
      printf("\nEnter item: ");
      scanf("%d",&el);
      enqueue(el);
      print_queue();
    }
    if(choice==2){
      dequeue();
      print_queue();
    }
    if(choice==3){
      peek();
    }    
    if(choice==4){
      printf("Program Terminated...");
      break;
    }
  }
  return 0;
}
