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

const int MAXN = 1e5+10;
int fr[MAXN];
int r[MAXN];
int T,N;
int deg[MAXN];
bool vis[MAXN];
ll ans,cycleans;
vi g[MAXN];
bool v[MAXN];

void mo(int i){
    if(deg[i] > 0 || vis[i] == true){
        return;
    }
    vis[i] = true;
    deg[fr[i]]--;
    mo(fr[i]);
}

ll dfs(int i){
    if(g[i].size() == 0)return (r[i] > 0)? r[i]:0;
    else{
        ll a=0;
        foreach(v, g[i]){
            a+=dfs(*v);
        }
        return (a+r[i] > 0)? a+r[i]:0;
    }
}

void cycle(int i){
    if(v[i]==true)return;
    v[i]=true;
    foreach(v, g[i]){
        if(vis[*v]){
            cycleans+=dfs(*v);
        }
    }
    cycleans += r[i];
    cycle(fr[i]);
}

int main(){
    s(T);
    while(T--){
        s(N);
        ans = 0;
        cycleans=0;
        forall(i, 0, N)g[i].clear();
        forall(i, 0, N){
            vis[i]=false;
            deg[i]=0;
            v[i]=false;
        }
        forall(i, 0, N){
            s(fr[i]);
            fr[i]--;
            deg[fr[i]]++;
            g[fr[i]].pb(i);
        }
        forall(i, 0, N)s(r[i]);
        forall(i, 0, N)mo(i);
        forall(i, 0, N){
            if(!vis[i]){
                cycle(i);
                ans+=(cycleans>0)?cycleans:0;
                cycleans=0;
            }
        }
        printf("%lld\n",ans);
    }        
}