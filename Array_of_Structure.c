//Program demonstrates array of structure and finds the
//employee with the maximum salary.
  
#include <stdio.h>
struct emp{
int eid;
char ename[20];
int esal;
} s;
int main(void) {
  int max=0,val;
  struct emp s[5];
  for(int i=0;i<5;i++){
    printf("Enter Employee ID: ");
    scanf("%d",&s[i].eid);
    printf("Enter Employee Name: ");
    scanf("%s",s[i].ename);
    printf("Enter Employee Salary: ");
    scanf("%d",&s[i].esal);
    printf("\n");
  }
  for(int i=0;i<5;i++){
    if(s[i].esal>max){
      max=s[i].esal;
      val=i;
    }
  }
  printf("\n----Employee with highest salary----\n");
  printf("Emp ID: %d\nEmp Name: %s\nEmp Salary: %d\n",s[val].eid,s[val].ename,max);
  return 0;
}
