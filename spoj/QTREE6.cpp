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


const int N = 1e5 + 10;
const int BLACK = 0, WHITE = 1;
vi g[N];                         
int siz[N];               // depth of node, size of subtree at node
int par[N];                    // par[i][node] = 2^i th parent of node
int pt=0, pos[N], pos_id[N];       // base array, base pointer, position in base array
int c_no=0, c_head[N], c_ind[N];    // chain no, chain head, chain index
int st[2*N+10], qt[2*N+10];         // segment tree, query tree
int lazy[2*N+10][2];
int n_color[N][2];
int col[N];

void dfs(int cur, int p){
    siz[cur] = 1;
    par[cur] = p;
    foreach(v, g[cur]){
	if(*v != p){
	    dfs(*v, cur);
	    siz[cur] += siz[*v];
	}
    }
}

void HLD(int cur){
    
    if(c_head[c_no] == -1)c_head[c_no] = cur;
    c_ind[cur] = c_no;
    pos[cur] = pt++;
    pos_id[pos[cur]] = cur;
    int mxv = -1, mx = -1;
    foreach(v, g[cur]){
	if(*v != par[cur]){
	    if(mx < siz[*v]){
		mx = siz[*v];
		mxv = *v;
	    }
	}
    }
    if(mxv != -1)HLD(mxv);
    foreach(v, g[cur]){
	if(*v != par[cur] && *v != mxv){
	    c_no++;
	    HLD(*v);
	}
    }
}

void make_tree(int cur, int s, int e){
    if(s == e){
	st[cur] = 0;
    }else{
	int m = (s+e)>>1;
	int c1 = cur<<1, c2 = c1 | 1;
	make_tree(c1, s, m);
	make_tree(c2, m+1, e);
	st[cur] = 0;
    }
    lazy[cur][0] = lazy[cur][1] = 0;
}

void lazy_update(int cur, int s, int e){
    if(lazy[cur][0] != 0 || lazy[cur][1] != 0){
	if(s != e){
	    lazy[cur<<1][0] += lazy[cur][0];
	    lazy[(cur<<1) + 1][0] += lazy[cur][0];
	    lazy[cur<<1][1] += lazy[cur][1];
	    lazy[(cur<<1) + 1][1] += lazy[cur][1];
	    lazy[cur][1] = lazy[cur][0] = 0;
	}else{
	    n_color[pos_id[s]][0] += lazy[cur][0];
	    n_color[pos_id[s]][1] += lazy[cur][1];
	    lazy[cur][1] = lazy[cur][0] = 0;
	}
    }
}

void query_color(int cur, int s, int e, int St, int En){
    if(En < s || e < St){
	qt[cur] = 0;
    }else if(St <= s && e <= En){
	qt[cur] = st[cur];
	
    }else{
	int m = (s+e)>>1;
	int c1 = cur<<1, c2 = c1 | 1;
	query_color(c1, s, m, St, En);
	query_color(c2, m+1, e, St, En);
	qt[cur] = qt[c1] + qt[c2];
    }
    return;
}

void change_color(int cur, int s, int e, int x){
    if(x < s || e < x)return;
    if(x == s && s == e){
	col[pos_id[s]] =  !col[pos_id[s]];
	st[cur] = col[pos_id[s]];
    }else{
	int m = (s+e)>>1;
	int c1 = cur<<1, c2 = c1 | 1;
	change_color(c1, s, m, x);
	change_color(c2, m+1, e, x);
	st[cur]  = st[c1] + st[c2];
    }
}

void query_con(int cur, int s, int e, int x, int color){
    lazy_update(cur, s, e);
    if(x < s || e < x)return;
    if(x == s && s == e){
	    qt[1] = n_color[pos_id[x]][color];
    }else{
	    int m = (s+e)>>1;
	    int c1 = cur<<1, c2 = c1 | 1;
	    query_con(c1, s, m, x, color);
	    query_con(c2, m+1, e, x, color);
    }
}

void update_con(int cur, int s, int e, int St, int En, int val, int color){
    if(En < s || e < St)return;
    if(St <= s && e <= En){
	    lazy[cur][color] += val;
    }else{
	    int m = (s + e)>>1;
	    int c1 = cur<<1, c2 = c1 | 1;
	    update_con(c1, s, m, St, En, val, color);
	    update_con(c2, m+1, e, St, En, val, color);
    }
}
// prequisite: v should have same color
int color_parent(int v, int val=0){
    int u = c_head[c_ind[v]], color = col[v];
    query_color(1, 0, pt-1, pos[u], pos[v]);
    if(color*(pos[u] - pos[v] + 1) == qt[1]){
	    if(val != 0)update_con(1, 0, pt-1, pos[u], pos[v], val, color);
	    if(par[u] != -1 && col[par[u]] == color){
	        return color_parent(par[u], val);
	    }else{
            if(par[u] != -1 && val != 0)update_con(1, 0, pt-1, pos[par[u]], pos[par[u]], val, color);
            return pos[u];
        }    
    }else{
	    int l = pos[u];
	    int r = pos[v];
	    int t = pos[v];	
	    while(l < r){
	        int m = (l+r)>>1;
	        query_color(1, 0, pt-1, m, r);
	        if(qt[1] == color*(m - r + 1)){
		        t = m;
		        r = m-1;
	        }else{
		        l = m+1;
	        }
	    }
	    if(val != 0)update_con(1, 0, pt-1, t-1, pos[v], val, color);
	    return t;
    }
}

int main(){
    int n,u,v,t,a;
    fs(n);
    forall(i, 0, n-1){
	    fs(u);fs(v);
	    g[u].pb(v);
	    g[v].pb(u);
    }
    fill(c_head,-1);
    fill(col,0);
    dfs(7, -1);
    HLD(7);
    make_tree(1, 0, pt-1);
    forall(i, 1, n+1){
        n_color[i][0] = siz[i];
        n_color[i][1] = 1; 
    }
    fs(t);
    while(t--){
	    fs(u);fs(v);
	    if(u == 0){
	        a = color_parent(v);
	        query_con(1, 0, pt-1, a, col[v]);
	        printf("%d\n", qt[1]);
	    }else{
	        change_color(1, 0, pt-1, pos[v]);
	        if(par[v] != -1){
                //trace4(par[v], v, col[par[v]], col[v])
		        if(col[par[v]] == col[v]){ // now color is inverted!!
		            query_con(1, 0, pt-1, pos[v], col[v]);
                    //trace2(qt[1],par[v])
		            color_parent(par[v], qt[1]);
                    query_con(1, 0, pt-1, pos[v], !col[v]);
                    update_con(1, 0, pt-1, pos[par[v]], pos[par[v]], -qt[1], !col[v]);
		        }else{
		            query_con(1, 0, pt-1, pos[v], !col[v]);
                    //trace2(-qt[1],par[v])
		            color_parent(par[v], -qt[1]);
                    query_con(1, 0, pt-1, pos[v], col[v]);
                    update_con(1, 0, pt-1, pos[par[v]], pos[par[v]], qt[1], col[v]);
		        }    
	        }
	    }
    }
    return 0;
}
    
