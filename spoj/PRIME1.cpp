#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime[32000];
int PRIME[3432];
int p=0;
void sieve(){
    
    for(int i=0;i<32000;i++)is_prime[i] = true;
    for(int i=2;i<32000;i++){
	if(is_prime[i]){
	    PRIME[p++] = i;
	    // printf("%d ",p);
	    for(int j=2*i; j<32000; j+=i)is_prime[j]=false;
	}
    }
}
int main(){

    sieve();
    bool A[100001];
    int t,n,m,temp;
    bool flag;
    scanf("%d",&t);
    while(t--){
	scanf("%d",&n);
	scanf("%d",&m);
	if(n==1)n++;
	for(int i=n;i<=m;i++){
	    temp = sqrt(i)+1;
	    flag = true;
	    for(int j=0; PRIME[j]<temp; j++){
		if(i%PRIME[j] == 0){
		    flag = false;
		    break;
		}
	    }
	    if(flag)printf("%d\n",i);
	}
	printf("\n");
    }
    return 0;
}
