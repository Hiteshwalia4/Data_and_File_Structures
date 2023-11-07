// A menu driven program that includes:
// 1. Inserting elements in an array.
// 2. Largest and Second largest element of the array.
// 3. Search using Linear Search.
// 4. Search using Binary Search.
// 5. Delete an element from array.
  
#include <stdio.h>
void printarr(int arr[],int n){
  printf("\nArray is: ");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
void insert(int el,int pos,int n,int arr[]){
  for(int i=n-1;i>=pos;i--)
    arr[i+1]=arr[i];
  arr[pos]=el;
}
void largest(int arr[],int n,int max,int sl){
  max=arr[0];
  for(int i=1;i<n;i++){
    if(arr[i]>max){
      sl=max;
      max=arr[i];
    }
    else if (arr[i]>sl && arr[i]<max){
      sl=arr[i];
    }
  }
  printf("\nLargest element of array is: %d",max);
  printf("\nSecond Largest element of array is: %d",sl);
}
void linear(int arr[],int n, int ser_el){
  int i,count=0;
  for(i=0;i<n;i++){
    if(arr[i]==ser_el){
      printf("\nElement found at index: %d",i);
      count++;
    }
  }
  if(count==0)
    printf("\nElement Not Found :-(");
  else
    printf("\nElement's count: %d",count);
}
void binary(int arr[],int ser,int lb,int ub){
  while(lb<=ub){
  int mid=(lb+ub)/2;
  if(arr[mid]==ser){
    printf("\nElement found at index: %d",mid);
    break;
  }
  else if(ser>arr[mid])
    lb=mid+1;
    
  else if(ser<arr[mid]){
      ub=mid-1;
  }
  }
  if(lb>ub)
    printf("\nElement Not Found...");   
}
int binary_rec(int arr[],int ser,int low,int high){
  if(low<=high){
  int mid=(low+high)/2;
  if(arr[mid]==ser)
     return mid;
  else if(ser<arr[mid])
     return binary_rec(arr,ser,low,mid-1);
  
  else if(ser>arr[mid])
    return binary_rec(arr, ser,mid+1,high);
  }
  return -1;
}
void demlete(int pos,int n,int arr[]){
  for(int i=pos-1;i<n-1;i++)
    arr[i]=arr[i+1];
}
int main() {
  int arr[10];
  int n,choice,ser_el,ser;
  int max,sl,el,pos,noOfAttempts=3;
  printf("Enter number of elements you want in array: ");
  scanf("%d",&n);

  printf("Enter elements of the array: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

  printarr(arr,n);

  while(1){
  printf("\n\n1.Insert an element");
  printf("\n2.Largest and second largest element of the array");
  printf("\n3.Search using Linear Search");
  printf("\n4.Search using Binary Search");
  printf("\n5.Delete an element");
  printf("\n6.Exit");
  printf("\nEnter your choice: ");
  scanf("%d",&choice);

  if(choice==1){
    printf("\nEnter element which you want to insert: ");
    // int el=scanf("%d",&el);
    scanf("%d",&el);
    printf("\nEnter position at which element is to be inserted: ");
    scanf("%d",&pos);
    insert(el,pos,n,arr);
    n++;
    printf("\nElemented inserted sucessfully :-)");
    printarr(arr,n); 
  }
    else if(choice==2){
      largest(arr, n, max,0);  
    }
    else if(choice==3){
      printf("Enter element to search: ");
      scanf("%d",&ser_el);
      linear(arr,n,ser_el);
    }
    else if(choice==4){
      printf("Enter element to search: ");
      scanf("%d",&ser);
      printf("\n----Binary Search without Recursion----");
      binary(arr,ser,0,n-1);
      printf("\n----Binary Search with Recursion----");
      int res=binary_rec(arr,ser,0,n-1);
      if(res==-1)
        printf("\nElement not Found...");
      else
        printf("\nElement Found at index: %d",res);
    }
    else if (choice==5){
      int pos;
      printf("\nEnter position of the element to be deleted: ");
      scanf("%d",&pos);
      if(pos>=1 && pos<=n){ 
        demlete(pos,n,arr);
        n--;
        printf("\nElemented deleted sucessfully :-)");
        printarr(arr,n);
      }
      else
        printf("Wrong position entered, Please Enter Correct postion....");
    }
    else if(choice==6){
      printf("Program Terminated...\n");
      break; 
    }
    else{
      if(noOfAttempts<1) {
        printf("\nAttempt Limit Reached, Program Terminated :(");
        break;
      }
        
      printf("\nPlease Enter a Valid Number!!");
      printf("\nNumber of attempts left: %d",noOfAttempts);
      noOfAttempts--;
    }
  }
  return 0;
}
