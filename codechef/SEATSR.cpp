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

int memo[2][100010];
char A[100010];
char B[100010];
int lnA,lnB;
int a,b,mx;

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

inline int getstr(char *str){
    register char c=gc();
    register int count=0;
    for(;c < 'a' || c > 'z';c=gc());
    for(;c>='a' && c <= 'z';c=gc()){
	*str = c;
	str++;
	count++;
    }
    *str = '\0';
    return count;
}

inline int ans(int lenA,int lenB){
    if(lenA > lenB + mx/a || lenB > lenA + mx/a)return -1;
    register int next,prev,c_min,j_min,j_max;
    forall(j,0,(mx/a)+1){
	memo[0][j] = j*a;
    }
    forall(j,mx/a+1,lenB+1){
      memo[0][j] = INF;
    }
    forall(i,1,lenA+1){
	next = i%2;
	prev = 1 - next;
	c_min = INF;
	j_min = maX(1,i-(mx/a));
	j_max = miN(i+(mx/a),lenB);
	memo[next][0] = i*a;

	if(j_min > 1)memo[next][j_min-1]=INF;
	if(j_max < lenB)memo[next][j_max+1] = INF;
	forall(j,j_min,j_max+1){
	    if(A[i] == B[j]){
		memo[next][j] = memo[prev][j-1];
	    }
	    else{
		memo[next][j] = miN(memo[prev][j] + a, memo[next][j-1]+a);
		memo[next][j] = miN(memo[next][j],memo[prev][j-1]+b);
	    }
	    c_min = miN(c_min,memo[next][j]);
	}
	if(c_min>mx)return -1;
    }
    return (memo[(lenA)%2][lenB] > mx)? -1 : memo[(lenA)%2][lenB];
}

int main(){
    int t;
    fs(t);
    while(t--){
	lnA = getstr(&(A[1]));
	lnB = getstr(&(B[1]));
	fs(a);fs(b);fs(mx);
	if(a==0)printf("0\n");
        else{
	    printf("%d\n",ans(lnA,lnB));
	}
    }
    return 0;
}
