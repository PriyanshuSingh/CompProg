#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

double DP[20][20];
double match[1<<16];
int N;


double matching(int bitMask){
     
     if (match[bitMask] > -0.5)
	  return match[bitMask];
     if (bitMask == 1<<2*N - 1){
	  match[bitMask] = 0;
	  return match[bitMask];
     }

     double totalMatching = 32767*32767;
     for(int i = 0; i < 2*N; i++){
	  if (!(bitMask&(1<<i))){
	       for(int j = i+1; j < 2*N; j++){
		    if (!(bitMask&(1<<j))){
			 totalMatching = min(totalMatching, DP[i][j] + matching(bitMask | 1<<i | 1<<j ));
		    }
	       }
	       break;
	  }
     } 
     match[bitMask] = totalMatching;
     return totalMatching;
}

int main(){
    int x[20],y[20],i,j,caseNo=1;
    char line[1000],name[1000];

    while(sscanf(gets(line),"%d",&N),N){
	for(i=0; i<2*N; i++)
	    sscanf(gets(line),"%s %d %d",name,&x[i],&y[i]);
	for(i=0;i<2*N;i++)
	    for(j=0;j<2*N;j++){
		DP[i][j] = sqrt((double)((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])));
		printf(" %lf ",DP[i][j]);
	    }
	memset(match,-1,sizeof match);
	printf("Case %d: %.2lf\n",caseNo++,matching(0));
    }
    return 0;
}

