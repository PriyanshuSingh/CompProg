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

const int MAXN = 1e5+10;

ll S1[MAXN];
ll S2[MAXN];
ll S3[MAXN];

const ll MOD = 1e9 + 7;
ll N,K;

ll powM(ll a, ll b) {
    ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

ll modInverse(ll a){
    return powM(a, MOD-2);
}


ll Kn;
ll temp,temp2;
ll m_in;


ll sol3(ll n){
    if(S3[n] != -1)return S3[n];
    S3[n] = (Kn - 2 < 0) ? MOD + Kn - 2 : Kn - 2;
    S3[n] *= (Kn - 1 < 0) ? MOD + Kn - 1 : Kn - 1;
    S3[n] %= MOD;
    S3[n] = (S3[n] * Kn) % MOD;
    return S3[n];
}

ll sol2(ll n){
    if(n == 1 || K == 1)return S2[n] = 0;
    if(S2[n] != -1)return  S2[n];
    temp = (Kn - K < 0) ? MOD + Kn - K : Kn - K;
    temp = (temp * m_in) % MOD;
    temp = (temp - n + 1 < 0) ? MOD + (temp - n + 1): temp - n + 1;
    temp *= Kn;
    temp %= MOD;
    temp *= K-1;
    temp = (temp * 3 + sol2(n-1) * K * K + sol3(n-1) * K * K * 3) % MOD;
    
    return S2[n] = temp;
}


ll sol1(ll n){
    if(S1[n] != -1)return S1[n];
    if(n == 1)return S1[n] = 0;
    temp = (sol2(n-1) * K * 2) % MOD;
    temp2 = (sol3(n-1) * K * 3) % MOD;
    S1[n] = (sol1(n-1) * K) % MOD;
    S1[n] = (S1[n] + temp + temp2) % MOD;
    return S1[n];
}
ll tt;
int main(){
    int T;
    s(T);
    while(T--){
        sl(N);sl(K);
        fill(S1,-1);
        fill(S2,-1);
        fill(S3,-1);
        S1[0] = 0;
        S2[0] = 0;
        S3[0] = 0;
        m_in = modInverse(K-1);
        Kn = K;
        ll ans = sol3(1);
        forall(i, 2, N+1){
            Kn = (Kn * K) % MOD;
            tt = (Kn-K < 0)? MOD + Kn-K : Kn-K ;
            tt *= m_in;
            tt %= MOD;
            tt = ((tt*tt)%MOD * tt)%MOD;
            //trace4(tt, ans, tt-ans, i-1)
            ans = (ans + sol2(i) + sol3(i) + sol1(i)) % MOD;
        }
        Kn = (Kn * K) % MOD;
        tt = (Kn-K < 0)? MOD + Kn-K : Kn-K ;
        tt *= m_in;
        tt %= MOD;
        tt = ((tt*tt)%MOD * tt)%MOD;
        //trace5(tt, ans, tt-ans, N, K)
        printf("%lld\n",ans);
    }
    return 0;
}
