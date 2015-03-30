/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 */

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
#define sf(n)                       scanf("%f",&n)
#define slf(n)                      scanf("%lf",&n)
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
#define F                           first
#define S                           second

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define DEBUG

// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif


// datatypes
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair< pii, int> piii;
typedef vector< piii > vpiii;
typedef pair<int, bool> pib;
typedef vector< pii > vpii;
typedef vector< pib > vpib;

const int maxn = 100001;
int a[maxn];
int b[maxn];
long long int n;

bool is(int r){
    fill(b,0);
    forall(i,0,r){
	++b[a[i]];
    }
    forall(i,0,r){
	if(n-i-1 >= r){
	    --b[a[n-i-1]];
	    if(b[a[n-i-1]] < 0)return false;
	}
    }
    for(int i=r; i<n; i++){
	if(n-i-1 < r)break;
	else{
	    if(a[i] != a[n-i-1])return false;
	}
    }
    int odd = 0;
    forall(i, 0, n){
	odd += b[i] % 2;
    }
    if(n % 2 == 1 && odd <= 1)return true;
    else if(odd == 0)return true;
    else return false;
}

int main(){
    sl(n);
    forall(i, 0, n){
	s(a[i]);
    }
    int l=0;
    while(l < n && a[l] == a[n - l -1])++l;
    if(l*2 >= n) printf("%lld\n",(n*(n+1))/2);
    else{
	int ri = n+1;
	int le = l;
	while(le+1 < ri){
	    int mid = (le + ri) >> 1;
	    if(is(mid)){
		ri = mid;
	    }
	    else le = mid;
	}
	if(ri == n+1){
	    printf("0\n");
	    return 0;
	}
	int z1 = ri;
	reverse(a,a+n);
	le = l;
	ri = n+1;
	while(le+1 < ri){
	    int mid = (le + ri) >> 1;
	    if(is(mid)){
		ri = mid;
	    }
	    else le = mid;
	}
	int z2 = ri;
	ll ans = ((ll)l+1)*((ll)l+1);
	if(z1 + l < n)
	    ans += ((ll)l + 1) * ((ll)n - z1 - l);
	if(z2 + l < n)
	    ans += ((ll)l + 1) * ((ll)n - z2 - l);
	printf("%lld\n",ans);
    }
    return 0;
}
