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

#ifdef __MINGW32__
#define printf __mingw_printf   /* codeforces long double problem with printf */
#endif

//#if __cplusplus > 199711L
//#define typeof decltype
//#endif

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
#define foreach(v, c)               for( __typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
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
#define sqr(a)                      (a) * (a)


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
// can print whole array (arr should not contain any pointer airthmetics)
#define traceArr(arr,size)           do{ vi __ARRAY_NAME__##arr((arr), (arr)+(size)); trace1(__ARRAY_NAME__##arr);}while(0)
#else
#define METHOD_NAME
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define traceArr(arr,size)
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

const int MAXN = 5e5+10;
ll coins[MAXN];
ll preSum[MAXN];

struct retValue{
    ll value;
    ll index;
};

retValue getDaysForMin(ll minValue, ll N){
    ll lowInd = 0, highInd = N-1;
    while(lowInd < highInd){
        ll mid = (lowInd + highInd)>>1;
        if(coins[mid] > minValue)highInd = mid;
        else lowInd = mid;
//        trace3(lowInd, highInd, minValue);
        if(lowInd + 1 == highInd)break;

    }
    if(minValue >= coins[highInd]){
        return (retValue){minValue*(highInd+1) - preSum[highInd],highInd};
    }else{
        return (retValue){minValue*(lowInd+1) - preSum[lowInd], lowInd};
    }
}

retValue getDaysForMax(ll maxValue, ll N){
    ll lowInd = 0, highInd = N-1;
    while(lowInd < highInd){
        ll mid = (lowInd + highInd)>>1;
        if(coins[mid] < maxValue)lowInd = mid;
        else highInd = mid;
//        trace3(lowInd, highInd, maxValue);
        if(lowInd + 1 == highInd)break;
    }
    if(coins[lowInd] >= maxValue){
        return (retValue){preSum[N-1] - ((lowInd > 0)?preSum[lowInd-1]:0) - maxValue*(N-lowInd), lowInd};
    }else{
        return (retValue){preSum[N-1] - ((highInd > 0)?preSum[highInd-1]:0) - maxValue*(N-highInd), highInd};
    }
}

void addCoins(ll N, ll K){
    ll low,high;
    low = 1;high = 2e9 + 10;
    while(low < high){
        ll mid = (low + high)>>1;
        if(getDaysForMin(mid, N).value > K)high=mid;
        else low = mid;
        if(low + 1 == high)break;        
    }
//    trace2(low, high);
//    assert(high<N && low >=1);
    retValue ans = getDaysForMin(high, N);
    if(ans.value == K){
        forall(i, 0, ans.index+1)coins[i] = high;
    }else{
        ans = getDaysForMin(low, N);
        int i = ans.index;
        int j = K - ans.value;
//        trace3(i, j, low);
        while(j--)coins[i--] = low+1;
        for(; i>=0; i--)coins[i] = low;
    }
}

void subCoins(ll N, ll K){
    ll low,high;
    low = 1;high = 2e9 + 10;
    while(low < high){
        ll mid = (low + high)>>1;
        if(getDaysForMax(mid, N).value > K)low=mid;
        else high = mid;
        if(low + 1 == high)break;        
    }
//    trace2(low, high);
//    assert(high<N && low >=1);
    retValue ans = getDaysForMax(low, N);
    if(ans.value == K){
        forall(i, ans.index, N)coins[i] = low;
    }else{
        ans = getDaysForMax(high, N);
        int i = ans.index;
        int j = K - ans.value;
//        trace3(i, j, high);
        while(j--)coins[i++] = high-1;
        for(; i<N; i++)coins[i] = high;
    }
}


int main(){
    ll N,K;sl(N);sl(K);
    forall(i, 0, N)sl(coins[i]);
    sort(coins, coins + N);
    preSum[0] = coins[0];
//    traceArr(coins, N);
    forall(i, 1, N)preSum[i] = preSum[i-1] + coins[i];
    addCoins(N, K);
//    traceArr(coins, N);
    preSum[0] = coins[0];
    forall(i, 1, N)preSum[i] = preSum[i-1] + coins[i];
    subCoins(N, K);
//    traceArr(coins,N);

    ll minVal = coins[0];
    ll maxVal = coins[N-1];
    pl(maxVal - minVal);pn;        
    return 0;
}