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
const int MAXN = 1e5+10;
int A[MAXN];
int memo[MAXN][3];
int N;

void solve(int i, int j){
    if(j==0){
        //start and make pair of 4
        memo[i][j] = miN(memo[i][j],memo[i+1][0]+3);
        if(A[i] < A[i+1]){
            if(A[i+1] - A[i] <= 10){
                memo[i][j] = miN(memo[i][j],memo[i+1][2]);
                if(A[i+1] > A[i]+1)memo[i][j] = miN(memo[i][j],memo[i+1][1]+1);
                if(A[i+1] > A[i]+2)memo[i][j] = miN(memo[i][j],memo[i+2][0]+2);
            }else if(A[i+1]-A[i]<=20){
                memo[i][j] = miN(memo[i][j],memo[i+1][1]+1);
                memo[i][j] = miN(memo[i][j],memo[i+2][0]+2);
            }else if(A[i+1]-A[i]<=30){
                memo[i][j] = miN(memo[i][j],memo[i+2][0]+2);
            }else{
                memo[i][j] = miN(memo[i][j],memo[i+1][0]+3);
            }
        }

    }else if(j==1){
        //only need one more 
        memo[i][j] = miN(memo[i][j], memo[i+1][0]+1);
        if(A[i] < A[i+1]){
            if(A[i+1] - A[i] <= 10){
                memo[i][j] = miN(memo[i][j], memo[i+2][0]);
            }
        }
           
    }else if(j==2){
        //need two more
        memo[i][j] = miN(memo[i][j],memo[i+1][0]+2);
        if(A[i] < A[i+1]){
            if(A[i+1] - A[i] <= 10){
                memo[i][j] = miN(memo[i][j], memo[i+1][1]);
                if(A[i+1] > A[i]+1)memo[i][j]=miN(memo[i][j],memo[i+2][0]+1);
            }else if(A[i+1] - A[i] <= 20){
                memo[i][j] = miN(memo[i][j], memo[i+2][0]+1);
            }
        }
    }
}

int main(){
    int T;s(T);
    forall(t, 1, T+1){
        s(N);
        forall(i, 0, N){s(A[i]);}
        memo[N][0] = 0;
        memo[N][1] = memo[N][2] = INF;
        memo[N+1][0] = memo[N+1][1] = memo[N+2][2] = INF;
        for(int i=N-1; i>=0; i--){
            memo[i][1] = memo[i][2] = memo[i][0] = INF;
            solve(i,0);solve(i,1);solve(i,2);
        }
        printf("Case #%d: %d\n",t,memo[0][0]);
    }
}