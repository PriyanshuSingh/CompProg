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
#define METHOD_NAME                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);
#define trace1(x)                    cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << endl;
#define trace2(x, y)                 cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              cerr<<"("<< __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define METHOD_NAME
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
const int MAXN = 8e4+10;
int st[MAXN<<2];
int laz[MAXN<<2];
pii q[MAXN<<1];
int l[MAXN],r[MAXN];
int N;
#include <set>
set<int> myset;

inline void lazy_update(int cur, int s, int e){
    if(s==e)st[cur] = laz[cur];
    else{
        int c1 = cur<<1, c2 = c1 | 1; 
        laz[c1] = laz[cur];
        laz[c2] = laz[cur];
        st[cur] = laz[cur];
    }
    laz[cur] = 0;
}

void update_st(int cur, int s, int e, int St, int En, int val){
    if(laz[cur] != 0)lazy_update(cur, s, e);
    if(En < s || e < St)return;
    else if(St <= s && e <= En){
        laz[cur] = val;
        lazy_update(cur, s, e);
    }else{
        int mid = (s+e)>>1;
        int c1 = cur<<1, c2 = c1 | 1;
        update_st(c1, s, mid, St, En, val);
        update_st(c2, mid+1, e, St, En, val);
        st[cur] = (st[c1] == st[c2] && st[c1] != 0)?st[c1]:0;
    }
}

void count_st(int cur, int s, int e){
    if(laz[cur] != 0)myset.insert(laz[cur]);
    else if(st[cur] != 0)myset.insert(st[cur]);
    else if(s==e)return;
    else{
        int mid = (s+e)>>1;
        int c1 = cur<<1, c2= c1 | 1;
        count_st(c1, s, mid);
        count_st(c2, mid+1, e);
    }
}
int main(){
    int T;s(T);
    while(T--){
        s(N);
        myset.clear();
        int pt=0;
        forall(i, 0, N){
            int le,ri;
            s(le);s(ri);
            l[i]=r[i]=-1;
            q[pt].F = le;
            q[pt++].S = i;
            q[pt].F = ri;
            q[pt++].S = i;
        }
        sort(q, q+pt);
        int k=0;
        l[q[0].S] = k;
        forall(i, 1, pt){
            if(q[i].F != q[i-1].F)k++;
            if(l[q[i].S]!=-1)r[q[i].S] = k;
            else l[q[i].S] = k;
        }
        fill(st,0);
        fill(laz,0);
        forall(i, 0, N){
            update_st(1, 0, k+1, l[i], r[i], i+1);
        }
        count_st(1, 0, k+1);
        printf("%lu\n",myset.size());
    }
    return 0;
}