#include<stdio.h>
#include<string.h>
#include <ctype.h>
using namespace std; 

int main(){
  char a[400],stack_op[200];
  int tcase,i=0,j=0,k=0,len;
 
  scanf("%d",&tcase);
  while(tcase--){
    scanf("%s",a);
    len = strlen(a);
    while(len--){
      switch(a[i]){
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
	stack_op[k++] = a[i];
      default:
	break;
      }
 
      if(isalpha(a[i]))
	a[j++] = a[i];
      else if(a[i] == ')')
	a[j++] = stack_op[--k];
      i++;
    }
    if(k > 0){
      while(k){
	a[j++] = stack_op[--k];
      }
    }
    a[j] = '\0';
    printf("%s\n",a);
    j = 0;
    i = 0;
    len = 0;
    k = 0;
  }
}
