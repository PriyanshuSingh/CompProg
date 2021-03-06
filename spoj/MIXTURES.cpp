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
#define gc  getchar_unlocked

int memo[101][101];

int mix[101][101];

int DP(int i,int j){
    if(i == j)return 0;
    else if(memo[i][j] != -1)return memo[i][j];
    else{
	int minS = INF;
	forall(k,i,j){
	    //  printf("%d %d %d",i,k,j);
	    minS = miN(minS,DP(i,k)+DP(k+1,j) + mix[i][k]*mix[k+1][j]);
	}
	memo[i][j] = minS;
    }
    return memo[i][j];
}


int main(){
    int n;
    while(s(n) > 0){
	fill(memo,-1);
	forall(i,0,n){
	    s(mix[i][i]);
	}
	forall(i,0,n){
	    forall(j,i+1,n){
		mix[i][j] = (mix[i][j-1] + mix[j][j])%100;
		//	printf("%d (%d %d)\n",mix[i][j],i,j);
	    }
	}
	printf("%d\n",DP(0,n-1));
    }
    return 0;
}
