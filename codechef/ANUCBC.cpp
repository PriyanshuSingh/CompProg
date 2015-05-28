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

const int MOD = 1e9+9;
const int MAXN = 1e5+5;
const int MAXM = 105;
int memo[MAXM][MAXM];
int A[MAXN];
int _count[MAXM];
int fac[MAXN],inv_fac[MAXN];
int summ[MAXM];
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

void init(){
    fac[1] = 1;
    fac[0] = 1;
    forall(i, 2, MAXN)fac[i] = (1LL*fac[i-1]*i)%MOD;
    for(int i = MAXN-1; i>=0; i--){
        inv_fac[i] = modInverse(fac[i]);
    }
}

inline int C(int n,int r){
    return (((1LL*fac[n]*inv_fac[r])%MOD)*inv_fac[n-r])%MOD;
}

inline int modd(int a,int m){
    return (a < 0) ? a + m: a;
}

int DP(int m){
    fill(memo,0);
    forall(i, 0, m){
        fill(summ,0);
        forall(k, 0, _count[i]+1){
            summ[(i*k)%m] += C(_count[i],k);
            summ[(i*k)%m] = (summ[(i*k)%m] > MOD)?summ[(i*k)%m]-MOD:summ[(i*k)%m];
        }
        forall(j, 0, m){
            if(i == 0 && j == 0){
                memo[i][j] = summ[0];
            }
            forall(k, 0, m){
                if(i!=0){
                    memo[i][j] += (1LL*memo[i-1][modd(j-k,m)]*summ[k])%MOD;
                    memo[i][j] = (memo[i][j] > MOD)?memo[i][j]-MOD:memo[i][j];
                }else{
                    break;
                }
            }
            //trace3(memo[i][j], i, j)
        }
    }
    return memo[m-1][0];
}

/** slow solution
void DP(int n, int m){
    fill(memo,0);
    memo[0][0] = 1; 
    memo[0][modd(A[0], m)]++;
    forall(i, 1, n){
        int el = modd(A[i], m);
        forall(j, 0, m){
            int jsum = modd(j+el,m);
            memo[i][jsum] += memo[i-1][j];
            memo[i][jsum] = (memo[i][jsum] > MOD)? memo[i][jsum] - MOD: memo[i][jsum];
            memo[i][j] += memo[i-1][j];
            memo[i][j] = (memo[i][j] > MOD)? memo[i][j] - MOD: memo[i][j];
        }
    }
}
**/

int main(){
    int T,N,Q,M;
    s(T);
    init();
    while(T--){
        s(N);s(Q);
        forall(i, 0, N)s(A[i]);
        while (Q--) {
            int ans = 1;
            s(M);
            fill(_count,0);
            forall(i, 0, N){
                _count[modd(A[i]%M,M)]++;
            }
            //forall(i, 0, M)trace2(i, _count[i]);
            ans = DP(M);
            printf("%d\n",ans);
        }
    }
}