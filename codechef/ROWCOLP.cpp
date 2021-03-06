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

ll R[320000];
ll C[320000],maxR,maxC;
char A[20];
int main(){
    int n,q,t,v;
    fill(R,0);
    fill(C,0);
    s(n);s(q);
    while(q--){
	ss(A);
	if(A[0] == 'R'){
	    s(t);s(v);
	    R[t] += v;
	}
	else if(A[0] == 'C'){
	    s(t);s(v);
	    C[t] += v;
	}
	else{
	    q++;
	    printf("sldkgj");
	}
    }
    maxR = -1;
    maxC = -1;
    forall(i,1,n+1){
	maxR=maX(maxR,R[i]);
//	printf("R[%d] = %d",i,R[i]);
    }
    forall(i,1,n+1){
	maxC = maX(maxC,C[i]);
//	printf("R[%d] = %d",i,C[i]);
    }
    printf("%lld\n",maxR+maxC);
    return 0;
}
