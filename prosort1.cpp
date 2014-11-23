#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int T;
    int N;
    int A[100001];
    int su,su2,index1,index2;
    scanf("%d",&T);
    while(T--){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
	    scanf("%d",&A[i]);
	}
	sort(A,A+N);
	su=0;
	su2=0;
	if(N%2==1){
	    index1 = N/2;
	    index2 = N/2 + 1;
	    for(int i = 0;i<N;i++){
		if(i<= index1){
		    su+=A[index1] - A[i];
		    su2 += A[index2] - A[i];
		}
		else{
		    su+=A[i] - A[index1];
		    su2+=A[i] - A[index2];
		}
	    }
	    if(su>su2)su=su2;
	}
	else{
	    index1=N/2;
	    for(int i=0; i<N;i++){
		if(i<=index1)
		    su+= A[index1] - A[i];
		else
		    su+= A[i] - A[index1];
	    }
	}
	printf("%d\n",su);
    }
  return 0;
}
