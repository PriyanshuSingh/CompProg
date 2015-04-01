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


const int N = 10010;
const int LN = 14;
vpiii g[N];                         // graph[i] = <node, cost, edge no.>
int depth[N],siz[N],e_node[N];     // depth of node, size of subtree at node
int par[LN][N];                    // par[i][node] = 2^i th parent of node
int base_arr[N],pt=0,pos[N];       // base array, base pointer, position in base array
int c_no=-1,c_head[N],c_ind[N];    // chain no, chain head, chain index
int st[6*N+10],qt[6*N+10];         // segment tree, query tree


void dfs(int cur, int pr, int _depth=0){
    depth[cur] = _depth;
    siz[cur] = 1;
    par[0][cur] = pr;
    foreach(v, g[cur]){
        if(v->F.F != pr){
            e_node[v->S] = v->F.F;
            dfs(v->F.F,cur,_depth+1);
            siz[cur] += siz[v->F.F];
        }
    }
}

void HLD(int cur, int cost){
    if(c_head[c_no] == -1)c_head[c_no] = cur;
    c_ind[cur] = c_no;
    pos[cur] = pt;
    base_arr[pt++] = cost;
    int mx=-1,mxv=-1,mxc;
    foreach(v, g[cur]){
        if(v->F.F != par[0][cur]){
            if(mx < siz[v->F.F]){
                mx = siz[v->F.F];
                mxv = v->F.F;
                mxc = v->F.S;
            }
        }       
    }
    if(mxv != -1)HLD(mxv, mxc);       
    foreach(v, g[cur]){
        if(v->F.F != par[0][cur] && v->F.F != mxv){
            c_no++;
            HLD(v->F.F, v->F.S);
        }
    }
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    forall(i, 0, LN)if((diff>>i)&1)u = par[i][u];
    if(u == v) return u;
    for(int i=LN-1; i >= 0; i--){
        if(par[i][u] != par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

void make_st(int cur, int s, int e){
    if(s == e-1){
        st[cur] = base_arr[s];
        return;
    }
    int m = (s+e)>>1;
    int c1 = cur<<1, c2 = c1|1;
    make_st(c1, s, m);
    make_st(c2, m, e);
    st[cur] = st[c1] + st[c2]; 
}

void query_st(int cur, int s, int e, int S, int E){
    if(s >= E || e <= S){
        qt[cur] = 0;
        return;
    }
    if(S<=s && E>=e){
        qt[cur] = st[cur];
        return;
    }
    int c1 = cur<<1, c2 = c1|1;
    int m = (s+e)>>1;
    query_st(c1, s, m, S, E);
    query_st(c2, m, e, S, E);
    qt[cur] += qt[c1] + qt[c2];
}
// v ancestor of u
int query_HLD(int u, int v){
    //trace2(u, v)
    int uchain, vchain = c_ind[v];
    uchain = c_ind[u];
    int ans = 0;
    while(1){
        if(u == v)return ans;
        //trace4(u, uchain, v, vchain)
        if(uchain == vchain){
            query_st(1, 0, pt, pos[v] + 1, pos[u] + 1);
            ans += qt[1]; 
            return ans;       
        }
        query_st(1, 0, pt, pos[c_head[uchain]], pos[u] + 1);
        ans += qt[1];
        u = c_head[uchain];
        u = par[0][u];
        uchain = c_ind[u];
    }
}
/*
void update(int cur, int s, int e, int x, int val){
    if(x < s || x >= e)return;
    if(s == x && s == e-1){
        st[cur] = val;
        return;
    }
    int m = (s+e)>>1;
    int c1 = cur<<1, c2 = c1|1;
    update(c1, s, m, x, val);
    update(c2, m, e, x, val);
    st[cur] = (st[c1] > st[c2]) ? st[c1] : st[c2];
}
*/
void query(int u, int v){
    int lca = LCA(u,v);
    int ans = query_HLD(u, lca);
    int temp = query_HLD(v, lca);

    if(temp > ans)ans = temp;
    printf("%d\n",ans);
}
/*
void change(int i, int val){
    int u = e_node[i];
    update(1, 0, pt, pos[u], val);
}
*/
int find_k(int s, int e, int k){

    int lca = LCA(s, e);
    int l = depth[s] - depth[lca] + 1;
    //trace2(l, k)
    if(l < k){ k = k - l + 1; swap(s,e);}
    k = k-1;
    //trace1(k)
    if(k == 0) return s;
    forall(i, 0, LN){
        if((k>>i)&1)s = par[i][s];
    }
    return s;
}
int main(){
    int t, n,u,v,c;
    fs(t);
    while(t--){
        fs(n);
        pt = 0;
        forall(i, 0, n+1){
            g[i].clear();
            c_head[i] = -1;
            forall(j, 0, LN)par[j][i] = -1;
        }
        forall(i, 1, n){
            fs(u);fs(v);fs(c);
            g[u].pb(mp(mp(v,c),i));
            g[v].pb(mp(mp(u,c),i));
        }
        dfs(1,-1);
        c_no = 0;
        HLD(1, -1);
        make_st(1, 0, pt);
        forall(i, 1, LN){
            forall(j, 0, n+1)if(par[i-1][j] != -1)par[i][j] = par[i-1][par[i-1][j]];           
        }
        while (1) {
            char str[50];
            int u,v;
            ss(str);
            if(str[1] == 'I'){
                fs(u);fs(v);
                query(u, v);
            }else if(str[0] == 'K'){
                fs(u);fs(v);fs(c);
                printf("%d\n",find_k(u, v, c));
            }else {
                break;
            }
        }
    }
    return 0;
}