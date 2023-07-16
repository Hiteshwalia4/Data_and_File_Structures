#include <stdio.h>
struct node{
int data;
struct node *next;
};
int main(void) {
  int mid1,mid2,length=0,choice=1,i=1;
  struct node *newNode,*temp,*temp2,*start=NULL;
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
  printf("\nDo you want to insert more nodes(1=Yes,0=No): ");
  scanf("%d",&choice);
  }
  temp2=start;
  printf("\nList is: ");
  while(temp2!=NULL){
    printf("%d-->",temp2->data);
    temp2=temp2->next;
    length++;
  }

    temp2=start;
    mid1=length/2;
    mid2=mid1+1;
  if(length%2==0){
    while(i<mid1){
      temp2=temp2->next;
      i++;
    }
    printf("\nAs length of list is %d(Even), so there will be 2 middle elements...",length);
    printf("\nFirst middle element: %d",temp2->data);
    printf("\nSecond middle element: %d",temp2->next->data);
  }
  else{
    while(i<mid2){
      temp2=temp2->next;
      i++;
    }
    printf("\nAs length of list is %d(Odd), so there will be 1 middle element...",length);
    printf("\nMiddle element: %d",temp2->data);   
  }
  return 0;
}
