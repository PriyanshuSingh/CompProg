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

//#ifdef __MINGW32__
//#define printf __mingw_printf   /* codeforces long double problem with printf */
//#endif

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
string s;
const int MAXN = 1e5 +10;
ll shash[MAXN];
ll rhash[MAXN];
ll invBasePow[MAXN];
ll basePow[MAXN];
void precompute(){
    ll base = 256;invBasePow[0] = 1;basePow[0] = 1;
    forall(i, 1, MAXN){invBasePow[i] = pow_mod(base,(ll)(MOD-2)); basePow[i] = base; base *= 256; base %= MOD;}
}
void computeHash(){
    shash[0] = s[0]; forall(i, 1, s.length()){shash[i] = shash[i-1] + basePow[i] * s[i];shash[i] %= MOD;}
    rhash[s.length()-1] = s[s.length()-1];
    for(int i=s.length()-2; i>=0; i--){rhash[i] = rhash[i+1] + basePow[s.length()-i-1] * s[i];rhash[i] %= MOD;}
}
ll getHash(int l, int r){ll ret = shash[r] - ((l!=0)?shash[l-1]:0); if(ret<0)ret+=MOD; ret = ret * invBasePow[l] % MOD; return ret;}
ll getRHash(int l, int r){ll ret = rhash[l] - ((r != s.length()-1)?rhash[r+1]:0); if(ret<0)ret+=MOD; ret = ret * invBasePow[s.length()-1-r] % MOD;return ret;}
int bsl(int i1, int i2){
    assert(i1 != i2);
    int len = miN(i1 + 1, s.length()-i2);
    
//trace3(len, s[i1], s[i2]);
    if(s[i1] != s[i2])return 0;
    else {
        int lowlen = 1, highlen = len;
        while(lowlen < highlen){
            int mid = (highlen + lowlen)>>1;
//            trace2(i1-mid+1, i1);trace2(i2, i2+mid-1);trace1(mid);
            if(getHash(i1-mid+1,i1) != getRHash(i2,i2+mid-1))highlen=mid;
            else lowlen = mid;
            if(lowlen + 1 == highlen)break;
        }
//        trace2(i1-highlen+1, i1);trace2(i2, i2+highlen-1);trace1(highlen);
        if(getHash(i1-highlen+1,i1) == getRHash(i2, i2+highlen-1))return highlen;
        else return lowlen;
    }
}
int main(){
    int t;cin>>t;precompute();while(t--){
        int n,k;cin>>n>>k>>s;computeHash();ll ans=0;
//        trace1(s);
        forall(i, 0, n-1){
            int l = i,r = i+1;
            int val = bsl(l, r);ll len = val;
            forall(j, 0, k){
                if(l - val >= 0 && r + val < n){l -= val; r +=val; len++;}else break;
                l--; r++;
                if(l >= 0 && r<n){val = bsl(l, r); len += val;} else break;
            }

            ans += (len * (len + 1));
        }
        forall(i, 1, n-1){
            int l = i-1,r = i+1;
            int val = bsl(l, r);ll len = val;
            forall(j, 0, k){
                if(l - val >= 0 && r + val < n){l -= val; r+=val; len++;}else break;
                l--; r++;
                if(l >= 0 && r<n){val = bsl(l, r); len += val;} else break;
            }
//            trace2(len+1,s[i]);
            ans += (len * (len + 1)) + len + 1;
        }
        if(n > 1)ans+=2; else ans+=1;
        cout<<ans<<endl;
    }    
}