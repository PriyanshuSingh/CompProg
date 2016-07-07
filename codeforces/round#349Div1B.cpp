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
// size must be > 0
#define traceArr(arr,size)           do{ vector< __typeof(arr[0]) > __ARRAY_NAME__##arr((arr), (arr)+(size)); trace1(__ARRAY_NAME__##arr);}while(0)
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
template<typename T> ostream& operator<<(ostream &s,vector<T> t){s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";if(sz(t) > 0)s<<t[sz(t)-1];s<<"]";return s; }

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
const int MAXN = 3e3+10;
int dist[MAXN][MAXN],dist2[MAXN][MAXN];
pii far[MAXN][3],far2[MAXN][3];
vector<pair<int, bool> > graph[MAXN];
int N,M;

void bfs(int start, bool reverse, int d[], pii f[]){
    queue<int> Q;
    Q.push(start);
    forall(i, 1, N+1)d[i] = INF;
    d[start] = 0;
    while(!Q.empty()){
        int ver = Q.front();Q.pop();
        foreach(v, graph[ver]){
            if(v->S == reverse){
                if(d[v->F] > d[ver] + 1){d[v->F] = d[ver] + 1;Q.push(v->F);}
            }
        }
    }
    f[0] = f[1] = f[2] = {-1,-1};
    forall(i, 1, N+1){
        if(d[i] == INF || i == start)continue;
        if(d[i] > f[0].F){
            swap(f[1],f[2]);
            swap(f[0],f[1]);
            f[0] = {d[i],i};
        }else if(d[i] > f[1].F){
            swap(f[1],f[2]);
            f[1] = {d[i], i};
        }else if(d[i] > f[2].F)f[2] = {d[i],i};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    
    forall(i, 0, M){
        int x,y;cin>>x>>y;
        graph[x].pb({y, false});
        graph[y].pb({x, true});
    }
    forall(i, 1, N+1){bfs(i, false, dist[i], far[i]);bfs(i, true, dist2[i], far2[i]);}
    int dsum = 0;
    int ansA,ansB,ansC,ansD;
    forall(i, 1, N+1)forall(j, 1, N+1)if(i != j && dist[i][j] != INF){
        int b = i,c = j;
//        trace2(b, c);
        forall(k, 0, 3)forall(l, 0, 3)if(far2[b][k].F != -1 && far[c][l].F != -1){
            int a = far2[b][k].S;
            int d = far[c][l].S;
            if(a != d && a != c && d != b){
                int sum = dist[a][b] + dist[b][c] + dist[c][d];
//                trace3(dist[a][b], dist[b][c], dist[c][d]);
                if(sum > dsum){dsum = sum;
                    ansA = a; ansB = b; ansC = c; ansD = d;
                }
            }
        }
    }
//    trace1(dsum);
    cout<<ansA<<' '<<ansB<<' '<<ansC<<' '<<ansD<<endl;
    return 0;
}