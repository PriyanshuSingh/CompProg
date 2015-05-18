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

const ll MOD = 1e9 + 7;
ll N,K;
ll Kn,Kn1,Kn2,Kn3,Kn4,Kn5,Kn6,K2n,K2n1,K2n2,K2n3,K2n4,K2n5;
ll cn,cn1,cn2,cn3,cn4,cn5,cn6,c2n,c2n1,c2n2,c2n3,c2n4,c2n5;
ll K_1,Kplus,N2;

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

ll solve1(){
    ll ans = (K * K_1) % MOD;
    cn1 = (4 - 6 * N2) % MOD;
    cn2 = (3 * N2 - 3 * N + 1) % MOD;
    cn = (3 * N2 + 3 * N + 1) % MOD;
    ll ans1 = 0;
    ans1 += (cn1 * Kn1) % MOD;
    ans1 += (cn2 * Kn2) % MOD;
    ans1 += (cn * Kn) % MOD;
    ans1 = ans1 - K*K - 4*K - 1;
    ans1 %= MOD;
    ans1 = (ans1 < 0) ? ans1 + MOD : ans1;
    ans = (ans * ans1) % MOD;
    return ans;
}

ll solve2(){
    ll ans = (K_1 * Kplus) % MOD;
    ans = (ans * K * 3) % MOD;
    cn2 = (4 * (N2 + N - 1)) % MOD;
    cn4 = (-2 * N2 - N + 1) % MOD;
    cn1 = (-2 * N - 4) % MOD;
    cn3 = (2 * N) % MOD;
    c2n2 = (-2 * N - 1) % MOD;
    c2n4 = (2 * N - 1) % MOD;
    cn = (-2 * N2 + -3 * N - 1) % MOD;
    ll ans1 = 0; 
    ans1 += (cn2 * Kn2) % MOD;
    ans1 += (cn4 * Kn4) % MOD;
    ans1 += (cn1 * Kn1) % MOD;
    ans1 += (cn3 * Kn3) % MOD;
    ans1 += (c2n2 * K2n2) % MOD;
    ans1 += (c2n4 * K2n4) % MOD;
    ans1 += (cn * Kn) % MOD;
    ans1 = ans1 + 5*K*K + 4*K + 1;
    ans1 %= MOD;
    ans1 = (ans1 < 0) ? ans1 + MOD : ans1;
    ans = (ans * ans1) % MOD;
    return ans;
}

void init(){
    Kn = powM(K,N);
    Kn1 = (Kn * K) % MOD;
    Kn2 = (Kn1 * K) % MOD;
    Kn3 = (Kn2 * K) % MOD;
    Kn4 = (Kn3 * K) % MOD;
    Kn5 = (Kn4 * K) % MOD;
    Kn6 = (Kn5 * K) % MOD;
    K2n = (Kn * Kn) % MOD;
    K2n1 = (K2n * K) %MOD;
    K2n2 = (K2n1 * K) % MOD;
    K2n3 = (K2n2 * K) % MOD;
    K2n4 = (K2n3 * K) % MOD;
    K2n5 = (K2n4 * K) % MOD;
    K_1 = modInverse(K-1);
    N2 = (N * N) % MOD;
    Kplus = modInverse(K+1);
    K_1 = ((K_1 * K_1) % MOD * K_1) % MOD;
    Kplus = (Kplus * Kplus) % MOD;
}

ll add1(){
    c2n3 = -N;
    c2n5 = N-2;
    ll ans1 = Kn4;
    ans1 += 2*Kn5;
    ans1 += Kn6;
    ans1 += (c2n3 * K2n3) % MOD;
    ans1 += -K2n4;
    ans1 += (c2n5 * K2n5) % MOD;
    ll temp = K*K*K;
    temp = (temp * temp)%MOD;
    ans1 += -temp;
    ans1 %= MOD;  
    ans1 = (ans1 < 0) ? ans1 + MOD: ans1;
    return ans1;
}

ll add2(){
    cn1 = N-1;
    cn = -N;
    ll ans1 = (cn1 * Kn1)%MOD;
    ans1 += (cn * Kn) % MOD;
    ans1 += K;
    ans1 %= MOD;
    ans1 = (ans1 < 0) ? ans1 + MOD : ans1;
    ans1 = (ans1 * K * K) % MOD;
    return ans1;
}

ll sub1(){
    c2n = -(N+1);
    cn1 = 2;
    c2n1 = -1;
    c2n2 = N-1;
    ll ans1 = (c2n * K2n)%MOD;
    ans1 += (cn1 * Kn1) %MOD;
    ans1 += Kn2;
    ans1 += (c2n1 * K2n1) %MOD;
    ans1 += (c2n2 * K2n2) %MOD;
    ans1 += Kn - K;
    ans1 %= MOD;
    ans1 = (ans1<0) ? ans1 + MOD: ans1;
    ans1 = (ans1 * K * K) % MOD;
    return ans1;
}

ll diff1(){
    ll ans1 = (add1() * (K-1)) % MOD;
    ans1 += (add2() * (K*K-1)*(K*K-1)) % MOD;
    ans1 += (sub1() * (1 - K)) % MOD; 
    ll aa = modInverse((K*K-1) * (K*K - 1));
    ll bb = modInverse((K-1)*(K-1)*(K-1));
    ans1 = (ans1 * aa) %MOD;
    ans1 = (ans1 * bb) % MOD;
    ans1 = (ans1 * 6) % MOD;
    return ans1;
}

ll total(){
    ll ans = modInverse(K-1);
    ll temp = (Kn1 - K < 0) ? Kn1 - K + MOD : Kn1 - K;
    ans = (ans * temp) % MOD;
    temp = (ans * ans) % MOD;
    ans = (ans * temp) % MOD;
    return ans;
}

int main(){
    int T;
    s(T);
    ll a1,a2,tt,ans;
    while(T--){
        sl(N);sl(K);
        init();
        tt = total();
        a1 = solve1();
        a2 = solve2();
        ll aa = diff1();
        ans = tt - a1 - a2 - aa;
        ans %= MOD;
        ans = (ans < 0) ? MOD + ans : ans;
//        ll temp = K*K;
//        temp %= MOD;
//        temp = (temp * K) % MOD;
//        temp = (temp * K) % MOD;
//        temp = (temp * (K-1)) % MOD;
//        temp = (temp * 6) % MOD;
//        ans = ans - temp;
//        ans %= MOD;
//        ans = (ans < 0) ? ans + MOD : ans;
          printf("%lld\n",ans);
    }
}