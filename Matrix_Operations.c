// A menu driven program that performs the following matrix opeartions:
// 1.Add two Matrices.
// 2.Subtract two Matrices.
// 3.Multiply two Matrices.
// 4.Check if two Matrices are Identical or not.

#include <stdio.h>
void print_matrix(int n, int m, int **arr) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      printf("%d\t", arr[i][j]);
    printf("\n");
  }
}
void enter_mat(int n,int m,int **arr){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &arr[i][j]);
 
}
int main(void) {
  int n1, m1,n2,m2, choice;
  printf("Enter number of rows of 1st matrix: ");
  scanf("%d", &n1);
  printf("\nEnter number of columns of 1st matrix: ");
  scanf("%d", &m1);

  int **mat1=(int **)malloc(n1*sizeof(int **));
  for(int i=0;i<n1;i++)
    mat1[i]=(int *)malloc(m1*sizeof(int));
  
  printf("\nEnter elements of 1st matrix:\n");
  enter_mat(n1, m1, mat1);
  
  printf("\nEnter number of rows of 2nd matrix: ");
  scanf("%d", &n2);
  printf("\nEnter number of columns of 2nd matrix: ");
  scanf("%d", &m2);

  int **mat2=(int **)malloc(n2*sizeof(int **));
  for(int i=0;i<n2;i++)
    mat2[i]=(int *)malloc(m2*sizeof(int));
  
  printf("\nEnter elements of 2nd matrix:\n");
  enter_mat(n2, m2, mat2);
  
  printf("\n1st Matrix is:\n");
  print_matrix(n1, m1, mat1);
  printf("\n2nd Matrix is:\n");
  print_matrix(n2, m2, mat2);

  int **res=(int **)malloc(n1*sizeof(int **));
  for(int i=0;i<n1;i++)
    res[i]=(int *)malloc(m2*sizeof(int));

  while (1) {
    printf("\n\n1.Add two Matrices");
    printf("\n2.Subtract two Matrices");
    printf("\n3.Multiply two Matrices");
    printf("\n4.Check if two Matrices are Identical or not");
    printf("\n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==1){
      if(n1==n2 && m1==m2){
      for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
          res[i][j]=mat1[i][j]+mat2[i][j];
          
      printf("\nAddition is: \n");
      print_matrix(n1,m1,res);  
      }
      else
        printf("\nCannot perform Addition as order of both matrices is not same...");
    }
    else if (choice==2){
      if(n1==n2 && m1==m2){
      for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
          res[i][j]=mat1[i][j]-mat2[i][j];

      printf("\nSubtraction is: \n");
      print_matrix(n1,m1,res);  
      }
      else
        printf("\nCannot perform Addition as order of both matrices is not same...");
    } 
    else if (choice==3){
    if(m1==n2){
      for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
          res[i][j]=0;
          for(int k=0;k<n2;k++)
            res[i][j]=res[i][j] + mat1[i][k] * mat2[k][j];
        }
      }
      printf("\nMultiplication is: \n");
      print_matrix(n1,m2,res);
    }
      else
      printf("Cannot Perform Matrix Multiplication...");
    }
    else if (choice==4){
      int flag=1;
      if(n1==n2 && m1==m2){
        for(int i=0;i<n1;i++){
          for(int j=0;j<m1;j++){
            if(mat1[i][j]!=mat2[i][j]){
              flag=0;
              break;
            }
          }
        }
      } 
      else{
        flag=0;
      }
      if(flag==0)
        printf("The two matrices are not identical :-(");
      else
        printf("The two matrices are identical :-)");
    }
    else if (choice==5){
      printf("\nProgram Terminated...");
      break;
    }
  }
  return 0;
}
