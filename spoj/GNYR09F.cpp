#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
// datatypes
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

int memo[101][101][2];

int DP(int n,int k,int bit){

    if(n<k || k<0)return 0;
    else if(memo[n][k][bit] != -1)return memo[n][k][bit];
    else if(k==0 && n ==0)memo[n][k][bit]=1;
    else if(k==0 && n == 1){
	if(bit==0)memo[n][k][bit] = 2;
	else
	    memo[n][k][bit] = 1;
    }
    else{
	if(bit == 0){
	    memo[n][k][bit] = DP(n-1,k,0)+DP(n-1,k,1);
	}  
	else{
	    memo[n][k][bit] = DP(n-1,k,0)+DP(n-1,k-1,1);
	}
    }
    //  printf("%d %d %d\n",n,k,bit);
    return memo[n][k][bit];
}

int main(){
    int t;
    int a,n,k;
    s(t);
    while(t--){
	fill(memo,-1);
	s(a);s(n);s(k);
	printf("%d %d\n",a,DP(n,k,0));
    }
    return 0;
}
