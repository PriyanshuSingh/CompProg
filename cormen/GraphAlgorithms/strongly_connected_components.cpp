/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Strongly Connected Components (SCCs) of a graph
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
#define gc  getchar_unlocked

typedef pair<int, int> PII;
typedef vector<PII > VPII;

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

bool on_f_time(PII a, PII b){
    return a.S < b.S;
}

vector<pair<int, bool> > graph[1000];
bool vis[1000];
vector<int> scc[1000];
stack<int> Stack;

void dfs_stack(int node, bool out){
    vis[node] = true;
    foreach(v, graph[node]){
        if(!vis[v->F] && v->S == out){
            dfs_stack(v->F,out);
        }
    }
    Stack.push(node); // sorting in descending order;
    // node will get pushed after every vertex it can reach.
}

void dfs_scc(int node, bool out, vector<int> &scc){
    vis[node] = true;
    scc.pb(node);
    foreach(v, graph[node]){
        if(!vis[v->F] && v->S == out){
            dfs_scc(v->F,out,scc);
        }
    }
}

int get_scc(int n){
    fill(vis,0);
    forall(i, 0, n){
        if(!vis[i])dfs_stack(i, true);
    }
    fill(vis,0);
    int i = 0;
    while(!Stack.empty()) {
        int top = Stack.top();
        Stack.pop();
        if(!vis[top]){
            //printf("%d- ",top);
            dfs_scc(top, false, scc[i]);
            i++;
        }
    }
    return i;
}

int main(){
    int n,m,u,v;
    fs(n);fs(m);
    while (m--) {
        fs(u);fs(v);
        graph[u].pb(mp(v,true));
        graph[v].pb(mp(u,false));
    }
    int no_of_scc = get_scc(n);
    printf("no. of component: %d\n",no_of_scc);
    forall(i, 0, no_of_scc){
        foreach(v, scc[i]){
            printf("%d ",*v);
        }
        printf("\n");
    }
}
/******************
 * test case
 *
 * 5 5
 * 1 0
 * 0 2
 * 2 1
 * 0 3
 * 3 4
 * 
 * no. of component: 3
 * 0 1 2 
 * 3 
 * 4 
 */
