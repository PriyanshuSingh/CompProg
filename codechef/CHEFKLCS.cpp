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

const int MAXN = 1e3+10;
int memo[MAXN][MAXN];
int len[MAXN][MAXN];

char A[MAXN],B[MAXN];
int n;

//int dpLcs(int i, int j){
//    if(i > n || j > n){len[i][j] = 1;return memo[i][j] = 0;}
//    else if(memo[i][j] != -1)return memo[i][j];
//    else{
//        if(A[i] == B[j]){memo[i][j] = dpLcs(i+1,j+1) + 1;len[i][j] = len[i+1][j+1];}
//        else {
//            memo[i][j] = maX(dpLcs(i+1,j),dpLcs(i,j+1));
//            if(memo[i][j] == dpLcs(i+1, j))len[i][j] += len[i+1][j];
//            if(memo[i][j] == dpLcs(i, j+1))len[i][j] += len[i][j+1];
//            if(memo[i][j] == dpLcs(i+1, j+1))len[i][j] -= len[i+1][j+1];
//            if(len[i][j] >= MOD)len[i][j] = MOD;
//        }
//        return memo[i][j];
//    }
//}
const int ALPHA_SIZE = 26;
int  Aind[MAXN][ALPHA_SIZE],Bind[MAXN][ALPHA_SIZE];

void precompute(){
    int aa[ALPHA_SIZE],bb[ALPHA_SIZE];
    forall(i, 0, ALPHA_SIZE){aa[i] = -1;bb[i] = -1; Aind[n][i] = -1; Bind[n][i] = -1;}
    aa[A[n] - 'a'] = n; bb[B[n] - 'a'] = n;
    for(int i=n-1; i >=0; i--){
        forall(j, 0, ALPHA_SIZE){Aind[i][j] = aa[j];Bind[i][j] = bb[j];}
        aa[A[i] - 'a'] = i;bb[B[i] - 'a'] = i;
    }
}

string solve(int k){
    precompute();
    forall(i, 0, n+2){memo[n+1][i] = memo[i][n+1] = 0;len[i][n+1] = len[n+1][i] = 1;}
    for(int i=n; i>=1; i--)for(int j=n; j>=1; j--){
        if(A[i] == B[j]){memo[i][j] = memo[i+1][j+1]+1;len[i][j] = len[i+1][j+1];}
        else {len[i][j] = 0;
            memo[i][j] = maX(memo[i+1][j], memo[i][j+1]);
            if(memo[i][j] == memo[i+1][j])len[i][j] += len[i+1][j];
            if(memo[i][j] == memo[i][j+1])len[i][j] += len[i][j+1];
            if(memo[i][j] == memo[i+1][j+1])len[i][j] -= len[i+1][j+1];
            if(len[i][j] >= MOD)len[i][j] = MOD;
        }
    }
//    dpLcs(1, 1);
    memo[0][0] = memo[1][1] + 1;
    len[0][0] = len[1][1];
    int a_ind = 0,b_ind = 0;
    string out = "";
//    trace1(len[0][0]);
    if(len[0][0] < k)return "-1";
    while(true){
        if(out.length() == memo[1][1])return out;
        forall(i, 0, ALPHA_SIZE){
            int new_a_ind = Aind[a_ind][i];
            int new_b_ind = Bind[b_ind][i];
            if(new_a_ind == -1 || new_b_ind == -1)continue;
            if(memo[a_ind][b_ind] != memo[new_a_ind][new_b_ind] + 1)continue;
            if(k <= len[new_a_ind][new_b_ind]){
                out.push_back((char)(i+'a'));
                a_ind = new_a_ind;b_ind = new_b_ind;break;
            }else k -= len[new_a_ind][new_b_ind];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int k;cin>>n>>k;forall(i, 1, n+1)cin>>A[i];forall(i, 1, n+1)cin>>B[i];
    cout<<solve(k)<<endl;
}
