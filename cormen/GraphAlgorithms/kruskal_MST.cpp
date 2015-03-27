/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Kruskal's algorithm 
 * computes minimum spanning tree in O(E.logE + E*alpha) time
 * where alpha is time taken in union find which is aprox O(1)(path compression)
 * so O(E.logE + E);
 */


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
#define sf(n)                       scanf("%f",&n)
#define slf(n)                      scanf("%lf",&n)
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
#define F                           first
#define S                           second

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define DEBUG

// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif


// datatypes
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair< pii, int> piii;
typedef vector< piii > vpiii;
typedef pair<int, bool> pib;
typedef vector< pii > vpii;
typedef vector< pib > vpib;


#define gc  getchar_unlocked

inline void fs(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

// union-find implemented with path compression
namespace uf{
    const int _MAX = 1010;
    int _p[_MAX], _sz[_MAX];
    
    void refresh(int n){
	if(n > _MAX){
	    printf("ERROR: size > %d\n",_MAX);
	    exit(1);
	}
	forall(i, 0, n){
	    _p[i] = i;
	    _sz[i] = 1;
	}
    }
    
    int _root(int i){
	while(i != _p[i]){
	    _p[i] = _p[_p[i]]; // path compression
 	    i = _p[i];
	}
	return i;
    }
    
    bool find(int i, int j){
	return _root(i) == _root(j);
    }
    
    void unite(int i, int j){
	int pi = _root(i);
	int pj = _root(j);
	
	if(_sz[pi] > _sz[pj]){
	    _p[pi] = pj;
	    _sz[pj] += _sz[pi];
	}else{
	    _p[pj] = pi;
	    _sz[pi] += _sz[pj];
	}
    }
}

piii edge[200000];

bool cmp(piii a, piii b){
    return a.S < b.S;
}

int kruskal_mst(int n,int m){
    int w=0;
    uf::refresh(n); // set n distinct sets {0 .. n-1}
    sort(edge, edge+m, cmp);
    forall(i, 0, m){
	if(!uf::find(edge[i].F.F, edge[i].F.S)){
	    // save edges if whole mst graph is needed
	    uf::unite(edge[i].F.F, edge[i].F.S);
	    w += edge[i].S;
	}
    }
    return w;
}


int main(){
    int n,m,u,v,w;
    fs(n);fs(m);
    forall(i, 0, m){
	fs(u);fs(v);fs(w);
	edge[i] = mp(mp(u,v),w);
    }
    printf("%d\n",kruskal_mst(n,m));
    return 0;
}

	    
