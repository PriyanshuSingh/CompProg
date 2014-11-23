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

struct p{
    int ver;
    int time;
};

vector<p> graph[100001];
bool vis[100001];
class compareP{
public:
    bool operator()(p& t1,p& t2){
	if(t1.time > t2.time)return true;
	return false;
    }
};

int BFS(int so,int dest){
    priority_queue<p,vector<p>,compareP> Q;
    if(so==dest)return 0;
    Q.push((p){so,0});
    while(!Q.empty()){
	p tp = Q.top();
	Q.pop();
	vis[tp.ver] = true;
	if(tp.ver == dest)return tp.time;
	foreach(v,graph[tp.ver]){
	  //	  printf("%d--- \n",v->ver);
	    if(!vis[v->ver]){
		Q.push((p){v->ver,v->time+tp.time});
	    }
	}
    }
    return -1;
}

int main(){
    int t;
    int sour,dest,a,b,tim,n,m,ans;
    s(t);
    while(t--){
	s(n);s(m);
	s(sour);s(dest);
	fill(vis,0);
	while(m--){
	    s(a);s(b);s(tim);
	    graph[a].pb((p){b,tim});
	    graph[b].pb((p){a,tim});
	}
	if((ans = BFS(sour,dest)) == -1)printf("NONE\n");
	else
	  printf("%d\n",ans);
	forall(i,0,n+1)graph[i].clear();
    }
    return 0;
}
