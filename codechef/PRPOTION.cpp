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

inline void fs(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int mxR,mxG,mxB,M;
int process(){
    int mx = maX(mxR,maX(mxB,mxG));
    int mn = mx;
    while(M--){
	if(mxR >= mxB && mxR >= mxG){
	    mxR/=2;
	}
	else if(mxB >= mxR && mxB >= mxG){
	    mxB/=2;
	}
	else{
	    mxG/=2;
	}
	mx = maX(mxR,maX(mxB,mxG));
	mn = miN(mn,mx);
    }
    return mn;
}
int main(){
    int t,r,g,b,temp;
    fs(t);
    while(t--){
	mxR=-1;
	mxG=-1;
	mxB=-1;
	fs(r);fs(g);fs(b);fs(M);
	while(r--){
	    fs(temp);
	    mxR=maX(mxR,temp);
	}
	while(g--){
	    fs(temp);
	    mxG=maX(mxG,temp);
	}
	while(b--){
	    fs(temp);
	    mxB=maX(mxB,temp);
	}
	printf("%d\n",process());
    }

}
