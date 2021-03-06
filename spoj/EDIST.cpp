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

using namespace std;

int memo[2001][2001];
char A[2001];
char B[2001];
int lnA,lnB;

int DP(int i,int j){
  //    printf("%d %d = %d\n",i,j,memo[i][j]);
    if(memo[i][j] != -1)return memo[i][j];
    else{
	if(A[i] == B[j]){
	    memo[i][j] = DP(i+1,j+1);
	}
	else{
	 
	    memo[i][j] = miN(miN(DP(i+1,j),DP(i,j+1)),DP(i+1,j+1)) + 1;
	}
    }

    return memo[i][j];
}

int main(){
    int t;
    s(t);
    while(t--){
	ss(A);ss(B);
	lnA = strlen(A);
	lnB = strlen(B);
	fill(memo,-1);
	forall(i,0,lnB+1){
	    memo[lnA][i] = lnB-i;
	}
	forall(i,0,lnA+1){
	    memo[i][lnB] = lnA-i;
	}
	printf("%d\n",DP(0,0));
    }
    return 0;
}
