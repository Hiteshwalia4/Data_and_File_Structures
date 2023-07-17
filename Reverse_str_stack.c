#include <stdio.h>
char stack[10],output[10],top=-1;
void push(char el){
  top++;
  stack[top]=el;
}
char pop(){
  char item=stack[top];
  top--;
  return item;
}
int main(void) {
  char str[6];
  printf("Enter any String: ");
  scanf("%s",str);
  int len=sizeof(str)/sizeof(char);
  for(int i=0;i<len;i++)
    push(str[i]);
  
  printf("Reversed String is: ");
  for(int i=top;i>=0;i--){ 
    char el=pop();    
    printf("%c",el);
  }
  return 0;
}
