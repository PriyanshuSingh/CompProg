/*************************************************
 * Problem statement
 * Longest simple path in a directed acyclic graph
 * Suppose that we are given a directed acyclic graph G = (V,E) with real- valued edge weights and two distinguished vertices s and t.        
 * Describe a dynamic- programming approach for finding a longest weighted simple path from s to t.
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
#define sf(n)                       scanf("%lf",&n)
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

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

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

typedef struct {
    int n; // node
    bool out; //is outdegree
    int w; // weight, can be negative!
} edge;

// adj list
vector<edge> gp[10000];

int dist[10000];
bool vis[10000];
bool bad[10000];

int solv(int des){
    int temp,count=0;
    if(vis[des]) return dist[des];
    else{
        foreach(v, gp[des]){
            if(!v->out){
                /*****************
                 * same print statement at two places can help
                 * to see recursion properly
                 */ 
                //printf("#(%d, %d)\n",v->n,des);  
                temp = solv(v->n);
                if(!bad[v->n]){
                    //printf("(%d, %d)\n",v->n,des);
                    count++;
                    dist[des] = maX(dist[des], temp + v->w);
                }
            }
        }
        if(count == 0)bad[des] = true;
        vis[des] = true;
    }
    return dist[des];
}


int solve(int des, int src, int n){
    forall(i, 0, n){
        dist[i] = -INF;
        vis[i] = false;
        bad[i] = false;
    }
    dist[src] = 0;
    vis[src] = true;
    return solv(des);
}

int main(){
    int n,m,u,v,w;
    fs(n);
    //m edges
    fs(m);
    forall(i, 0, m){
        fs(u);fs(v);fs(w);
        gp[u].pb((edge){v,true,w});
        gp[v].pb((edge){u,false,w});
    }
    fs(u);fs(v);

    printf("%d\n",solve(v,u,n));
    forall(i, 0, n){
        printf("%d ",dist[i],bad[i]);
    }
    return 0;
}





