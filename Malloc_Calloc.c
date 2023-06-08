// This program shows the use of malloc(), calloc(), realloc() and free() functions
// used in allocation and deallocation of memory dynamically...

#include <stdio.h>
int sumOfArray(int *arr,int n){
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=*(arr+i);
  return sum;
}
void enter_array(int *arr,int start,int n){
  printf("\nEnter elements of array:\n");
  for(int i=start;i<n;i++)
    scanf("%d",arr+i);  
}
void display_array(int *arr,int n){
  for(int i=0;i<n;i++)
    printf("%d ",*(arr+i));
}
int main(void) {
  int n;
  int *p;
  printf("Enter size of array: ");
  scanf("%d",&n);
  p=(int *)malloc(n*sizeof(int));
  enter_array(p, 0,n);
  printf("Array is: ");
  display_array(p,n);
  int sum=sumOfArray(p, n);
  printf("\nSum of elements using malloc(): %d",sum);

  free(p);
  printf("\n\nArray after using free() is: ");
  display_array(p, n);
  
  p=(int *)calloc(n,sizeof(int));
  printf("\n");
  enter_array(p, 0,n);
  printf("Array is: ");
  display_array(p,n);
  sum=sumOfArray(p, n);
  printf("\nSum of elements using calloc(): %d",sum);

  p=realloc(p,2*n*sizeof(int));
  printf("\n\nArray after realloc(array,2*size): ");
  display_array(p, 2*n);
  printf("\nEnter remaining elements of array...");
  enter_array(p, n, 2*n);
  printf("Array is: ");
  display_array(p,2*n);
  
  sum=sumOfArray(p, 2*n);
  printf("\nSum of elements after using realloc(): %d",sum);
  
  return 0;
}
