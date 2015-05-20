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


const int MAXN = 3e5+10;

int N,M;
ll d[MAXN];
ll sm;
vi ans;
bool vis[MAXN];

typedef struct _Edge{
    int head;
    int w;
    int ind;
}edge;

vector<edge> g[MAXN];

class Compare{
    public:
        bool operator()(pair<edge, ll> a, pair<edge, ll> b){
            if(a.S == b.S){
                return a.F.w > b.F.w;
            }
            return a.S > b.S;
        }
};

void dijkstra(int u){
    priority_queue< pair<edge, ll>, vector< pair<edge, ll> >, Compare> pq;
    forall(i, 0, N+1)d[i] = __LONG_LONG_MAX__;
    fill(vis,0);
    d[u] = 0;
    pq.push(mp((edge){u,0,0},0));
    while(!pq.empty()){
        pair<edge, ll> e = pq.top(); pq.pop();
        if(vis[e.F.head])continue;
        vis[e.F.head] = true;
        ans.pb(e.F.ind);
        sm += e.F.w;
        foreach(v, g[e.F.head]){
            if(d[v->head] >= d[e.F.head] + v->w){
                d[v->head] = d[e.F.head] + v->w;
                pq.push(mp(*v,d[v->head]));
            }
        }
    }
}
int main(){
    int a,b,w;
    sm = 0;
    s(N);s(M);
    forall(i, 0, M){
        s(a);s(b);s(w);
        g[a].pb((edge){b,w,i+1});
        g[b].pb((edge){a,w,i+1});
    }
    s(a);
    dijkstra(a);
    printf("%lld\n",sm);
    forall(i, 1, ans.size()){
        printf("%d ",ans[i]);
    }
    return 0;
}