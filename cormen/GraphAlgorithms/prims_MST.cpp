/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Prim's algorithm 
 * computes minimum spanning tree in O(E.logE) time
 *
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

class Cmp{
public:
    bool operator() (const piii& a, const piii& b){
	return a.S > b.S;
    }
}obj;

const int MAX = 1000;
priority_queue<piii, vpiii, Cmp> Q(obj);
int p[MAX];
bool vis[MAX];
vpii graph[MAX];

int prims_mst(){
    int w=0;
    fill(vis,0);
    fill(p,-1);
    Q.push(mp(mp(0,0),0));
    while(!Q.empty()){
	piii top = Q.top(); // element repr -> pair<pair<vertex, parent>, weight>
	Q.pop();
	if(!vis[top.F.F]){
	    w += top.S;
	    vis[top.F.F] = true;
	    p[top.F.F] = top.F.S; // tree stored in array form ( p[i] = parent of i)
	    foreach(v, graph[top.F.F]){
		if(!vis[v->F]){
		    Q.push(mp(mp(v->F,top.F.F),v->S));
		}
	    }
	}
    }
    return w;
}

int main(){
    int n,m,u,v,w;
    fs(n);fs(m);
    forall(i, 0, m){
	fs(u);fs(v);fs(w);
	graph[u].pb(mp(v,w));
	graph[v].pb(mp(u,w));
    }
    printf("%d\n",prims_mst());
}
/**********************************************
 * Test Case
 *
 * 5 7
 * 0 1 2
 * 1 2 3
 * 2 4 7
 * 4 3 9
 * 3 0 6
 * 1 3 8
 * 1 4 5
 * 
 * 
 * total weight of mst = 16
 */
