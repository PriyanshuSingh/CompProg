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
#define checkbit(n,b)                ( ((n) >> (b)) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define DEBUG

// debugging

#ifdef DEBUG
#define _FLINE_                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__)
#define trace1(x)                    _FLINE_;cerr << #x << "=" << x << endl;
#define trace2(x, y)                 _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define _FLINE_
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

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}

#define LastOne(k)    (k & (-k))

const int MAXN = 1e4+10;
int ft[MAXN];

int N;
        char buffer[33];
int query(int b){
    int sum=0;
    for(;b>0;b-=LastOne(b)){
        sum+=ft[b];

        forall(i, 0, 32){
            if(checkbit(b, i))buffer[31-i]='1';
            else buffer[31-i]='0';
        }
        printf("%s\n",buffer);
    }
    return sum;
}

void add(int b, int val){
    trace2("ADD", b);
    for(;b<=N;b+=LastOne(b)){
        ft[b]+=val;
        forall(i, 0, 32){
            if(checkbit(b, i))buffer[31-i]='1';
            else buffer[31-i]='0';
        }
        printf("%s\n",buffer);
    }
    trace1(
}

void update(int l, int r, int val){
    add(l, val);
    add(r+1, -val);
}

int main(){
    int T,U,Q;
    s(T);
    while(T--){
        s(N);s(U);
        N++;
        fill(ft,0);
        forall(i, 0, U){
            int l,r,v;
            s(l);s(r);s(v);
            update(l+1, r+1, v);
        }
        s(Q);
        while (Q--) {
            int b;s(b);
            printf("%d\n",query(b+1));
        }
    }
    return 0;
}