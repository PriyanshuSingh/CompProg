/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * CLRS 22-2
 * part(c) part(d) part(f) part(h)
 * algorithm computes cut vertex, bridges, biconnected component
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

const int MAXN = 1010;


vi graph[MAXN];
stack< pii > stk;
int low[MAXN]; // lowpoint (node with min discover time that can be reached)
int dis[MAXN]; // discover time
int p[MAXN]; // parent
bool vis[MAXN];
vpii bcc[MAXN]; // max biconnected component can be |V|
vi sep_vertex;

void make_bcc(pii a, vpii &b){
    pii temp;
    do{
        temp = stk.top();
        stk.pop();
        b.pb(temp);
    }while (temp.F != a.F || temp.S != a.S);
}

int dfs(int node){
    static int t = 0;
    static int num_bcc=0;
    int child = 0;
    vis[node] = true;
    dis[node] = ++t;
    low[node] = dis[node];
    foreach(v, graph[node]){
        if(!vis[*v]){
            stk.push(mp(node,*v));
            ++child;
            p[*v] = node;
            dfs(*v);
            low[node] = miN(low[node], low[*v]);
            if(low[*v] >= dis[node]){
                make_bcc(mp(node,*v), bcc[num_bcc]);
                num_bcc++;
                if((p[node] == -1 && child > 1) || p[node] != -1)sep_vertex.pb(node);
                // root vertex can be cut vertex only when it has atleast two children
                // in DFS(G) (induced tree by DFS on G) 
            }
        }else if(*v != p[node] && dis[*v] < dis[node]){ // dis[*v] < dis[node] block forward edges two get pushed in stack
                                                        // *v != p[node] prevent parent to get pushed
            stk.push(mp(node,*v));
            low[node] = miN(low[node], dis[*v]); // back edge for sure
        }
    }
    return num_bcc;
}



int main(){
    int n,m,u,v,num_of_bcc;
    fs(n);fs(m);
    forall(i, 0, m){
        // graph is undirected
        fs(u);fs(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fill(p,-1);
    fill(vis,0);
    forall(i, 0, n){
        if(!vis[i])num_of_bcc=dfs(i);
    } // if only one edge in component then its a bridge if it has atleast one cut vertex
      // see example: 10--11 is not a bridge as not even one vertex is cut vertex
    printf("biconnected component\n");
    forall(i, 0, num_of_bcc){
        foreach(v, bcc[i]){
            printf("%d--%d ",v->F,v->S);
        }
        printf("\n");
    }
    printf("\nCut vertex\n");
    foreach(v, sep_vertex){
        printf("%d ",*v);
    }
}
/*********************
 * Test case
 * 12 14
 * 0 1
 * 1 2
 * 1 3
 * 2 3
 * 2 4
 * 3 4
 * 1 5
 * 0 6
 * 5 6
 * 5 7
 * 5 8
 * 7 8
 * 8 9
 * 10 11
 * 
 * biconnected component
 * 4--2 3--4 3--1 2--3 1--2 
 * 8--9 
 * 8--5 7--8 5--7 
 * 6--0 5--6 1--5 0--1 
 * 10--11 
 *
 * Cut vertex
 * 1 8 5 
 */
