#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int l[3];
bool B[300][300];

int main(){

    int A[2501];
    int count[201];
    int tcase,p,q;
    scanf("%d",&tcase);
    while(tcase--){
	scanf("%d",&p);
	scanf("%d",&q);
	for(int i=0; i<300; i++){
	    for(int j=0; j<300; j++){
		B[i][j] = true;
	    }
	}
        for(int i=0; i<201;i++){
	     count[i] = 0;
	}
	for(int i=0; i<p*q; i++){
	    scanf("%d",&A[i]);
	    count[A[i]+100]++;
	}
	for(int i=0; i<p*q; i++){
	    for(int j=i+1; j<p*q; j++){
		if(A[i]+A[j] > 100 || A[i]+A[j] < -100){
		    continue;
		}
		else if(count[-(A[i]+A[j]) + 100] == 0){
		    continue;
		}
		else if(A[i] ==0 && A[j] == 0 && B[100][100] && count[100] >= 3){
		    printf("0 0 0\n");
		    B[100][100] = false; 
		}
		else{
		    // for(vector<int>::iterator it=count[-(A[i]+A[j]) + 100].begin(); it != count[-(A[i]+A[j])+100].end(); ++it){
		      //	if(*it > j){
			  //			  printf("%d %d %d sdkjfskjdf\n",i,j,*it);
		  int guess = -(A[i]+A[j]);
		  if(guess == A[i] && count[A[i]] <2){
		      continue;
		  }
		  else if(guess == A[j] && count[A[j]] < 2){
		      continue;
		  }
			    l[0] = A[i];
			    l[1] = A[j];
			    l[2] = guess;
			    sort(l,l+3);
			    if(B[l[0]+100][l[1]+100]){
				printf("%d %d %d\n",l[0],l[1],l[2]);
				B[l[0]+100][l[1]+100] = false;
			    }
			    //	}
			    // }
		}
	    }
	}
    }
    return 0;
}
