#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
int p[] = {5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125};
long int Z(int n){
    long int sum = 0;
    int i=0,k;
    while((k = n/p[i++])!=0)sum+=k;
    return sum;
}

int main(){
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
	scanf("%d",&n);
	printf("%ld\n",Z(n));
    }
    return 0;
}
