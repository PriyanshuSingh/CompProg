#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  long long int A[100001],min,maxe,mine,cmin,cmax,minCount,maxCount,c,flag;
    int N;
    flag = 1;
    scanf("%d",&N);
    scanf("%lld",&A[0]);
    minCount = 1;
    maxCount = 1;
    maxe = A[0];
    mine = A[0];
    for(int i=1; i<N; i++){
	scanf("%lld",&A[i]);
	if(maxe < A[i]){
	    maxe = A[i];
	    maxCount = 1;
	}
	else if(maxe == A[i]){
	    maxCount++;
	}
	if(mine > A[i]){
	    mine = A[i];
	    minCount=1;
	}
	else if(mine == A[i]){
	    minCount++;
	}
    }
    sort(A,A+N);
    min = A[1] - A[0];
    cmin = 1;
    flag = 0;
    c = 0;
    for(int i=1; i<N-1; i++){
	if(!flag && min > A[i+1] - A[i]){
	    min = A[i+1] - A[i];
	    cmin =  1;
	}
	else if(!flag && min == A[i+1] - A[i]){
	    cmin++;
	}
	if(!flag && A[i-1] == A[i]){
	  c++;
	  flag = 1;
	  cmin = 0;
	}
	else if(A[i-1] == A[i]){
	  c++;
	  flag =1;
	}
	else if(flag){
	  c++;
	  cmin += (c*(c-1))/2;
	  c = 0;
	}
    }
    if(flag){
      if(A[N-1] == A[N-2] && c != 0){
	c += 2;
	cmin += (c*(c-1))/2;
      }
      else if(A[N-1] == A[N-2] && c == 0 && flag){
	cmin++;
      }
      else if(A[N-1] != A[N-2] && c != 0){
	    c++;
	    cmin += (c*(c-1))/2;
	}
    }
    if(minCount == maxCount && mine == maxe){
        cmax = (minCount*(minCount-1))/2;
        printf("%lld %lld",cmax,cmax);
    }
    else{
	cmax = minCount*maxCount;
	printf("%lld %lld",cmin,cmax);
    }
    return 0;
}
