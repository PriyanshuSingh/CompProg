#include <iostream>
#include <cstdio>

using namespace std;

double dp[51][50][100];
double ans;

inline void init(){
    for(int i=0;i<51;i++){
	for(int j=0;j<50;j++){
	    for(int k=0;k<100;k++){
		dp[i][j][k] = 0.0;
	    }
	}
    }
    for(int i=0;i<50;i++){
	dp[0][i][1] = 1;
    }
}

int main(){

    int N,K,T,C;
    int Li,Ri;
    scanf("%d",&T);


    while(T--){
	init();
	scanf("%d %d %d",&N,&C,&K);
	for(int i=1;i<=K;i++){
	    scanf("%d %d",&Li,&Ri);
	    Li--;
	    Ri--;
	    for(int j=0;j<N;j++){
		for(int k=0;k<C;k++){
		    if(j>=Li && j<=Ri){
			dp[i][j][k] += dp[i-1][j][k]*0.5;
			for(int l=0;l<C;l++){
			    dp[i][j][(k*l)%C] += dp[i-1][j][k]/(2*C);
			}
		    }
		    else
			dp[i][j][k] = dp[i-1][j][k];
		}
	    }
	}
	ans = 0.0;
        for(int j=0;j<N;j++){
	    for(int k=0;k<C;k++){
		ans += dp[K][j][k]*k;
	    }
	}
	printf("%0.9lf\n",ans);
    }
    return 0;
}
