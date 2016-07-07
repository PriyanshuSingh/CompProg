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
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair< pii, int> piii;
typedef vector< piii > vpiii;
typedef pair<int, bool> pib;
typedef vector< pii > vpii;
typedef vector< pib > vpib;

#define gc     getchar_unlocked

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";s<<t[sz(t)-1]<<"]";return s; }

const int MOD = 99991;

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
            res = (1LL* res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

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


const int MAXN = 50010;
int C[MAXN],B[MAXN];
int N,K;

#include <complex>
typedef complex<long double> cd;
typedef vector<cd> vcd;

inline int bit_rev(int a,int k){
    register int c=0;
    forall(i, 0, k){
        if(checkbit(a, i)){
            c+= (1<<(k-i-1));
        }
    }
    return c;
}

inline void fft(vcd &arr, bool inv){
    int lgn=0,n=1;
    while(n < sz(arr)){n<<=1;lgn++;}
    
    assert(n == sz(arr));
    forall(i, 0, n){int j=bit_rev(i, lgn); if(i<j)swap(arr[i],arr[j]);}

    for(int m=2; m<=n; m<<=1){
        long double alpha = (2*M_PI)/(1.0*m); if(inv)alpha = -alpha;
        cd wm = cd(cos(alpha), sin(alpha));

        for(int k = 0; k<n; k+=m){
            cd w = cd(1, 0);
            forall(j, 0, m/2){

                cd t = w*arr[k+j+m/2];
                cd u = arr[k+j];
                arr[k+j] = u + t;
                arr[k+j+m/2] = u - t;
                w = w*wm;
            }
        }
    }

    
    if(inv){
        forall(i, 0, n)arr[i] /= n;
    }
}

vll mult(vll &a, vll &b){
    vcd ta(a.begin(), a.end()), tb(b.begin(), b.end());
    ll n = 1, mx = maX(a.size(), b.size());
    while(n<mx)n<<=1;
    n<<=1;

    //resize a and b
    ta.resize(n);tb.resize(n);
    fft(ta, false);fft(tb, false);
    forall(i, 0, n)ta[i] *= tb[i];
    fft(ta, true);

    vll res(n);
    forall(i, 0, n){res[i] = (ll)(ta[i].real() + 0.5); res[i] %=MOD;}
    return res;
}

vll solve(int st, int en, int A[]){
    if(st == en){vll a(2); a[0]=A[st]; a[1]=1;return a;}
    else{ 
        int mid = (st + en)>>1; 
        vll l = solve(st, mid, A); 
        vll r = solve(mid+1, en, A);
        return mult(l,r); 
    }
}

ll ans(int A[]){
    ll a= solve(0,N-1, A)[N-K];
    return a;
}

int main(){
    const int a = 22019,b = 55048,c=44944;
    fs(N);fs(K);
    forall(i, 0, N){
        int tmp;fs(tmp);
        C[i] = pow_mod(c, tmp);
        B[i] = pow_mod(b, tmp);
    }
    ll bb = ans(B), cc = ans(C);
    bb = a*(bb - cc + MOD);
    bb %= MOD;
    if(bb < 0)bb+=MOD;
    printf("%lld",bb);
}

