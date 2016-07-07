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
const int MAXN = 1e5;
int lis[MAXN];
int siz[MAXN];
bool isPrime[MAXN];
vi prime;
vi ans[MAXN+1];
int mm[MAXN];
void init(){
    fill(isPrime,-1);
    forall(i, 2, MAXN){
        if(isPrime[i]){for(ll j = 1LL*i*i; j<MAXN; j+=i)isPrime[j]=false;prime.pb(i);}
    }
}
int main(){
    init();
    siz[1] = 1;
    mm[1] = 1;
    ans[1].pb(1);
    lis[1] = 1;
    siz[2] = 2;lis[2] = 1;
    mm[2] = 2;
    ans[2].pb(2);ans[2].pb(1);
    int c=0,p=0,k=0,y=0;
    int m = 0,x=0;
    forall(i, 3, MAXN+1){
        siz[i] = lis[i] = INF;
//        trace1(i);
        if(isPrime[i]){
            int mx=0,s=0;
//            for(int j=16; j>=0; j--){
//                if(checkbit(i, j)){
//                    if(mx == 0){mx = j;s=j<<1;}
//                    else s += mx + j;
//                }
//            }
//            if(siz[i] > s){siz[i] = s; lis[i] = mx;}
            s = siz[i-1] + lis[i-1];int l = lis[i-1];
            siz[i] = s; lis[i] = l;
            foreach(v, ans[i-1]){
                ans[i].pb(*v+lis[i]);
            }forall(j, 1, lis[i]+1)ans[i].pb(j);
//            if(siz[i] > s){siz[i] = s; lis[i] = l;p++;}
//            else {trace3(i, siz[i],s);}
        }
        else{
            int lim = sqrt(i) + 1;
            forall(j, 0, prime.size()){
                if(prime[j] > lim)break;
                if(i % prime[j] == 0){
                    int s = siz[i/prime[j]] + siz[prime[j]];
                    int l = lis[i/prime[j]] + lis[prime[j]];
//                    int s1 = siz[i/(i/prime[j])] + siz[i/prime[j]];
//                    int l1 = lis[i/(i/prime[j])] + lis[i/prime[j]];
//                    if(s1 < s){swap(s1,s);swap(l1,l);}
                    siz[i] = s;lis[i]=l;
                    if(s > siz[i-1] + lis[i-1]){
                        siz[i] = siz[i-1]+lis[i-1];lis[i]=lis[i-1];
                        foreach(v, ans[i-1]){
                            ans[i].pb(*v+lis[i]);
                        }forall(b, 1, lis[i]+1)ans[i].pb(b);
                        
                    }else{
                        foreach(v, ans[i/prime[j]]){
                            ans[i].pb(*v);
                        }//trace4(ans[i/prime[j]].size(), siz[i/prime[j]], i, i/prime[j]);
                        assert(ans[i/prime[j]].size() == siz[i/prime[j]]);
                        foreach(v, ans[prime[j]]){
                            ans[i].pb(*v + siz[i/prime[j]]);
                        }
                    }
                    break;
//                    if(siz[i] > s){siz[i] = s; lis[i] = l;}
//                    else if(siz[i] == s && lis[i] < l){lis[i]=l;}
                }
            }
//            int s = siz[i-1] + lis[i-1];int l = lis[i-1];
//            if(siz[i] > s){trace4(i,siz[i],s,l);siz[i] = s; lis[i] = l;}
//            if(i % 2 == 1){
//                int s = siz[i-1] + lis[i-1];int l = lis[i-1];
////                siz[i]=s;lis[i]=lis[i-1];
//                if(siz[i] > s){siz[i] = s; lis[i] = l;}
//            }

        }

//        if(siz[i] > s){trace4(i,siz[i],s,isPrime[i]);siz[i] = s; lis[i] = mx;}
        if(m < siz[i]){m = siz[i];x=i;}
        if(k < lis[i]){k = lis[i];y=i;}
//        if(siz[i] > 100){trace4(i,siz[i],isPrime[i],lis[i]);c++;}
    }
//    cout<<m<<' '<<x;
//    bitset<17>a(x);cout<<' '<<a<<endl;
//    trace1(ans[10]);
//    trace1(ans[x]);
//    trace2(y, k);
//            trace1(siz[99991]);
//            trace1(c);
//            trace2(p, prime.size());
//ios::sync_with_stdio(false);
    int t;cin>>t;while(t--){
        int n;cin>>n;
        cout<<ans[n].size()<<endl;
        foreach(v, ans[n])cout<<*v<<' ';
        cout<<endl;
    }
}