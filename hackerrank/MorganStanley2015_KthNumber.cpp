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
#include <set>
#include <unordered_set>
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
const int MAXN = 1e5+10;

class FenwickTree
{
    vector<int> tree;
    int n;
    void add(int idx, int val)
    {
        for(;idx < n; idx = (idx | (idx + 1)))
            tree[idx] += val;
    }
 

 
public:
    FenwickTree(int n)
    {
        this->n = n;
        tree = vector<int>(n, 0);
    }
 
    void inc(int idx)
    {
        add(idx, 1);
    }
 
    void dec(int idx)
    {
        add(idx, -1);
    }
    int get(int pos)
    {
        int res = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += tree[pos];
        return res;
    }
    void tr(){
        forall(i, 0, n){
            trace2(i, tree[i]);
        }
    }
};


pii A[MAXN];
int B[MAXN];
piii query[MAXN];
int ans[MAXN];
int N,Q;
bool cmp(piii a, piii b){return (a.F.F == b.F.F)?a.F.S < b.F.S:a.F.F < b.F.F;}

int main(){
    s(N);s(Q);
    FenwickTree tree = FenwickTree(N+10);
    forall(i, 1, N+1){
        int t;s(t);
        A[i-1] = mp(t,i);
        B[i] = t;
    }
    sort(A,A+N);
    forall(i, 0, N){
        tree.inc(A[i].S);
    }
    forall(i, 0, Q){
        int k,l;
        s(l);s(k);
        query[i] = mp(mp(l,k),i);
    }
    sort(query , query + Q, cmp);
    int ptr = 0;
    forall(i, 0, Q){
        int L = query[i].F.F;
        int K = query[i].F.S;
        while(A[ptr].F < L){
            tree.dec(A[ptr++].S);
        }
        int low = 1, hi = N;
        int as=1;
        while(1){
            int mid = (low+hi)>>1;
            int v = tree.get(mid);
            if(as == mid)break;
            as = mid;
            if(v == K)hi=mid;
            else if(v < K)low = mid;
            else hi = mid;
        }
        ans[query[i].S]=B[as];
        if(tree.get(as) < K){
            ans[query[i].S] = B[as+1];
        }if(tree.get(as) > K){
            while(1);
            ans[query[i].S] = B[as-1];
        }
    }
    forall(i, 0, Q)printf("%d\n",ans[i]);
    return 0;
    
}