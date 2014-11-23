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

using namespace std;

vector<int> tr[100001];
struct nod{
    int fa;
    int val;
    int ans;
};
bool vis[100001];
nod gh[100001];
void bfs(){

    fill(vis,0);
    queue<int> Q;
    Q.push(1);
    int tp;
    while(!Q.empty()){
	tp = Q.top();
	Q.pop();
	vis[tp] = true;
	foreach(v,tr[tp]){
	    if(!vis[*v]){
		gh[*v].fa=tp;
		Q.push(*v);
	    }
	}
    }
}



int main(){
    int n,q,a,b;
    s(n);
    s(q);
    forall(i,0,n-1){
	s(a);s(b);
	tr[a].pb(b);
	tr[b].pb(a);
    }
    bfs();
    forall(i,1,n+1){
	if(!vis[i]){

	}
    }

}
