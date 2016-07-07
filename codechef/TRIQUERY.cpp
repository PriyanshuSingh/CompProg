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

const int MAXN = 3e5+10;

typedef struct __QUERY__{
    int x, y, d, i;
} query;

pii a[MAXN];
query qy[MAXN];
int ans[MAXN];
int ftx[MAXN],fty[MAXN];
int ptq[MAXN];
int bx[MAXN];
int by[MAXN];
bool isxy[MAXN];
int N,Q;

bool CMP(pii a,pii b){return (a.F==b.F)?a.S<b.S:a.F<b.F;}

bool cmp(pii a, pii b){return a.F+a.S < b.F+b.S;}
bool cmpp(query a,query b){return a.x+a.y+a.d < b.x+b.y+b.d;}
bool cmpx(query a,query b){return a.x+a.y < b.x+b.y;}

void addX(int b, int v){ for(;b<=MAXN;b+=(b&(-b)))ftx[b]+=v;}
void addY(int b, int v){ for(;b<=MAXN;b+=(b&(-b)))fty[b]+=v;}

int getX(int b){ int sum=0;for(;b;b-=(b&(-b)))sum+=ftx[b];return sum;}
int getY(int b){ int sum=0;for(;b;b-=(b&(-b)))sum+=fty[b];return sum;}

int main(){
    s(N);s(Q);
    fill(ftx, 0);
    fill(fty, 0);
    fill(ptq, 0);
    fill(isxy, 0);
    forall(i, 0, N){s(a[i].F);s(a[i].S);}
    sort(a,a+N);
    forall(i, 0, Q){s(qy[i].x);s(qy[i].y);s(qy[i].d);qy[i].i=i;if(binary_search(a, a+N, mp(qy[i].x,qy[i].y), CMP))isxy[i]=true;}
    
    sort(qy, qy+Q, cmpx);
    sort(a,a+N,cmp);
    
    int j = 0;
    forall(i, 0, Q){
        while(j < N && qy[i].x + qy[i].y >= a[j].F + a[j].S){         
            addX(a[j].F, 1);
            addY(a[j].S, 1);
            j++;
        }
        int xLess = getX(qy[i].x);
        int yLess = getY(qy[i].y);
        bx[qy[i].i] = xLess - getX(qy[i].x-1);
        by[qy[i].i] = yLess - getY(qy[i].y-1);
        int tot = j;
        ptq[qy[i].i] = xLess + yLess - tot; 
    }
    sort(qy, qy+Q, cmpp);
    fill(ftx,0);
    fill(fty,0);
    j = 0;
    forall(i, 0, Q){
        while(j<N && qy[i].d+qy[i].x+qy[i].y >= a[j].F+a[j].S){
            addX(a[j].F, 1);
            addY(a[j].S, 1);
            j++;
        }
        int xLess = getX(qy[i].x);
        int yLess = getY(qy[i].y);
        int belxy = xLess + yLess - ptq[qy[i].i];
        int a = j - belxy;
        int onx = xLess - getX(qy[i].x-1);
        int ony = yLess - getY(qy[i].y-1);
        a += onx + ony - bx[qy[i].i] - by[qy[i].i] + isxy[qy[i].i];
        ans[qy[i].i] = a;
    }
    forall(i, 0, Q)printf("%d\n",ans[i]);
    return 0;
}