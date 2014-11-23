#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int MAX = 100001;

// boolean isPrime[100001]={true};
// int sp[100001];
// void initSieve(){
//     for(int i=2; i<50001; i++){
// 	if(isPrime[i]){
// 	    for(int j=2*i; j<100001; j+=i){
// 		isPrime[j] = false;
// 	    }
// 	}
//     }
// }
bool v[MAX]={false};
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (long long int i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (long long int j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

vector<int> fac(int b){
    vector<int> f;
    while(sp[b] != b){
	f.push_back(sp[b]);
	b = b/sp[b];
    }
    f.push_back(sp[b]);
    return f;
}

long long int foo(int n, int prime){
    int sum=0;
    while(n/prime != 0){
	sum+= n/prime;
	n=n/prime;
    }
    return sum;
}
int main(){
    vector<int> factor;
    int T;
    int n,b;
    long long int min,temp;
    scanf("%d",&T);
    while(T--){ 
	scanf("%d",&n);
	scanf("%d",&b);
	factor = fac(b);
	min = foo(n,factor[0]);
	for(int i=1; i < factor.size(); i++){
	    temp = foo(n,factor[i]);
	    if(min > temp) min = temp;
	}
	printf("%lld\n",temp);
    }
}
