#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
bool is_prime[100001]={true};
vector<int> PRIME;
vector<int> PA[100001];
void sieve(){
    for(int i=2;i<100001;i++){
	if(is_prime[i]){
	    PRIME.push_back(i);
	    for(int j=2*i;j<100001;j+=i){
		is_prime[i] = false;
	    }
	}
    }
}


void precal(){
    int temp;
    for(int i=2; i < 100001; i++){
	printf(" %d :: ",i);
	if(is_prime[i]){
	    PA[i].push_back(i);
	}
	else{
	  temp = i/2 + 1;
	    for(int j=0; PRIME[j] <= temp; j++){
		if(i%PRIME[j] == 0){
		    PA[i].push_back(i);
		    while(i%PRIME[j]==0)i=i/PRIME[j];
		    if(is_prime[j])
			PA[i].push_back(i);
		}
	    }
	}
    }
}


int main(){
    sieve();
    precal();
    for(int i=0; i<100001;i++){
      printf("%d ::",i);
      for(vector<int>::iterator it=PA[i].begin(); it != PA[i].end(); ++it){
	printf(" %d ",*it);
      }
      printf("\n");
    }
    return 0;
}



