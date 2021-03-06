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

ll DP[101][101];
ll DP2[101][101];
ll A[101][101];
ll m,n;

void init(){
    fill(DP,0);
    fill(DP2,0);
    forall(i,0,m){
	forall(j,0,n){
	    if(i == 0 || j == 0){
		DP[i][j] = A[i][j];
		//		printf("%d\n",DP[i][j]);
	    }
	    else{
	      DP[i][j] = DP[i-1][j-1] + A[i][j];
	    }
	}
    }
    forall(i,0,m){
	forall(j,0,n){
	    if(i==0 || j == n-1){
		DP2[i][j] = A[i][j];
	    }
	    else{
		DP2[i][j] = A[i][j] + DP2[i-1][j+1];
	    }
	}
    }
}

int main(){
    int t;
    s(t);
    while(t--){
	sl(m);sl(n);
	forall(i,0,m){
	    forall(j,0,n){
		sl(A[i][j]);
	    }
	}
	init();
	
	// forall(i,0,m){
	//     forall(j,0,n){
	//       //      printf("%d=%d ",DP[i][j],DP2[i][j]);
	//     }
	//     printf("\n");
	// }
	
	ll maxim=-100000000000000;
	//printf("%lld",maxim);
	ll rmax,temp,temp2;
	
	forall(i,0,m){
	    forall(j,0,n){
		rmax = miN(m-i,n-j);
		forall(r,1,rmax){
		  // printf("%d %d %d\n",i,j,r);
		    if(r&1){
			if(i==0 || j ==0)temp=DP[i+r][j+r];
      			else
			    temp = DP[i+r][j+r]-DP[i-1][j-1];
			if(i==0 || j+r == n-1)temp2 = DP2[i+r][j];
			else
			    temp2 = DP2[i+r][j] - DP2[i-1][j+r+1];
			//		printf("%d %d %d = %lld\n",i,j,r,temp+temp2);
			maxim = maX(maxim,temp+temp2);
		    }
		    else{
			if(i==0 || j ==0)temp=DP[i+r][j+r];
      			else
			    temp = DP[i+r][j+r]-DP[i-1][j-1];
			if(i==0 || j+r == n-1)temp2 = DP2[i+r][j];
			else
			    temp2 = DP2[i+r][j] - DP2[i-1][j+r+1];
			temp += temp2;
			temp -= A[i+r/2][j+r/2];
			//	printf("%d %d %d = %lld\n",i,j,r,temp);
			maxim = maX(maxim,temp);
		    }
		}
	    }
	}
  
	printf("%lld\n",maxim);
    }
    return 0;
}
