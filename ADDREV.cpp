#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int A[20];

int rev(int n){
    int i=0;
    if(n==0)return 0;
    while(n != 0){
	A[i++] = n%10;
	n/=10;
    }
    //    printf("%d;;",n);
    for(int j=0  ; j<i ; j++){
      // printf("%d\n",A[j]);
	n = 10*n + A[j];
    }
    return n;
}

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
	scanf("%d",&n);
	scanf("%d",&m);
	printf("%d\n",rev(rev(n)+rev(m)));
    }
    return 0;
}
