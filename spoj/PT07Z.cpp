#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
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
int n;
int dist[100001];
vector<int> graph[100001];
int mx = -1;

int BFS(int node){
    fill(dist,-1);
    int top;
    int mx_node = node;
    queue<int> Q;
    dist[node] = 0;
    Q.push(node);
    while(!Q.empty()){
	top = Q.front();
	Q.pop();
	foreach(v,graph[top]){
	    if(dist[*v] == -1){
		dist[*v] = dist[top]+1;
		Q.push(*v);
		if(mx <= dist[*v]){
		    mx = dist[*v];
		    mx_node = *v;
		}
	    }
	}
    }
    return mx_node;
}

int main(){
    int n,a,b;
    s(n);
    forall(i,0,n-1){
	s(a);s(b);
	graph[a].pb(b);
	graph[b].pb(a);
    }
    int node = BFS(1);
    node = BFS(node);
    printf("%d\n",dist[node]);
    return 0;
}
