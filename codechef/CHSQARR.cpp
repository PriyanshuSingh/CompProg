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
typedef vector<vector<int> > vvi;
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){if(t.size()==0){s<<"[]";return s;}s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";s<<t[sz(t)-1]<<"]";return s; }

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
int A[MAXN][MAXN];
int N,M,Q;
int sum[MAXN][MAXN];
int mxx[MAXN][MAXN];
//code snippet taken from http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
vi getKMax(vi arr, int k)
{
    int n = arr.size();
    std::deque<int>  Qi(k);
    vi out;out.reserve(1010);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear

        Qi.push_back(i);
    }

    for ( ; i < n; ++i)
    {

        out.pb(arr[Qi.front()]);
 
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
 
         // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    out.pb(arr[Qi.front()]);
    return out;
}
void fillSumArr(int a, int b){
    forall(i, 0, N){
        int cur=0;
        int j=0;while(j<a){cur+=A[i][j];j++;}
        int p=0;sum[i][p++] = cur;
        while(j < M){
            cur -= A[i][j-a];
            cur += A[i][j];
            sum[i][p++] = cur;
            j++;
        }
    }
    forall(j, 0, M-a+1){
        int cur=0;
        queue<int> q;
        int i=0;while(i<b){cur+=sum[i][j];q.push(sum[i][j]);i++;}
        int p=0;sum[p++][j] = cur;
        while(i < N){
            cur -= q.front();q.pop();
            cur += sum[i][j];q.push(sum[i][j]);
            sum[p++][j] = cur;
            i++;
        }
    }
}
int solve(int a, int b){
//    trace2(a, b);
    int mans= 1e9+200;
    fillSumArr(a, b);
    vvi temp;
    forall(i, 0, N){
        vi row;
        forall(j, 0, M)row.pb(A[i][j]);
        temp.pb(getKMax(row, a));
    }
    forall(j, 0, M-a+1){
        vi c;forall(i, 0, N)c.pb(temp[i][j]);
        vi col = getKMax(c, b);
        forall(i, 0, N-b+1){
//            trace4(sum[i][j],i,j,a*b*col[i]);
            mans = min(a*b*col[i] - sum[i][j], mans);
        }
    }
    return mans;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>M;
    forall(i, 0, N)forall(j, 0, M)cin>>A[i][j];
    cin>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        cout<<solve(b, a)<<endl;
    }
    return 0;
}