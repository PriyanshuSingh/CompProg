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

int ST[1<<18];
int N[1000001];

void build(int node,int L,int R){
  //  printf("%d %d %d\n",node,L,R);
    if(L == R){
	ST[node] = N[L];
	return;
    }
    else{
	build(node<<1,L,(L+R)>>1);
	build((node<<1)+1,((L+R)>>1)+1,R);
	ST[node] = maX(ST[node<<1],ST[(node<<1)+1]);
    }
    return;
}

void update(int node,int L,int R,int index,int elm){
    if(index == L && index == R)ST[node]=elm;
    else{
	if(index <= (L+R)>>1)
	    update(node<<1,L,(L+R)>>1,index,elm);
	else
	    update((node<<1)+1,((L+R)>>1)+1,R,index,elm);
	ST[node] = maX(ST[node<<1],ST[(node<<1)+1]);
    }
    
}

int main(){
    int n,k;
    s(n);
    forall(i,0,n){
	s(N[i]);
    }
    s(k);
    build(1,0,k-1);
    printf("%d ",ST[1]);
    forall(i,k,n){
	update(1,0,k-1,i%k,N[i]);
	printf("%d ",ST[1]);
    }
    printf("\n");
}
