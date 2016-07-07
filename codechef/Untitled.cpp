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

//#ifdef __MINGW32__
//#define printf __mingw_printf   /* codeforces long double problem with printf */
//#endif

//#if __cplusplus > 199711L
//#define typeof decltype
//#endif

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define slf(n)                      scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define pi(a)                       printf("%d", a)
#define pl(a)                       printf("%lld", a)
#define pn                          printf("\n")

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( __typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
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
#define checkbit(n,b)                ( ((n) >> (b)) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define sqr(a)                      (a) * (a)


#define DEBUG

// debugging

#ifdef DEBUG
#define METHOD_NAME                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);
#define trace1(x)                    cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << endl;
#define trace2(x, y)                 cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              cerr<<"("<< __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
// can print whole array (arr should not contain any pointer airthmetics)
#define traceArr(arr,size)           do{ vi __ARRAY_NAME__##arr((arr), (arr)+(size)); trace1(__ARRAY_NAME__##arr);}while(0)
#else
#define METHOD_NAME
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define traceArr(arr,size)
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

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";s<<t[sz(t)-1]<<"]";return s; }

const int MOD = 1e9+7;

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}

template<typename T>
inline T pow_mod(T a, T b) {
    T res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
struct node{
    int max_alive,number_alive,lazy_update_val;
};
const int MAXN = 1e5+10;
int LOGN = 18;
int arr[MAXN],chain_head[MAXN],chain_ind[MAXN],pos[MAXN];
int siz[MAXN],dpth[MAXN],par[MAXN][18];
int C[MAXN];
int chainno=0,idx=0;
node st[MAXN<<2];
int min_value;
vi tree[MAXN];

void build(int cur, int s, int e){
    if(s==e){
        st[cur].max_alive = (arr[s] >= min_value)?-INF:arr[s];
        st[cur].number_alive = (arr[s] >= min_value)?0:1;
        st[cur].lazy_update_val = 0;
    }else{
        int mid=(s+e)>>1,c1=cur<<1,c2=c1|1;
        build(c1, s, mid);build(c2, mid+1, e);
        st[cur].max_alive = max(st[c1].max_alive, st[c2].max_alive);
        st[cur].number_alive = st[c1].number_alive+st[c2].number_alive;
        st[cur].lazy_update_val=0;
    }
}
void lazyUpdate(int cur, int s, int e){
    if(s==e)st[cur].lazy_update_val=0;
    else{
        int mid=(s+e)>>1, c1 = cur<<1, c2 = c1|1;
        if(st[c1].max_alive != -INF){st[c1].max_alive+=st[cur].lazy_update_val;st[c1].lazy_update_val += st[cur].lazy_update_val;}
        if(st[c2].max_alive != -INF){st[c2].max_alive+=st[cur].lazy_update_val;st[c2].lazy_update_val += st[cur].lazy_update_val;}
    }
    st[cur].lazy_update_val=0;
}

void update(int cur, int s, int e, int St, int En, int val){
    if(st[cur].lazy_update_val > 0)lazyUpdate(cur, s, e);
    if(En < s || e < St)return;
    else if(St <= s && e <= En){
        if(st[cur].max_alive != -INF){st[cur].max_alive += val;st[cur].lazy_update_val += val;}
    }else{
        int mid=(s+e)>>1,c1=cur<<1,c2=c1|1;
        update(c1, s, mid, St, En, val);update(c2, mid+1, e, St, En, val);
        st[cur].max_alive = maX(st[c1].max_alive, st[c2].max_alive) + st[cur].lazy_update_val;
        st[cur].number_alive = st[c1].number_alive + st[c2].number_alive;
    }
}




void propogate(int cur, int s, int e){
    if(st[cur].lazy_update_val > 0)lazyUpdate(cur, s, e);
    if(st[cur].max_alive >= min_value){
        if(s == e){
            st[cur].max_alive = -INF;
            st[cur].number_alive=0;
        }else{
            int mid = (s+e)>>1, c1 = cur<<1, c2 = c1|1;
            propogate(c1, s, mid);propogate(c2, mid+1, e);
            st[cur].max_alive = maX(st[c1].max_alive, st[c2].max_alive);
            assert(st[cur].lazy_update_val == 0);
            st[cur].number_alive = st[c1].number_alive + st[c2].number_alive;
        }
    }
}

int query(int cur, int s, int e, int St, int En){
    if(st[cur].lazy_update_val > 0)lazyUpdate(cur, s, e);
//    trace5(cur, s, e, St, En);
    if(En < s || e < St)return 0;
    else if(St <= s && e <= En){
        if(st[cur].max_alive == -INF)return e - s + 1;
        if(st[cur].max_alive >= min_value)propogate(cur, s, e);
        return e - s + 1 - st[cur].number_alive;
    }else{
        int mid=(s+e)>>1,c1 = cur<<1, c2 = c1|1;
        int ans = query(c1, s, mid, St, En) + query(c2, mid+1, e, St, En);
        st[cur].max_alive = maX(st[c1].max_alive, st[c2].max_alive);
        assert(st[cur].lazy_update_val == 0);
        st[cur].number_alive = st[c1].number_alive + st[c2].number_alive;
        return ans;
    }
//    trace5(cur, s, e, St, En);assert(false);
}

int dfs(int cur, int _par, int _dpth){
    siz[cur] = 1;
    dpth[cur] = _dpth;
    par[cur][0] = _par;
    foreach(v, tree[cur])if(*v != _par)siz[cur]+=dfs(*v,cur,_dpth+1);
    return siz[cur];
}
//bool vis[MAXN];
//void dfs(int cur, int _par, int _dpth, int N){
////    trace3(cur, _par, _dpth);
//    forall(i, 0, N+1)vis[i]=false;
//    stack<piii > stck;
//    stck.push({{cur, _par}, _dpth});
//    while(!stck.empty()){
//        cur = stck.top().F.F;
//        _par = stck.top().F.S;
//        _dpth = stck.top().S;
////        trace4(cur, _par, _dpth, vis[cur]);
//        siz[cur] = 1;
//        dpth[cur] = _dpth;
//        par[cur][0] = _par;
//        if(vis[cur]){
//            foreach(v, tree[cur])if(*v != _par)siz[cur] += siz[*v];
//            stck.pop();
//        }else{
//            foreach(v, tree[cur])if(*v != _par)stck.push({{*v, cur}, _dpth+1});
//            vis[cur]=true;
//        }
//    }
//
////    foreach(v, tree[cur]){
////        if(*v != _par){
////            siz[cur] += dfs(*v, cur, _dpth+1);
////        }
////    }
////    return siz[cur];
//}

void hld(int cur){
//    trace2(cur, par[cur][0]);
    if(chain_head[chainno] == -1)chain_head[chainno] = cur;
    chain_ind[cur] = chainno;
    pos[cur] = idx;
    arr[idx++] = C[cur];
    int mxChild = -1,mxSize=-1;
    foreach(v, tree[cur])if(mxSize < siz[*v] && *v != par[cur][0]){mxSize=siz[*v];mxChild=*v;}
    if(mxChild != -1)hld(mxChild);
    foreach(v, tree[cur]){
        if(*v != par[cur][0] && *v != mxChild){
            chainno++;hld(*v);
        }
    }
}

int lca(int u, int v){
    if(dpth[u] < dpth[v])swap(u,v);
    int diff = dpth[u] - dpth[v];forall(i, 0, LOGN)if(checkbit(diff, i))u = par[u][i];
    if(u == v)return u;
    for(int i=LOGN-1; i>=0; i--){
//        trace2(u, v);
        if(par[u][i] != par[v][i]){u = par[u][i];v=par[v][i];}
    }
    return par[u][0];
}
void init_par(int N){
//    LOGN = log2(N)+1;
    forall(i, 1, LOGN)forall(j, 1, N+1)par[j][i] = par[par[j][i-1]][i-1];
}

void update_hld(int p, int u, bool update_par, int w){
    while(chain_ind[p] != chain_ind[u]){
        update(1, 0, idx-1, pos[chain_head[chain_ind[u]]], pos[u], w);
        u = par[chain_head[chain_ind[u]]][0];
    }
    if(update_par){
        update(1, 0, idx-1, pos[p], pos[u], w);
    }else{
        if(p != u)update(1, 0, idx-1, pos[p]+1, pos[u], w);
    }
}

int query_hld(int p, int u, bool query_par){
    int ans = 0;
    while(chain_ind[p] != chain_ind[u]){
        ans += query(1, 0, idx-1, pos[chain_head[chain_ind[u]]], pos[u]);
        u = par[chain_head[chain_ind[u]]][0];
    }
    if(query_par){
        ans += query(1, 0, idx-1, pos[p], pos[u]);
    }else if(p != u) ans+= query(1, 0, idx-1, pos[p]+1, pos[u]);
//    trace4(p, u, query_par,ans);
    return ans;
}

void solve(int q){
    int t,u,v,w;
    while(q--){
        s(t);if(t == 1){
            s(u);s(v);s(w);
            int p = lca(u, v);
//            trace4(u, v, p, w);
            update_hld(p, u, true, w);update_hld(p, v, false, w);
        }else{
            s(u);s(v);
            int p = lca(u, v);
//            trace3(u, v, p);
            pi(query_hld(p, u, true)+query_hld(p, v, false));pn;
        }
    }
}
int main(){
//    ios::sync_with_stdio(false);
//    const rlim_t stack_size = 512 * 1024 * 1024;
//    struct rlimit inf;
//    getrlimit(RLIMIT_STACK, &inf);inf.rlim_cur=stack_size;
//    int res = setrlimit(RLIMIT_STACK, &inf);
    fill(chain_head,-1);
    int t;s(t);while(t--){
        forall(i, 0, chainno+1)chain_head[i]=-1;chainno=0;idx=0;
        int n,q,A,B;s(n);s(q);s(A);s(B);forall(i, 1, n+1){s(C[i]);tree[i].clear();}
        forall(i, 0, n-1){int u,v;s(u);s(v);tree[u].pb(v);tree[v].pb(u);}
        dfs(1, -1, 0);
        init_par(n);
        hld(1);
        if(A != 0){
            if(B < 0 && B % A != 0)min_value = -B/A + 1;
            else min_value = -B/A;
        }else min_value = -INF;
        build(1, 0, idx-1);
        solve(q);
    }
    return 0;
}
