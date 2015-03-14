/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 *
 * Inventory Planning
 * Problem: The Rinky Dink Company makes machines that resurface ice rinks. The demand
 * for such products varies from month to month, and so the company needs to de-
 * velop a strategy to plan its manufacturing given the fluctuating, but predictable,
 * demand. The company wishes to design a plan for the next n months. For each
 * month i, the company knows the demand d , that is, the number of machines that Pn i
 * it will sell. Let D D iD1 di be the total demand over the next n months. The company keeps a full-time 
 * staff who provide labor to manufacture up to m ma- chines per month. If the company needs to make more than m
 * machines in a given month, it can hire additional, part-time labor, at a cost that works out to c dollars per
 * machine. Furthermore, if, at the end of a month, the company is holding any unsold machines, it must pay 
 * inventory costs. The cost for holding j machines is given as a function h(j) for j=1,2,3...D, 
 * where h(j)>=􏰃0 for 1 <= 􏰎j <= 􏰎D and h(j)<=􏰎h(j+1) for 1 <=􏰎 j <= 􏰎D􏰐1.
 *
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
#define gc  getchar_unlocked

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


int memo[100][1000];
int D[100];
int n,m,c;

int h(int j){
    return j*(c+1);
}

int sol(int i, int j){
    if(memo[i][j] != -1)return memo[i][j];
    else if(i == 0)return c*(maX(0, j - m)) + h(j-D[0]);
    else{
        forall(k, D[i-1], j+1){
            memo[i][j] = INF;
            memo[i][j] = miN(memo[i][j], sol(i-1,k) + c * maX(0,(j-k-m)));
        }
        memo[i][j] += h(j-D[i]);
    }
    return memo[i][j];
}

int solve(){
    fill(memo,-1);
//    forall(j, D[0], D[n-1]+1){
//        memo[0][j] = c*(maX(0, j - m)) + h(j-D[0]);
//    }
    return sol(n-1,D[n-1]);
}

int main(){
    fs(n);fs(m);fs(c);
    fs(D[0]);
    forall(i, 1, n){
        fs(D[i]);
        D[i] += D[i-1];
    }
    printf("%d\n",solve());
//    
//    forall(i, 0, n){
//        forall(j, 0, D[n-1]+1){
//            printf("%d ",memo[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
/***************************
 * test case
 * 10 7 3
 * 11 9 6 10 1 38 25 10 8 9 
 *
 *
 * output = 2800
 */