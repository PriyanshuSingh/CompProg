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
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 10;
int memo[MAXN],N,K,Q;
ll a,b,c,d,e,f,r,s,t,m,qans,sumD,proD,pre,poM;
ll A[MAXN];
ll L1,La,Lc,Lm,D1,Da,Dc,Dm,L,R;


void findMinK(ll arr[], int n, int k)
{
    deque<int>  Qi;
    int i;
    for (i = 1; i <= k; ++i){
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()]){
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    int j = 1;
    for ( ; i <= n; ++i)
    {
        memo[j++] = A[Qi.front()];
        while ( (!Qi.empty()) && Qi.front() <= i - k )
            Qi.pop_front();
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    memo[j++] = arr[Qi.front()];
}

int main(){
    s(N);s(K);s(Q);
    sl(a);sl(b);sl(c);sl(d);sl(e);sl(f);sl(r);sl(s);sl(t);sl(m);sl(A[1]);
    sl(L1);sl(La);sl(Lc);sl(Lm);sl(D1);sl(Da);sl(Dc);sl(Dm);
    poM=t;
    forall(i, 2, N+1){
        pre = (A[i-1]*A[i-1])%m;
        poM = (poM * t) % s; 
        if(poM <= r){
            A[i] = (a*pre + b*A[i-1] + c)%m;
        }else{
            A[i] = (d*pre + e*A[i-1] + f)%m;
        }
    }
    findMinK(A, N, K);
    sumD = 0;
    proD = 1;
    Q++;
    forall(i, 1, Q){
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        qans = INF;
        L = L1 + 1;
        R = miN(L1 + K + D1, N);
        qans = miN(memo[L], memo[R-K+1]);
        sumD += qans;
        proD = (proD * qans)%MOD;
    }
    printf("%lld %lld\n",sumD,proD);
    return 0;
}