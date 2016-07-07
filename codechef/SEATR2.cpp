/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 */

#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
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

// debugging

#ifdef __PRI__
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
template<typename T> ostream& operator<<(ostream &s,vector<T> t){if(t.size()==0){s<<"[]";return s;}s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";s<<t[sz(t)-1]<<"]";return s; }

// C++ 11
template<typename T, typename TT> ostream& operator<<(ostream &s, map<T, TT> m){if(m.size()==0){s<<"{}";return s;}s<<"{";auto nxt = m.begin(), it = nxt++;for(; nxt != m.end(); it++,nxt++)s<<*it<<", "; s<<*it<<"}"; return s;}
template<typename T> ostream& operator<<(ostream &s, set<T> m){if(m.size()==0){s<<"()";return s;}s<<"(";auto nxt = m.begin(), it = nxt++;for(; nxt != m.end(); it++,nxt++)s<<*it<<", "; s<<*it<<")"; return s;}
// C++ 11

const int MOD = 1e9+7;

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b)a %= b, swap(a, b);
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
const int MAXN = 510;
const int MAXM = 2e4+10;
int memo[MAXN][MAXM];
vi lv[MAXN];
vi tree[MAXN];
vi gr[MAXN];

void dfs(int cur, int par, int lvl){
    lv[lvl].pb(cur);
    int v = 0;
    for(auto &x: gr[cur]){
        if(x != par)v++, tree[cur].pb(x), dfs(x, cur, lvl+1);
    }
}
void genCases(int &n, int &m){
    n =  500; m = 2e4;
    forall(i, 1, n){
        gr[i].pb(i+1);
        gr[i+1].pb(i);
    }
}
ll f[MAXM];
int main(){
    int t; cin>>t; while(t--){
   
        forall(i, 0, MAXN)tree[i].clear(), lv[i].clear(), gr[i].clear();
        int n,m;
        #ifndef __PRI__
        cin>>n>>m;
        forall(i, 0, n-1){
            int x,y;cin>>x>>y;
            gr[x].pb(y); gr[y].pb(x);
        }
        #else
        genCases(n, m);
        #endif
        
        dfs(1, -1, 0);
        int cc = 0;
        for(int l=500; l>=0; l--){
            for(auto x: lv[l]){
                if(!tree[x].empty()){
                    forall(j, 1, m+1){
                        f[j] = 1;
                        for(auto c: tree[x]){
                            cc++;
                            f[j] = f[j] * memo[c][j];
                            if(f[j] >= MOD)f[j] %= MOD;
                        }    
                    }
                    forall(j, 1, m+1){
                        int k=j;
                        memo[x][j] = 0;
                        while(k <= m){
                            cc++;
                            memo[x][j] += f[k];
                            if(memo[x][j] >= MOD)memo[x][j] -= MOD;
                            k += j;
                        }
                        if(x == 1 && j == 1)goto ans;
                    }
                }else{
                    forall(j, 1, m+1){
                        cc++;
                        memo[x][j] = m/j;
                    }
                }
            }
        }
        ans:
        trace1(cc);
        cout<<memo[1][1]<<endl;

    }
    #ifdef __PRI__
    cerr<<1.0 * clock() / CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}