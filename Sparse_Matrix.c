#include <stdio.h>

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
    printf("\n\n1.Check if Matrix is Identity or Not");
    printf("\n2.Check if Matrix is Sparse or Not");
    printf("\n3.Convert Sparse matrix into Row Triplet Form");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice==1){
      int flag=0;
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          if((i==j && mat[i][j]!=1) || (i!=j && mat[i][j]!=0))
            flag=1;
                
      if(flag==1)
        printf("\nMatrix is not Identity :(");
      else
        printf("\nMatrix is Identity :)");  
    }
  else if(choice==2){
    int threshold=n*m;
    int count=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(mat[i][j]==0)
          count++;

    if(count>threshold/2)
      printf("\nEntered Matrix is Sparse :-)");
    else
      printf("\nEntered Matrix is not Sparse :-(");
  }
  else if(choice==3){
    int rt[10][3],count=0,k=0;
    printf("\nRow Triplet Form: \n");
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mat[i][j]!=0){
          count++;
          rt[k][0]=i;
          rt[k][1]=j;
          rt[k][2]=mat[i][j];
          k++;
        }
      }
    }
    for(int i=0;i<count;i++)    
        printf("(%d, %d, %d)\n", rt[i][0], rt[i][1], rt[i][2]);

  }
  else if(choice==4){
    printf("Program Terminated...");
    break;
  }
}
  return 0;
}
