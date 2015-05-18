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
const int MAXN = 1e5+1;
const ll MOD = 1e9 + 7;
ll N,K;
ll SOL1[MAXN];
ll SOL2[MAXN];
ll SOL3[MAXN];

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

ll sol2(ll n){
    if(K == 1 || n == 1)return 0;
    ll IK_1 = modInverse(K-1);
    //trace1(IK_1)
    ll Kn = powM(K, n);
    //trace1(Kn)
    ll K2np = (Kn - K < 0) ? MOD - Kn + K : Kn - K;
    K2np = (K2np * IK_1) % MOD;
    ll K2n = (Kn * Kn) % MOD;
    //trace1(K2np)
    K2np = (K2np * K2n) % MOD;
    //trace1(K2np)
    //trace1(K2n)
    K2n = (K2n * (n-1)) % MOD;
    Kn = (Kn * (n-1)) % MOD;
    //trace1(Kn)
    //trace1(K2n)
    ll lhs = (K2np + Kn) % MOD;
    //trace1(lhs)
    ll rhs = (2 * K2n) % MOD;
    //trace1(rhs)
    ll ans = (lhs - rhs < 0) ? MOD - rhs + lhs : lhs - rhs;
    ans = (3 * ans) % MOD;
    return ans;
}

ll sol3(ll n){
    ll Kn = powM(K, n);
    //trace2(Kn,n)
    ll ans = (Kn - 2 < 0) ? MOD - Kn + 2 : Kn - 2;
    ans *= (Kn - 1 < 0) ? MOD - Kn + 1 : Kn - 1;
    ans %= MOD;
    ans = (ans * Kn) % MOD;
    return ans;
}

ll sol1(ll preSol,ll n){
    ll sol_2 = (sol2(n-1) * K * 2) % MOD;
    ll sol_3 = (sol3(n-1) * K * 3) % MOD;
    ll ans = (preSol * K) % MOD;
    ans = (ans + sol_2 + sol_3) % MOD;
    return ans;
}


int main(){
    int T;
    s(T);
    while(T--){
        sl(N);sl(K);
        //N = 1e5; K = 26;
        ll ans = sol3(1);
        ll prev = 0;
        forall(i, 2, N+1){
            prev = sol1(prev, i);
            if(i>10065 && i <= 10070)trace4(i, prev, sol2(i), sol3(i))
            ans = (ans + prev + sol2(i) + sol3(i)) % MOD;
        }
       // trace3(ans, N, K)
        printf("%lld\n",ans);
    }
    return 0;
}



     