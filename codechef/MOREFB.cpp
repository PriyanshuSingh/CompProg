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
const int FMOD = 33330;
const int MOD = 99991;
int FIB[FMOD];
int memo[1001][FMOD][2];
int A[2010];
inline int moddf(int a){
    return (a >= FMOD)?a-FMOD:a;
}
inline int modd(int a){
    return (a >= MOD)?a-MOD:a;
}
int main(){
    int N,K;
    s(N);s(K);
    int sm=0;
    forall(i, 0, N){
        s(A[i]);
        A[i] %= FMOD;
        sm+=A[i];
        //trace1(A[i])
    }
    sm++;
    fill(memo,0);
    bool rev=false;
    if(K>1000){
        K = N-K;
        rev=true;
    }
    FIB[0] = 0;FIB[1] = 1;
    forall(i, 2, FMOD)FIB[i] = modd(FIB[i-1]+FIB[i-2]);
    //forall(i, 0, 20)trace2(FIB[i], i);
    memo[0][0][0] = 1;
    int prev = 0;
    int next = 1;
    forall(i, 0, N){
        forall(j, 0, miN(FMOD,sm)){
            forall(k, 0, K){
                memo[k][j][next] += memo[k][j][prev];
                if(memo[k][j][prev] > 0){
                    //trace4(j, A[i],memo[k][j][prev],k+1)
                    memo[k+1][moddf(j+A[i])][next] += memo[k][j][prev];
                }
                memo[k][j][prev] = 0;
            }
        }
        forall(j, 0, miN(FMOD, sm)){
            memo[K][j][prev] = memo[K][j][next];
            //trace3(memo[K][j][next], K, prev);
        }
        next = prev;
        prev = (prev+1)&1;
        //trace1(prev);
    }
    int ans=0;
    int ff = (sm-1) % FMOD;
    forall(i, 0, miN(FMOD, sm)){
        //trace2(memo[K][i][prev],i)
        if(!rev){
            ans = modd(ans + (1LL*memo[K][i][prev]*FIB[i])%MOD);
        }else{
            ans = modd(ans + (1LL*memo[K][i][prev]*FIB[(ff-i<0)?ff-i+FMOD:ff-i])%MOD);
        }
    }
    printf("%d\n",ans);
}