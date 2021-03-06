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

inline void fs(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
pair<int,int> A[2001];
bool cmp(const pair<int,int> a,const pair<int,int> b){
    if(a.first == b.first)
	return a.second < b.second;
    else
	return a.first < b.first;
}


inline int process(int n){
    if(n==0)return 4;
    else if(n==1)return 3;
    int ans = 2,x,y;
    bool p1,p2,p3,p4;
    forall(i,0,n){
	forall(j,i+1,n){
	    x = A[i].first - A[j].first;
	    y = A[i].second - A[j].second;
	    p1 = binary_search(A,A+n,mp(x-y+A[j].first,x+y+A[j].second),cmp);
	    p2 = binary_search(A,A+n,mp(-y+A[j].first,x+A[j].second),cmp);
	    p3 = binary_search(A,A+n,mp(x+y+A[j].first,y-x+A[j].second),cmp);
	    p4 = binary_search(A,A+n,mp(y+A[j].first,-x+A[j].second),cmp);
	    //printf("%d %d %d %d\n",p1,p2,p3,p4);
	    if(p1 && p2)return 0;
	    else if(p1 || p2)ans = 1;
	    if(p3 && p4)return 0;
	    else if(p3 || p4)ans = 1;
	}
    }
    return ans;
}


int main(){
    int n,x,y;
    fs(n);
    forall(i,0,n){
	fs(x);fs(y);
	A[i] = mp(x,y);
    }
    sort(A,A+n,cmp);
    int ans=process(n);
    printf("%d\n",ans);
   
    // forall(i,0,n){
    // 	printf("(%d,%d) ",A[i].first,A[i].second);
    // }
    // if(binary_search(A,A+n,(pair<int,int>){11,0},cmp))printf("found!!!\n");
    return 0;
}


