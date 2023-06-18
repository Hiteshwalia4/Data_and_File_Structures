#include <stdio.h>
int stack[5];
int top=-1;
int n= sizeof(stack)/sizeof(int);
void push(int el){
  if(top==n-1)
    printf("\nStack Overflow!!!");
  else{ 
  ++top;
  stack[top]=el;
  }
}
void pop(){
  if(top==-1)
    printf("\nStack Underflow!!!");
  else{ 
    int temp=stack[top];
    top--;
    printf("\nPopped item is: %d",temp);
  }
}
void display_stack(){
  printf("\nStack is: ");
  for(int i=top;i>=0;i--)
    printf("%d| ",stack[i]);
}
int main(void)
{
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
