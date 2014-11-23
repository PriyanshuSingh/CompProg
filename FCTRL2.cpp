#include<stdio.h>
#include<string.h> 
 
 
static char str[159];
 
void mul(int n);
void print(void);
 
void factorial(int n){
 
 
  if(n == 0){
    str[0] = '1';
    str[1] = '\0';
    return;
  }
  factorial(n -1);
  mul(n);
  return;
}
 
void mul(int n){
 
  int sum = 0;
  int carry = 0;
  int i = 0;
 
  while(str[i]){
    sum = (str[i] - '0')*n + carry;
    str[i] = sum % 10 + '0';
    carry = sum / 10;
    i++;
  }
 
  while(carry != 0){
    str[i] = carry % 10 + '0';
    carry /= 10;
    i++;
  }
  str[i] = '\0';
}
 
int main(){
 
  int tcase,n;
  scanf("%d", &tcase);
 
  while(tcase--){
 
    scanf("%d", &n);
    factorial(n);
    print();
  }
}
 
void print(void){
 
  int s = strlen(str);
  int i = 0;
 
  for(i = s - 1; i >= 0; i--){
    printf("%c",str[i]);
  }
  printf("\n");
}
