#include <stdio.h>

int main(void) {
  int n,sum=0;
  printf("Enter number of elements of array: ");
  scanf("%d",&n);
  int *arr=(int *)malloc(n*sizeof(int));
  printf("Enter elements of array: ");
  for(int i=0;i<n;i++)
    scanf("%d",arr+i);
  printf("\nEntered Array is: ");
  for(int i=0;i<n;i++)
    printf("%d ",*(arr+i));

  int org_sum=(n*(n+1))/2;
  for(int i=0;i<n;i++)
    sum=sum + *(arr+i);

  int res=org_sum-sum;
  if(res!=0)
    printf("\nMissing element in array is: %d",res);
  else
    printf("\nThere is no missing element in array..");
  return 0;
}
