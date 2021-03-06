#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
char n[1000010];

bool check(int mid,int mid2,int start,int end){
  //  printf("%d %d %d %d\n",mid,mid2,start,end);
    if(n[mid] == n[mid2]){
	while(n[mid] == n[mid2] && mid >=0 && mid2 <=end){
	    mid--;mid2++;
	}
	if(mid<0){
	    return true;
	}
	else if(n[mid] < n[mid2])
	    return true;
	return false;
    }
    else if(n[mid] > n[mid2]){
	return false;
    }
    else{
	return true;
    }
}
bool incr(int i,int j){
    if(n[i] == '9'){
      //printf("got here");
	n[i] = '0';
	n[j] = n[i];
	return true;
    }
    else{
	n[i]++;
	n[j] = n[i];
	return false;
    }
}

bool process(int start,int end){
    int mid = (start+end)/2;
    bool inc = check(mid,end-mid,start,end);
    //  printf("%d\n",inc);
    for(int i=mid,j=end-mid;i>=0 && j <=end; i--,j++){
	if(inc == true){
	  //  printf("INCREASING %c %c index(%d %d)\n",n[i],n[j],i,j);
	    inc = incr(i,j);
	}
	else{
	    n[j] = n[i];
	}
    }
    if(inc)n[end] = '1';
    return inc;
}

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
	gets(n);
	//	printf("%s  %d\n",n,strlen(n));
	if(process(0,strlen(n)-1))printf("1");
	printf("%s\n",n);
    }
}
