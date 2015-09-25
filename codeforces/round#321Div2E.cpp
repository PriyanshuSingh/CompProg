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
const int MOD = 1e9+7;
const int MAXN = 1e5+10;

int st[MAXN<<2];
int dirty[MAXN<<2];
char a[MAXN];
int pow256[MAXN];
int sums256[MAXN];
int N,M,K;

void fill_pow256(){
    pow256[0]=1;
    forall(i, 1, MAXN){
        pow256[i] = (1LL*pow256[i-1]*256)%MOD;
    }    
}

void fill_sums256(){
    sums256[0]=0;
    forall(i,1,MAXN){
        int a = sums256[i-1]+pow256[i-1];
        sums256[i]=(a>=MOD)?a-MOD:a;
    }
}

void make_st(int cur, int s, int en){
    if(s==en){
        st[cur] = a[s-1]-'0';
    }else{
        int c1=cur<<1,c2=c1|1;
        int mid = (s+en)>>1;
        make_st(c1, s, mid);
        make_st(c2, mid+1, en);
        st[cur] = (1LL*st[c1]*pow256[en-mid] + st[c2])%MOD;
    }
}

void lazy(int cur, int s, int en){
    if(s==en){
        st[cur] = dirty[cur];
        a[s-1]=dirty[cur];
    }else{
        st[cur] = (1LL*dirty[cur]*sums256[en-s+1])%MOD;
        dirty[cur<<1]=dirty[cur];
        dirty[(cur<<1)+1]=dirty[cur];
    }
    dirty[cur] = -1;
}

void update(int cur, int s, int en, int St, int En, int chr){
    if(dirty[cur]!=-1)lazy(cur, s, en);
    if(En < s || en < St)return;
    else if(St <= s && en <= En){
        dirty[cur] = chr;
        lazy(cur, s, en);
    }else{
        int c1=cur<<1,c2=c1|1;
        int mid=(s+en)>>1;
        update(c1, s, mid, St, En, chr);
        update(c2, mid+1, en, St, En, chr);
        st[cur] = (1LL*st[c1]*pow256[en-mid] + st[c2])%MOD;
    }
}

int getHash(int cur, int s, int en, int St, int En){
    if(dirty[cur]!=-1)lazy(cur, s, en);
    if(En < s || en < St)return -1;
    else if(St <= s && en <= En)return st[cur];
    else{
        int c1=cur<<1,c2=c1|1;
        int mid=(s+en)>>1;
        int a = getHash(c1, s, mid, St, En);
        int b = getHash(c2, mid+1, en, St, En);
        if(a==-1)return b;
        if(b==-1)return a;
        // Important remember the bounds: here s<=St && En<=en but it
        return (1LL*a*pow256[(En<en?En:en) - mid] + b)%MOD;
    }
}

int main(){
    s(N);s(M);s(K);
    ss(a);
    M+=K;
    fill_pow256();
    fill_sums256();
    fill(dirty,-1);
    make_st(1, 1, N);
    while(M--){
        int t,l,r,w;
        s(t);s(l);s(r);s(w);
        if(t==1){
            update(1, 1, N, l, r, w);
        }else{
            if(r-l+1 == w)puts("YES");
            else if(getHash(1, 1, N, l, r-w) == getHash(1, 1, N, l+w, r))puts("YES");
            else puts("NO");
        }
    }
}