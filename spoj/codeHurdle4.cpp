#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
int fib[] = {0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986};
vector<int> FIB(fib,fib+sizeof(fib)/sizeof(int));

int sumDivisor(int n,int m){
    int sqroot = (int) sqrt(n);
    int sum=0;
    if(n == 1)return 1;
    for(int i=1; i <= sqroot; i++){
	if(n%i == 0){
	    sum = (sum + i + n/i )%m;
	}
    } 
    if(sqroot*sqroot == n){
	sum = sum - sqroot;
	if(sum < 0){
	    sum = m - sum;
	}
    }
    return sum;
}

bool devilNumber(int n){
    int sqroot = (int) sqrt(n);
    int sum = 0;
    if(n==1)return true;
    for(int i=1; i <= sqroot; i++){
	if(n%i == 0){
	    sum += 2;
	}
    } 
    if(sqroot*sqroot == n){
	sum--;
    }
    if(binary_search(FIB.begin(),FIB.end(),sum)){
	return true;
    }
    else{
	return false;
    }
}
int main(){
    int t,n,m;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
	scanf("%d",&n);
	scanf("%d",&m);
	if(devilNumber(sumDivisor(n,m))){
	  printf("Case #%d : YES.\n",i);
	}
	else{
	  printf("Case #%d : NO.\n",i);
	}
    }
    return 0;
}
