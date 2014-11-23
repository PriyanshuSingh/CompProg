#include <iostream> 
#include <cstdio>
#define M 1000001
#define MOD 1000000009
int memo[M];

void r(){
    memo[1] = 1;
    memo[2] = 1;
    for(int i=3;i<M;i++){
	memo[i] = memo[i-1] + memo[i-2];
	if(memo[i] > MOD){
	    memo[i] -= MOD;
	}
    }
}

int main(){
    r();
    return 0;
}
