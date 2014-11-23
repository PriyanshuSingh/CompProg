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


void fs(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


int arr[1000];
bool vis[1000];

inline int getsq(ll n){
    int sq = 0;
    while(n != 0){
	int temp = n%10;
	sq += temp*temp;
	n/=10;
    }
    return sq;
}

inline void precal(){
    stack<int>stk;
    int g;
    fill(arr,-1);
    arr[1] = 0;
    arr[0] = -1;
    fill(vis,0);
    vis[0] = true;
    vis[1] = true;
    forall(i,2,1000){
	if(!vis[i]){
	    stk.push(i);
	    vis[i] = true;
	    g = getsq(i);
	    while(!vis[g]){
		stk.push(g);
		vis[g] = true;
		g = getsq(g);
	    }
	    if(arr[g] != -1){
		while(!stk.empty()){
		    arr[stk.top()] =  arr[g]+1;
		    g = stk.top();stk.pop();
		}
	    }
	    else{
		while(!stk.empty()){
		    arr[stk.top()] = -1;stk.pop();
		}
	    }
	}
    }
}


int main(){
    precal();
    ll t;
    ll n;
    fs(t);
    while(t--){
	fs(n);
	if(n<1000)
	    printf("%d\n",arr[n]);
	else{
	    if(arr[getsq(n)] != -1)printf("%d\n",arr[getsq(n)]+1);
	    else
		printf("-1\n");
	}

    }
    return 0;
}
