# include<stdio.h>
int queue[5];
int n=sizeof(queue)/sizeof(int);
int front=-1;
int rear=-1;
void enqueue(int el){
  if((rear+1) % n== front)
    printf("\nQueue is Full!!");
  else if(front==-1 && rear==-1){
    front=0;
    rear=0;
    queue[rear]=el;
  }
  else{
    rear=(rear+1) % n;
    queue[rear]=el;
  }   
}
void dequeue(){
  if(front==rear){
    printf("\nDequeued element is: %d",queue[front]);
    front=-1;
    rear=-1;
  }
  else{
    printf("\nDequeued element is: %d",queue[front]);
    front= (front+1) % n;
  }
}
void peek(){
  if(front==-1 && rear==-1)
    printf("\nQueue is Empty..");
  else
    printf("\nTopmost element is: %d",queue[front]);
}
void print_queue(){
  if(front==-1 && rear==-1)
    printf("\nQueue is Empty..");
  else{ 
  printf("\nQueue is: ");
  // for(int i=front;i<=rear;i=(i+1) % n)
  //   printf("%d--",queue[i]);
  int i=front;
    while(i!=rear){
    printf("%d--",queue[i]);
   i=(i+1)%n;   
    }
    printf("%d--",queue[i]);
    
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
