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

const int MAXN = 1.25e5+10;
ll shash[MAXN][10];
ll thash[MAXN];
ll invTenHash[MAXN];
int f[10],used[10];
string s,t;

inline ll modd(ll a){return (a>=MOD)?a-MOD:a;}

void precompute(){
    forall(i, 0, 10)shash[0][i]=0;
    shash[0][s[0]-'a'] = 1;
    ll ten = 256;
    invTenHash[0] = 1;
    thash[0] = t[0]-'a';
    forall(i, 1, s.length()){forall(j, 0, 10)shash[i][j] = modd(((s[i]-'a' == j)?ten:0) + shash[i-1][j]);thash[i] = modd(thash[i-1] + (t[i] - 'a') * ten % MOD);invTenHash[i]=pow_mod(ten,(ll)MOD-2);ten = ten * 256 % MOD;}
}

ll getSHash(int l, int r, int map[]){
    ll lh=0,rh=0;
    forall(i, 0, 10){if(l != 0)lh += map[i] * shash[l-1][i];rh += map[i] * shash[r][i];}
    lh %= MOD; rh %= MOD;
    rh -= lh;if(rh < 0)rh += MOD;
    rh = (rh * invTenHash[l]) % MOD;
    return rh;
}

ll getThash(int l, int r){ll ret; ret = thash[r] - ((l != 0)?thash[l-1]:0);if(ret < 0)ret+=MOD;return ret * invTenHash[l] % MOD;}

ll getLCP(int x, int y, int map[]){
    int highlen = s.length() - max(x,y);
    int lowlen = 1;
    while(lowlen < highlen){
//        trace2(lowlen, highlen);
        int mid = (lowlen + highlen)>>1;
        if(getSHash(x, x+mid-1, map) != getThash(y, y+mid-1))highlen = mid;
        else lowlen = mid;
        if(lowlen + 1 == highlen)break;
    }
    if(getSHash(x, x+highlen-1, map) == getThash(y, y+highlen-1))return highlen;
    else return lowlen;    
}

int main(){
    ios_base::sync_with_stdio(false);
    int T;cin>>T;while(T--){
        int n,q;
        cin>>n>>q>>s>>t;precompute();while(q--){
            int x,y;cin>>x>>y;x--;y--;
            forall(k,0,10)f[k]=11;fill(used,0);
            n = s.length();//trace1(n);
            int i =0;
            do{
                f[s[x + i] - 'a'] = t[y + i] - 'a';
                used[t[y + i]-'a'] = true;
                i = getLCP(x,y,f);
//                if(j <= i)trace6(j,i,(char)(f[s[x+j] - 'a']+'a'),s[x+j],t[y+j],used[t[y+j]-'a']);
            }while(i+x < n && i+y < n && f[s[x+i]-'a'] == 11 && used[t[y+i]-'a'] == false);
            int k=0;
            forall(j, 0, 10)if(f[j] == 11){while(used[k])k++;f[j] = k;used[k]=true;}
//            if(i<10)cout<<i;else cout<<getLCP(x, y, f);cout<<' ';
            cout<<i<<' '; 
            forall(i, 0, 10)cout<<(char)(f[i] + 'a');cout<<endl;
//            traceArr(f, 10);

        }
    }
    return 0;
}