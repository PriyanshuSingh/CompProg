/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * CLRS 22-4
 * Let G = (V, E) be a directed graph in which each vertex u belongs V is labeled with
 * a unique integer L(u) from the set {0, 1, 2, ... |V| -1}. 
 * For each vertex u belong V , let
 * R(u) = {v : u can reach v} be the set of vertices that are reachable from u. Define
 * min(u) to be the vertex in R(u) whose label is minimum, i.e., min(u) is the vertex v
 * such that L(v) = min{L(w) : w in R(u)}. Give an O(V+E)-time algorithm that
 * computes min(u) for all vertices u in V:
 * 
 * // in my solution L(v) = v (its the node itself);
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

typedef vector<int> _vi;
typedef pair<int, int> _pii;
typedef pair<int, bool> _pib;
typedef vector< _pii > _vpii;
typedef vector< _pib > _vpib;


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

int minv[1000];
_vpib graph[1000];

void rev_dfs(int node, int val){
    minv[node] = val;
    foreach(v, graph[node]){
	if(!v->S && minv[v->F] == -1){
	    rev_dfs(v->F,val);
	}
    }
}

int main(){
    int n,m,u,v;
    fs(n);fs(m);
    forall(i, 0, m){
	fs(u);fs(v);
	graph[v].pb(mp(u,false)); // constructing reverse graph!!!
    }
    fill(minv,-1);
    forall(i, 0, n){
	if(minv[i] == -1)rev_dfs(i,i);
    }
    printf("vertex\tmin_vertex\n");
    forall(i, 0, n){
	printf("%d\t%d\n",i,minv[i]);
    }
}

/******************************************
 * Test Case
 * 9 12  
 * 1 6
 * 6 5
 * 0 6
 * 6 7
 * 7 0
 * 0 7
 * 7 2
 * 2 8
 * 8 4
 * 0 8
 * 4 5
 * 3 2
 * vertex  min_vertex
 * 0	   0
 * 1	   0
 * 2	   2
 * 3	   2
 * 4	   4
 * 5	   5
 * 6	   0
 * 7	   0
 * 8	   4
 */
