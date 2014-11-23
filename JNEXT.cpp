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

int A[1000001];

int main(){
    int t;
    int n;
    int  v;
    int temp;
    bool flag;
    s(t);
    while(t--){
	s(n);
	forall(i,0,n){
	    s(A[i]);
	}
	flag = false;
	for(int i=n-1;i>=1;i--){
	    if(A[i] > A[i-1]){
		v = i;
		forall(j,i,n){
		    if(A[j]<A[v] && A[j]>A[i-1])v=j;
		}
		temp = A[v];
		A[v] = A[i-1];
		A[i-1] = temp;
		if(i+1 < n)sort(A+i,A+n);
		flag = true;
		break;
	    }
	}
	if(flag){
	    forall(i,0,n)printf("%d",A[i]);
	    printf("\n");
	}else{
	    printf("-1\n");
	}
    }
    return 0;
}
