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

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}

const int MAXN = 5e5 + 10;
int start[MAXN];
int stop[MAXN];
char verw[MAXN];
typedef struct __VERTEX__{
    int index;
    bool z[26];
} ver;

struct cmp{
    bool operator()(const ver a, const int b){
        return start[a.index] < b;
    }
    
    bool operator()(const int a, const ver b){
        return a < start[b.index];
    }
};

vector< ver > depth[MAXN];
vi g[MAXN];
int N,M;
void dfs(int cur, int par=0, int _depth=1){
    static int t = 0;
    ver c;
    c.index = cur;
    depth[_depth].pb(c);
    start[cur] = ++t;
    foreach(v, g[cur])if(*v != par)dfs(*v,cur,_depth+1);
    stop[cur] = ++t;
}

int main(){
    s(N);s(M);
    forall(i, 2, N+1){
        int temp;s(temp);
        g[i].pb(temp);
        g[temp].pb(i);
    }
    ss(verw+1);
    dfs(1);
    forall(i, 1, N+1){
        if(!depth[i].empty()){
            forall(k, 0, 'z'-'a'+1)depth[i][0].z[k] = false;
            depth[i][0].z[verw[depth[i][0].index]-'a'] = true;
            forall(j, 1, sz(depth[i])){
                forall(k, 0, 'z'-'a'+1)depth[i][j].z[k] = false;
                depth[i][j].z[verw[depth[i][j].index]-'a'] = true;
                forall(k, 0, 'z'-'a'+1){
                    depth[i][j].z[k] ^= depth[i][j-1].z[k];
                }
            }            
        }
    }
    
    while(M--){
        int v,h;
        s(v);s(h);
        int st = (lower_bound(all(depth[h]),start[v], cmp()) - depth[h].begin());
        int en = (lower_bound(all(depth[h]),stop[v], cmp()) - depth[h].begin());
        if(st < en){
            int c=0;
            if(st != 0){
                forall(k, 0, 'z'-'a'+1){
                    if(depth[h][st-1].z[k] ^ depth[h][en-1].z[k])c++;
                }
            }else{
                forall(k, 0, 'z'-'a'+1){
                    if(depth[h][en-1].z[k])c++;
                }
            }
            if((en - st)%2 == 0){
                if(c>0)printf("No\n");
                else printf("Yes\n");
            }else{
                if(c>1)printf("No\n");
                else printf("Yes\n");
            }
        }else printf("Yes\n");
    }
}

