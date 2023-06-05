// A menu driven program that sorts an array using: 
// 1. Insertion Sort.
// 2. Bubble Sort.
// 3. Selection Sort.
// 4. Count Sort.
// 5. Radix Sort.

#include <stdio.h>
void printarray(int arr[],int n){
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("");
}
void insertion_sort(int arr[],int n){
  int temp,j;
  for(int i=1;i<n;i++){
    temp=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>temp){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=temp;
  }
}
void bubble_sort(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
      if(flag==0)
        break;
    }
  }
}
void selection_sort(int arr[],int n){
  int min;
  for(int i=1;i<n;i++){
    min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min])
        min=j;
    }
    if(min!=i)
      {
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
      }
  }
}
void count_sort(int arr[],int n){
  int max=arr[0];
  int output[n];
  for(int i=1;i<n;i++){
    if(arr[i]>max)
      max=arr[i];
  }
  int count[max+1];
  for(int i=0;i<max+1;i++)
    count[i]=0;
      
  for(int i=0;i<n;i++)
    count[arr[i]]++;
  
  for(int i=1;i<=max;i++)
    count[i]=count[i]+count[i-1];

  for(int i=n-1;i>=0;i--){
    output[count[arr[i]]-1]=arr[i];
    count[arr[i]]--;
  }
  for(int i=0;i<n;i++)
    arr[i]=output[i];
}
void radix_count_sort(int arr[],int n,int pos){
  int output[n];
  int count[10]={0};
  for(int i=0;i<n;i++)
    count[(arr[i]/pos)%10]++;

  for(int i=1;i<=9;i++)
    count[i]+=count[i-1];

  for(int i=n-1;i>=0;i--){
    output[count[(arr[i]/pos)%10]-1]=arr[i];
    count[(arr[i]/pos)%10]--;
  }
  for(int i=0;i<n;i++)
    arr[i]=output[i];

}
void radix_sort(int arr[],int n){
  int max=arr[0];
  for(int i=1;i<n;i++){
    if(arr[i]>max)
      max=arr[i];
  }
  for(int pos=1;max/pos>0;pos=pos*10)
    radix_count_sort(arr,n,pos);
}
int main() {
  int arr[10];
  int n, choice;
  printf("Enter number of elements of array: ");
  scanf("%d",&n);
  printf("\nEnter elements of the array: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nArray is: ");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  
  while(1){
    printf("\n\n1.Sort Array using Insertion Sort");
    printf("\n2.Sort Array using Bubble Sort");
    printf("\n3.Sort Array using Selection Sort");
    printf("\n4.Sort Array using Count Sort");
    printf("\n5.Sort Array using Radix Sort");
    printf("\n6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    if (choice==1){
      insertion_sort(arr,n);
      printf("\nSorted Array using Insertion Sort: ");
      printarray(arr,n);
    }
    else if(choice==2){
      bubble_sort(arr,n);
      printf("\nSorted Array using Bubble Sort: ");
      printarray(arr,n);
    }
      else if(choice==3){
        selection_sort(arr,n);
        printf("\nSorted Array using Selection Sort: ");
        printarray(arr,n);
      }
      else if(choice==4){
        count_sort(arr,n);
        printf("\nSorted Array using Count Sort: ");
        printarray(arr,n);
      }
      else if(choice==5){
        radix_sort(arr,n);
        printf("\nSorted Array using Radix Sort: ");
        printarray(arr,n);
      }
    else if(choice==6){
      printf("Program Terminated...");
      break;
    }
  }
  return 0;
}
