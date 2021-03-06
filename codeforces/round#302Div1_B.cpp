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

const int MAXN = 3010;

int d[MAXN][MAXN];
int n,m;
int s1,t1,s2,t2,l1,l2;
vi g[MAXN];
queue<int> q;
void BFS(int src){
    forall(i, 0, n){
        d[src][i] = INF;
    }
    d[src][src] = 0;
    q.push(src);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        foreach(v, g[top]){
            if(d[src][*v] > d[src][top] + 1){
                d[src][*v] = d[src][top] + 1;
                q.push(*v);
            }
        }
    }
}

int main(){
    int a,b;
    s(n);s(m);
    forall(i, 0, m){
        s(a);s(b);
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    forall(i, 0, n){
        BFS(i);
    }
    s(s1);s(t1);s(l1);
    s(s2);s(t2);s(l2);
    s1 = s1-1;
    t1 = t1-1;
    s2 = s2-1;
    t2 = t2-1;
    int ans = -1;
    if(d[s1][t1] <= l1 && d[s2][t2] <= l2){
        ans = maX(ans , m - d[s1][t1] - d[s2][t2]);
    }
    forall(i, 0, n){
        forall(j, 0, n){
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2){
                ans = maX(ans, m - d[s1][i] - d[s2][i] - d[i][j] - d[j][t1] - d[j][t2]);
            }
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[t2][i] + d[i][j] + d[j][s2] <= l2){
                ans = maX(ans, m - d[s1][i] - d[i][j] - d[t2][i] - d[j][t1] -d[j][s2]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}