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

const int N = 100100;
vi g[N];                           // graph[i] = <node, cost, edge no.>
int depth[N],siz[N],e_node[N];     // depth of node, size of subtree at node
int par[N];                        // par[i][node] = 2^i th parent of node
int pt=0,pos[N],pos_id[N];         // base array, base pointer, position in base array
int c_no=0,c_head[N],c_ind[N];     // chain no, chain head, chain index
int st[6*N+10],qt[6*N+10];         // segment tree, query tree

void dfs(int cur, int pr, int _depth=0){
    depth[cur] = _depth;
    siz[cur] = 1;
    par[cur] = pr;
    foreach(v, g[cur]){
        if(*v != pr){
            dfs(*v, cur, _depth+1);
            siz[cur] += siz[*v];
        }
    }
}

void HLD(int cur){
    if(c_head[c_no] == -1){
        c_head[c_no] = cur;
    }
    c_ind[cur] = c_no;
    pos[cur] = pt++;
    pos_id[pt-1] = cur;
    int mxv = -1;
    int mx = -1;
    foreach(v, g[cur]){
        if(*v != par[cur] && siz[*v] > mx){
            mx = siz[*v];
            mxv = *v;
        }
    }
    if(mxv != -1){
        HLD(mxv);
    }
    foreach(v, g[cur]){
        if(*v != par[cur] && *v != mxv){
            c_no++;
            HLD(*v);
        }
    }
}

void update(int cur, int s, int e, int x){
    if(s == x && e == x){
        if(st[cur] == INT_MAX){
            st[cur] = s;
        }else{
            st[cur] = INT_MAX;
        }
    }else if(s > x || e < x){
        return;
    }else{
        int m = (s+e)>>1;
        int c1 = cur<<1;
        int c2 = c1 | 1;
        update(c1, s, m, x);
        update(c2, m+1, e, x);
        st[cur] = (st[c1] < st[c2])? st[c1] : st[c2];
    }
}

void query_st(int cur, int s, int e, int S, int E){
    //trace4(s, e, S, E)
    if(s > E || e < S){
        qt[cur] = INT_MAX;
        //trace1("yes")
        return;
    }
    else if(S <= s && e <= E){
        qt[cur] = st[cur];
    }
    else{
        int m = (s+e)>>1;
        int c1 = cur<<1;
        int c2 = c1 | 1;
        query_st(c1, s, m, S, E);
        query_st(c2, m+1, e, S, E);
        qt[cur] = (qt[c1] < qt[c2])? qt[c1] : qt[c2];
    }
}

int query_HLD(int v){
    //trace1(v)
    int uchain = 0,vchain;
    int u = 1;
    int ans = INT_MAX;
    vchain = c_ind[v];
    while(1){
        //trace1(v);
        //trace2(u, v)
        if(u == v)return ans;
        else if(uchain == vchain){
            query_st(1, 0, pt-1, pos[u], pos[v]);
            if(qt[1] != INT_MAX){
                ans = qt[1];
            }
            return ans;
        }else{
            query_st(1, 0, pt-1, pos[c_head[vchain]], pos[v]);
            if(qt[1] != INT_MAX){
                ans = qt[1];
            }
            //trace2(par[c_head[vchain]], c_head[vchain])
            v = par[c_head[vchain]];
            vchain = c_ind[v];
        }
    }    
}

int main(){
    int n, q, u, v,ans;
    bool isone = false;
    fs(n);fs(q);
    forall(i, 0, 6*N + 10){
        st[i] = INT_MAX;
    }
    forall(i, 1, n){
        fs(u);fs(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    fill(c_head, -1);
    dfs(1, -1);
    HLD(1);
    forall(i, 0, q){
        fs(u);fs(v);
        if(u == 0){
            if(v == 1){
                isone = !isone;
                continue;
            }
            update(1, 0, pt-1, pos[v]);
        }else if(u == 1){
            if(isone)printf("1\n");
            else if(v == 1){
                printf("-1\n");
            }else{
                ans = query_HLD(v);
                printf("%d\n", (ans != INT_MAX)? pos_id[ans] : -1);
            }
        }
    }
    return 0;
}