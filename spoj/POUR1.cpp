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
struct p{
    int x;
    int y;
    int step;
};
queue< p > Q;
int a,b,c;

bool valid(int x,int y){
    if(x>a || y>b || x<0 || y<0)return false;
    return true;
}

int pour(){
    Q.push((p){0,0,0});
    p tp;
    while(!Q.empty()){
	tp = Q.front();
	Q.pop();
	if(tp.x == c || tp.y == c)return tp.step;
	else{
	    if(tp.x!=0){
		Q.push((p){0,tp.y,tp.step++});
		if(
	    }
	    if(tp.y!=0)
		Q.push((p){tp.x,0,tp.step++});
	    if(tp.x != a)
		Q.push((p){a,tp.y,tp.step++});
	    if(tp.y != b)
		Q.push((p){tp.x,b,tp.step++});
	}	
    }
}
