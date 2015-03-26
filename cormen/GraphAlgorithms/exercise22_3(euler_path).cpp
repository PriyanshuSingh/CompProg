/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * CLRS 22-3
 * Fleury's Algorithm to compute euler path / circuit
 * in an undirected graph
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
typedef vector< pii > vpii;

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

bool bitmap[1000][1000];
vi graph[1000];
stack<int> path;
int V;

void euler_path(int node){
    foreach(v, graph[node]){
	if(bitmap[node][*v]){
	    bitmap[node][*v] = false;
	    bitmap[*v][node] = false;
	    euler_path(*v);
	}
    }
    path.push(node);
}

int main(){
    int n,m,u,v;
    int s;
    fs(n);fs(m);
    // assuming graph has even deg or have only two odd deg vertices
    forall(i, 0, m){
	fs(u);fs(v);
	graph[u].pb(v);
	graph[v].pb(u);
    }
    s = 0;
    forall(i, 0, n){
	if(graph[i].size() % 2 != 0)s = i;
    }
    fill(bitmap,-1);// memset value is unsigned (1 byte), so -1 == 255 (all bits 1 in binary)*** 2's complement
                    // therefore here -1 is setting whole bitmap to true (1 represent true).
    euler_path(s);
    printf("EULER PATH\\CIRCUIT\n");
    while(!path.empty()){
	printf("%d ",path.top());
	path.pop();
    }
    printf("\n");
    return 0;
}
    
/*********************
 * Test case
 * 5 8
 * 1 0
 * 0 2
 * 2 1
 * 0 3
 * 3 4
 * 3 2
 * 3 1
 * 2 4
 *
 * EULER PATH\CIRCUIT
 * 1 0 2 1 3 4 2 3 0 
 *
 */
