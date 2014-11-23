#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream> 
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

#define M 1000000007

ll modpow(int a,int n){
	int r=1;
	for(ll x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}
 
int inv(int a){
	return modpow(a,M-2);
}


ll modnCr(ll n,ll r){	// calc nCr (mod M) (M:prime)
      if(n<r)return 0;
      if(n-r<r)r=n-r;
 
      ll res=1;
      for(int i=r;i>0;i--){
	  res=(res*((n-i+1)%M))%M;
	  res=(res*inv(i))%M;
      }
      return res;
}

int main(){
    int t;
    int n,m,sum,temp;
    s(t);
    while(t--){
	s(n);s(m);
	sum = 0;
	forall(i,0,n){
	    s(temp);
	    sum+=temp;
	}
	printf("%lld\n",modnCr(m-sum+n-1,n-1));	
    }
    return 0;
}
