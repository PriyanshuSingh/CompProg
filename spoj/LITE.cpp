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

int ST[1<<18];
bool lazy[1<<18];

inline void update(int node,int start,int end,int L,int R){
    if(lazy[node]){
	ST[node] = end - start + 1 - ST[node];
	if(start != end){
	    lazy[node*2] = !lazy[node*2];
	    lazy[node*2+1] = !lazy[node*2+1];
	}
	lazy[node] = false;
    }
    if(L > end || R < start)return;
    if(start >= L && end <= R){
	ST[node] = end-start+1 - ST[node];
	if(start != end){
	    lazy[node*2] = !lazy[node*2];
	    lazy[node*2+1] = !lazy[node*2 + 1];
	}
	return ;
    }
    update(node*2,start,(start+end)/2,L,R);
    update(node*2+1,(start+end)/2 +1,end,L,R);
    ST[node] = ST[node*2] + ST[node*2+1];
}

inline int query(int node,int start,int end,int L,int R){
    if(L>end || R <start)return 0;
    if(lazy[node]){
	ST[node] = end-start + 1 - ST[node];
	if(start!=end){
	    lazy[node*2] = !lazy[node*2];
	    lazy[node*2 + 1] = !lazy[node*2 +1];
	}
	lazy[node] = false;
    }
    if(L<=start && R>=end){
	return ST[node];
    }
    return query(node*2,start,(start+end)/2,L,R)+query(node*2+1,(start+end)/2+1,end,L,R);
}

int main(){
    int n,m;
    int q,l,r;
    s(n);s(m);
    fill(ST,0);
    fill(lazy,0);
    while(m--){
	s(q);s(l);s(r);
	if(q==0){
	    update(1,0,n-1,l,r);
	}
	else{
	    printf("%d\n",query(1,0,n-1,l,r));
	}
    }
    return 0;
}
