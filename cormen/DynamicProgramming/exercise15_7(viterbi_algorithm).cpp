/*******************************************************
 * Author: Priyanshu Singh
 * Alias: tgamerz
 *
 * Viterbi Algorithm
 * We can use dynamic programming on a directed graph G = (V,E) for speech recognition. 
 * Each edge (u,v) in E is labeled with a sound 􏰍li from a finite set A of sounds. 
 * Describe an efficient algorithm that, given an edge-labeled graph G with dis- 
 * tinguished vertex 􏰇v0   and a sequence s = {l1,l2,l3...lk} of sounds from A, 
 * returns a path in G  that begins at 􏰇0 and has s as its label, if any such path exists.
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


// datatypes
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define gc  getchar_unlocked

inline void fs(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

typedef struct{
    int n;
    int sk;
    float prb;
} edge;

vector<edge> graph[1000];
pair<int, float> memo[1000][100];

float sol(int n, int k_lim){
    float max_prob;
    forall(k, 0, k_lim-1){
        forall(i, 0, n){
            if(memo[i][k].F != -1){
                foreach(v, graph[i]){
                    if(v->sk == k+1){
                        //memo[v->n][k+1].S = maX(memo[v->n][k+1].S, memo[i][k].S*(v->prb));
                        if(memo[v->n][k+1].S < memo[i][k].S*(v->prb)){
                            memo[v->n][k+1] = mp(i,memo[i][k].S*(v->prb));
                        }
                    }
                }
            }    
        }
    }
    
    max_prob = 0;
    forall(i, 0, n){
        max_prob = maX(max_prob, memo[i][k_lim-1].S);
    }
    return max_prob;
}

float solve(int root, int num, int k_lim){
    forall(i, 0, num){
        forall(k, 0, k_lim){
            memo[i][k] = mp(-1,0);
        }
    }
    foreach(v, graph[root]){
        if(v->sk == 0){
            memo[v->n][0] = mp(root,v->prb);
        }
    }
    return sol(num,k_lim);
}

int main(){
    int n,m,u,v,k,k_lim;
    float p;
    fs(n);fs(m);fs(k_lim); // n = no. of nodes; m = no. of edges; k_lim = total num of sound in A 
    forall(i, 0, m){
        fs(u);fs(v);fs(k);sf(p); // u-> v with prob = p; sound = k;
        graph[u].pb((edge){v,k,p});
    }
    fs(u); // vertx v0
    printf("max probability: %f", solve(u,n,k_lim));
}



