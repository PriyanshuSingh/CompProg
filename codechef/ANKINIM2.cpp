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
#define gc    getchar_unlocked
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

#include <complex>
typedef complex<double> cd;
typedef vector<cd> vcd;


inline void fastprint(int a){
    static char str[55];
    register int pt = 0;
    if(a==0)putchar_unlocked('0');
    else{
        while(a){
            str[pt++]=a%10+'0';
            a/=10;
        }
        for(int i = pt-1; i>=0; --i)putchar_unlocked(str[i]);
    }
    putchar_unlocked(' ');
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

inline vcd fft(const vcd &as, int m, cd w){
    if(m == 1)return vcd(1, as[0]);
    else{
        vcd a_even(m/2), a_odd(m/2);
        forall(i, 0, m/2){a_even[i]=as[(i<<1)]; a_odd[i] = as[(i<<1) + 1];}
        vcd f_even = fft(a_even, m/2, w*w);
        vcd f_odd = fft(a_odd, m/2, w*w);
        vcd f(m);
        cd a = cd(1,0);
        forall(i, 0, m/2){
            f[i] = f_even[i] + a*f_odd[i];
            f[i+m/2]=f_even[i] -a*f_odd[i];
            a = a*w;
        }
        return f;
    }
}

inline int bit_rev(int a,int k){
    int c=0;
    forall(i, 0, k){
        if(checkbit(a, i)){
            c+= (1<<(k-i-1));
        }
    }
    return c;
}

void fft_iter(cd A[], int size, cd out[], bool inverse){
    // size is power of 2;
    int c = 1;
    int k = 0;
    while(c<size){c<<=1;k++;}
    forall(i, 0, size){
        out[i] = A[bit_rev(i,k)];
    }
    
    for(int s=2; s<=size; s<<=1){
        double alpha = 2*M_PI/(1.0 * s);
        if(inverse)alpha = -alpha;
        cd wm = cd(cos(alpha), sin(alpha));
        for(int k=0;k<size; k+=s){
            cd w = cd(1,0);
            for(int j=0; j<s/2; j++){
                cd t = w*out[k+j+s/2];
                cd u = out[k+j];
                out[k+j] = u + t;
                out[k+j+s/2] = u - t;
                w *= wm;
            }
        }
    }
}

const int MAXN = 1e5+10;
const int pM = 262154;
int A[MAXN];
pii xo[MAXN];
int N;
vi arr[MAXN];
cd X[pM],Y[pM],Z[pM];
int ans[MAXN];

int main(){
    int T;s(T);
    forall(i, 0, pM){X[i]=cd(0,0);Y[i]=cd(0,0);}
    while(T--){
        fill(ans,0);
        fs(N);
        int m = 2;while(m<(2*N))m<<=1;
        double alpha = 2*M_PI/m;
        //trace1(m);
        cd W = cd(cos(alpha),sin(alpha));
        forall(i, 0, N)fs(A[i]);
        xo[0] = mp(A[0], 0);
        if(A[0] == 0)ans[1]++;
        forall(i, 1, N){xo[i] = mp(xo[i-1].F^A[i],i); if(xo[i].F == 0)ans[i+1]++;}
        sort(xo, xo+N);
        int pre = xo[0].F;
        int pt = 0;
        arr[pt].clear();
        arr[pt].pb(xo[0].S);
        forall(i, 1, N){
            if(pre == xo[i].F){
                arr[pt].pb(xo[i].S);
            }else{
                arr[++pt].clear();
                arr[pt].pb(xo[i].S);
                pre = xo[i].F;
            }
        }
        forall(i, 0, pt+1){
            if(sz(arr[i]) < 12000){
                forall(j, 0, sz(arr[i])){
                    forall(k, j+1, sz(arr[i])){
                        ans[arr[i][k]-arr[i][j]]++;
                    }
                }
            }else{
                //vcd A(m,cd(0,0)),B(m,cd(0,0));
                forall(j, 0, sz(arr[i])){
                    //A[arr[i][j]] = cd(1,0);
                    //B[N-arr[i][j]] = cd(1,0);
                    X[arr[i][j]] = cd(1,0);
                    Y[N-arr[i][j]] = cd(1,0);
                }
                fft_iter(X, m, Z, false);
                fft_iter(Y, m, X, false);
                forall(j, 0, m){Z[j] *= X[j];Y[j]=cd(0,0);}
                fft_iter(Z, m, X, true);
                for(int j=0; j<=N; j++)X[j]=cd(0,0);
                for(int j=N+1; j<=2*N; j++){
                    ans[j-N] += (int)(X[j].real()/m + 0.5);
                    X[j] = cd(0,0);
                }
                for(int j=2*N+1;j<m;j++)X[j]=cd(0,0);
                
//                vcd F_A = fft(A, m, W);
//                vcd F_B = fft(B, m, W);
//                vcd F_C(m);
//                forall(j, 0, m)F_C[j] = F_A[j]*F_B[j];
//                vcd CC = fft(F_C, m, cd(1,0)/W);
//                forall(j, N+1, 2*N+1){
//                    ans[j-N] += (int)(CC[j].real()/m + 0.5);
//                }
            }
        }
        forall(i, 1, N+1)fastprint(ans[i]);
        putchar_unlocked('\n');
    }
    return 0;
}