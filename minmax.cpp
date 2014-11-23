#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int tcase,n,m,maxB,a;
    long long int A[100001]={0};
    long long int B[100001]={0};
    long long int count;
    scanf("%d",&tcase);
    while(tcase--){
	scanf("%d",&m);
	scanf("%d",&n);
	count =0;
	for(int i=0;i<100001;i++){
	    A[i] = 0;
	    B[i] = 0;
	}
	for(int i=0; i< m; i++){
	    scanf("%d",&a);
	    A[a]++;
	}
	for(int i =0; i<n; i++){
	    scanf("%d",&a);
	    B[a]++;
	}
	int k,l;
	k=0;
	l=100000;
	while(k!=l){
		if(A[k]>B[l]){
		    B[l-1] += B[l];
		    count += B[l];
		    B[l] = 0;
		    l--;
		}
		else{
		    A[k+1] += A[k];
		    count+= A[k];
		    A[k] = 0;
		    k++;
		}    
	}
	printf("%lld\n",count);
    }
    return 0;
}
