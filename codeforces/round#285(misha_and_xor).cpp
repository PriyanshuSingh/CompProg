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
#include <bitset>

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

const int MAXN = 2005;

int setbit[MAXN];
bool vis[MAXN];
bitset<MAXN> bitmat[MAXN]; // bit matrix of all no.
bitset<MAXN> ans[MAXN]; 

char str[MAXN];

int N;

int main(){
    s(N);
    forall(i, 0, N){
	ss(str);
	int len = strlen(str);
	reverse(str, str+len);
	forall(l, 0, len){
	    str[l] -= '0';
	}
	int k = 0;
	int b = 0;
	while(len){ // decimal to binary conversion
	    b = 0;
	    for(int j = len-1; j >= 0; j--){
		b = b*10 + str[j];
		str[j] = b/2;
		b &= 1;
	    }
	    bitmat[i][k++] = b;
	    while(len > 0 && !str[len-1])len--;
	}
    }
    fill(ans,0);
    forall(i, 0, N){
	ans[i][i] = 1;
    }
    fill(setbit,-1);
    forall(i, 0, N){
	int j = 0;
	for( j = 0; j < MAXN; j++){
	    if(!bitmat[i][j])continue;
	    else if(setbit[j] == -1){ // no possible way to set jth bit
	        setbit[j] = i; // 
		break;
	    }
	    else{
		bitmat[i] ^= bitmat[setbit[j]];
		ans[i] ^= ans[setbit[j]];
	    }
	}
	if( j < MAXN){
	    printf("0");
	}
	else{
	    printf("%lu ",ans[i].count()-1);
	    forall(k,0,MAXN){
		if(ans[i][k] && k != i){
		    printf("%d ",k);
		}
	    }
	   
	}
	printf("\n");
    }
    return 0;
}
