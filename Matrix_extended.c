// A menu driven program that performs the following operations:
//     1.Print all Diagonal Elements
//     2.Print Sum of all Rows
//     3.Arrange all Rows in ascending order

#include <stdio.h>
void sort(int *mat,int n){   
  int temp,j;
  for(int i=1;i<n;i++){
    temp=mat[i];
    j=i-1;
    while(j>=0 && mat[j]>temp){
      mat[j+1]=mat[j];
      j--;
    }
    mat[j+1]=temp;
    }
  }
int main(void) {
  int n, m,choice;
  printf("Enter number of rows of matrix: ");
  scanf("%d", &n);
  printf("\nEnter number of columns of matrix: ");
  scanf("%d", &m);

  int **mat=(int **)malloc(n*sizeof(int *));
  for(int i=0;i<n;i++)
    mat[i]=(int *)malloc(m*sizeof(int));

  printf("\nEnter elements of matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &mat[i][j]);

  printf("Entered matrix is: \n");
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }

while (1) {
    printf("\n\n1.Print all Diagonal Elements");
    printf("\n2.Print Sum of all Rows");
    printf("\n3.Arrange all Rows in ascending order");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==1){
    printf("\nMain Diagonal elements are: ");
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          if(i==j)
            printf("%d ",mat[i][j]);
          
    printf("\nRight Diagonal elements are: ");
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          if(i+j==n-1)
            printf("%d ",mat[i][j]);
  }
  else if(choice==2){
    int sum=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        sum=sum+mat[i][j];

    printf("\nSum of all rows: %d",sum);
    
  }
  else if(choice==3){
    for(int i=0;i<n;i++)
      sort(mat[i],n);
    
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
  }
  else if(choice==4){
    printf("Program Terminated...");
    break;
  }
}
  return 0;
}
