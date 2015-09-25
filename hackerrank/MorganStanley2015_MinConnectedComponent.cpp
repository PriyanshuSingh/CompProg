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
#define checkbit(n,b)                ( ((n) >> (b)) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define DEBUG

// debugging

#ifdef DEBUG
#define _FLINE_                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__)
#define trace1(x)                    _FLINE_;cerr << #x << "=" << x << endl;
#define trace2(x, y)                 _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define _FLINE_
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

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}
const int MAXN = 2e5+10;

pii A[MAXN];
int N,Q;

int st[MAXN<<2];

void make_st(int cur, int s, int e){
    if(s==e)st[cur] = A[s].S;
    else{
        int c1 = cur<<1, c2=c1|1;
        int mid = (s+e)>>1;
        make_st(c1,s,mid);
        make_st(c2,mid+1,e);
        st[cur] = miN(st[c1], st[c2]);
    }
}

void update(int cur, int s, int e, int x, int val){
    if(x < s || e < x)return;
    else if(s==e && s==x){
        st[cur] = val;
        A[s].S = val;
    }else{
        int c1 = cur<<1, c2=c1|1;
        int mid = (s+e)>>1;
        update(c1, s, mid, x, val);
        update(c2, mid+1, e, x, val);
        st[cur] = miN(st[c1], st[c2]);
    }
}

inline int findC(int u){
    int preu = u;
    while(A[u].F != u){
        u=A[u].F;
        A[preu].F = A[u].F;
        preu = u;
    }
    return u;
}

void uni(int u, int v){
    int paru=findC(u);
    int parv=findC(v);
    if(parv == paru)return;
    else{
        int delv = paru;
        int delval = INF;
        int mergev = parv;
        int mergeval = A[paru].S+A[parv].S;
        update(1, 1, N, delv, delval);
        update(1, 1, N, mergev, mergeval);
        A[paru].F = parv;
    }
}

int main(){
    s(N);s(Q);
    forall(i, 1, N+1){
        int t;s(t);
        A[i] = mp(i,t);
    }
    make_st(1, 1, N);
    while(Q--){
        int u,v;
        s(u);s(v);
        uni(u,v);
        printf("%d\n",st[1]);
    }
}
