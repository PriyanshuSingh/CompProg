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
const int MAXN = 1e5 + 10;

struct Node{
    ll x,y;
    Node& operator+= (const Node& other){x+=other.x;y+=other.y;return *this;}
};
#define _start sdfjglkdfgkdfg
#define _end lskdfjdslkjglk

Node st[MAXN<<2];
ll _start[MAXN],_end[MAXN],dpth[MAXN];
const int OFFSET = MAXN;
ll fib[MAXN<<1];
vi tree[MAXN];

template <typename T>
inline T modd(T a){if(a>=MOD)return a-MOD; else if(a<0)return a+MOD; else return a;}

inline void modNode(Node &a){a.x = modd(a.x);a.y = modd(a.y);}
void precompute(){fib[OFFSET] = 0; fib[OFFSET + 1] = 1;forall(i,OFFSET+2,MAXN<<1)fib[i] = modd(fib[i-1]+fib[i-2]);for(int i=OFFSET-1; i>=0; i--)fib[i] = modd(fib[i+2]-fib[i+1]);}

void update(int cur, int s, int e, int St, int En, int x, int depth){
    if(En < s || e < St)return;
    else if(St <= s && e <= En){st[cur] += {fib[OFFSET + x - depth], fib[OFFSET + x - depth - 1]};modNode(st[cur]);}
    else {
        int mid = (s + e)>>1,c1 = cur<<1, c2 = c1 | 1;
        update(c1, s, mid, St, En, x, depth);update(c2, mid+1, e, St, En, x, depth);
    }
}

ll query(int cur, int s, int e, int x, int depth){
    if(x < s || e < x)return 0;
    else if(s == x && x == e)return (st[cur].x * fib[OFFSET + depth + 1] + st[cur].y * fib[OFFSET + depth]) % MOD;
    else {
        int mid = (s + e)>>1,c1 = cur<<1, c2 = c1 | 1;
        ll ret = modd(query(c1, s, mid, x, depth) + query(c2, mid+1, e, x, depth));
        ret += (st[cur].x * fib[OFFSET + depth + 1] + st[cur].y * fib[OFFSET + depth]) % MOD;
        return modd(ret);
    }
}
int c = 0;
void dfs(int cur, int d){
    _start[cur] = c++;
    dpth[cur] = d;
//    trace2(_start[cur], cur);
    foreach(v, tree[cur])dfs(*v, d+1);
    _end[cur] = c-1;    
}

int main(){
    precompute();fill(st, 0);
    int n,m;cin>>n>>m;forall(i, 2, n+1){
        int x;cin>>x;tree[x].pb(i);
    }
    dfs(1,1);
//    traceArr(fib, MAXN*2);
    while(m--){
        char Q;cin>>Q;
        if(Q == 'U'){int x,y;cin>>x>>y;update(1, 0, n-1, _start[x], _end[x], y, dpth[x]);}
        else{int x;cin>>x;cout<<query(1, 0, n-1, _start[x], dpth[x])<<endl;}
    }
    return 0;
}