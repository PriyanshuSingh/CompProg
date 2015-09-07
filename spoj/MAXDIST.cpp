/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
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
#include <bitset>

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

//dirextion
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

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
const int MAXN = 10010;
const int LOGN = 15;
int depth[MAXN];
int par[MAXN][LOGN];
int N;
vi g[MAXN];
vi d;
int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    forall(i, 0, LOGN)if((diff>>i)&1)u = par[i][u];
    if(u == v) return u;
    for(int i=LOGN-1; i >= 0; i--){
        if(par[i][u] != par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}


int BFS(int u){
    queue<int> Q;
    int mxi=-1,mx=-1;
    forall(i, 0, N+1)depth[i]=INF;
    depth[u] = 0;
    par[0][u] = -1;
    Q.push(u);
    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        foreach(v, g[t]){
            if(depth[*v] == INF){
                depth[*v] = depth[t] + 1;
                par[0][*v] = t;
                Q.push(*v);
                if(mx < depth[*v]){
                    mxi = *v;
                    mx = depth[*v];
                }
            }
        }
    }
    return mxi;
}


int main(){
    int T,maxd;
    s(T);
    forall(i, 0, MAXN)g[i].clear();
    while(T--){
        fill(par,-1);
        d.clear();
        s(N);
        forall(i, 0, N-1){
            int a,b;
            s(a);s(b);
            g[a].pb(b);
            g[b].pb(a);
        }
        maxd = BFS(BFS(1));
        //trace1(maxd)
        forall(i, 1, LOGN){
            forall(j, 0, N+1)if(par[i-1][j] != -1)par[i][j] = par[i-1][par[i-1][j]];           
        }
        forall(i, 1, N+1){
            if(depth[i] == depth[maxd])d.pb(i);
        }
        int lca = d[0];
        //trace2(lca,d.size())
        //trace1(depth[maxd])
        //trace1(maxd);
        forall(i, 1, d.size()){
            lca = LCA(lca, d[i]);
            //trace1(d[i])
        }
        
        int lca2;
        fill(par,-1);
        d.clear();
        maxd = BFS(maxd);
        //trace2(maxd,depth[maxd])
        forall(i, 1, LOGN){
            forall(j, 0, N+1)if(par[i-1][j] != -1)par[i][j] = par[i-1][par[i-1][j]];           
        }
        forall(i, 1, N+1){
            if(depth[i] == depth[maxd])d.pb(i);
            //trace1(i)
        }
        lca2 = d[0];
        //trace2(lca2,d.size());
        forall(i, 1, d.size()){
            lca2 = LCA(lca2, d[i]);
            //trace1(d[i])
        }
        if(depth[lca] > depth[lca2])swap(lca, lca2);
        //trace3(depth[lca2],lca2,lca);
        if(depth[lca2] - depth[lca] > 1)printf("YES\n");
        else printf("NO\n");
        forall(i, 0, N+1)g[i].clear();
    }
}
