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

//dirextion
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

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

const int MAXN = 100100;
map<ll, ll> ma;
vector<ll> v;
ll n;
ll A[2 * MAXN];
ll B[2 * MAXN];

ll i,j,k,m;
ll count_inv(ll A[], ll start, ll end){
    if(start >= end)return 0;
    else{
        ll mid = (start + end)>>1;
        ll ans = count_inv(A, start, mid) + count_inv(A, mid + 1, end);
        for(i=start,j=mid+1,k=start; i<=mid && j<=end;){
            if(A[i] <= A[j]){
                B[k++] = A[i++];
                
            }else{
                B[k++] = A[j++];
                ans += (mid - i + 1);
            }
        }
        while(i<=mid)B[k++] = A[i++];
        while(j<=end)B[k++] = A[j++];
        for( m=start; m <= end; m++){
            A[m] = B[m];
        }
      //  trace3(ans,start,end)
        return ans;
    }
}

ll count_inversion(ll A[],ll size){
    return count_inv(A,0,size-1);
}



int main(){
    ll a,b;
    sl(n);
    forall(i, 0, n){
        sl(a);sl(b);
        if(!in(a,ma)){
            ma[a] = a;
            v.pb(a);    
        }
        if(!in(b,ma)){
            ma[b] = b;
            v.pb(b);
        }
        swap(ma[a], ma[b]);
    }
    sort(all(v));
    forall(i, 0, v.size()){
        A[i] = ma[v[i]];
//        printf("%lld ",A[i]);
    }
    ll ans = count_inversion(A,v.size());
    ll ac_pos,cur_pos,in_bet;
    ll in_bet2;
    forall(i, 0, v.size()){
        ac_pos = INDEX(v, ma[v[i]]);
        if(v[ac_pos] != ma[v[i]] || ac_pos < 0 || ac_pos >= v.size())printf("screwed");
        cur_pos = i;
        in_bet = abs(ac_pos - cur_pos) + 1;
        in_bet2 = abs(v[i] - ma[v[i]]) + 1;
        ans += in_bet2 - in_bet;
    }
//    for(int i=0; i<v.size() ; i++){
//        printf("%lld ",A[i]);
//    }
//    printf("\n");
    printf("%lld\n",ans);
    return 0;
} 