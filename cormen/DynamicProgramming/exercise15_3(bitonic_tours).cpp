/******************************************************
 * Bitonic euclidean travelling-salesman problem
 * In the euclidean traveling-salesman problem, we are given a set of n points in the plane, and we wish to find the shortest closed 
 * tour that connects all n points. Figure 15.11(a) shows the solution to a 7-point problem. 
 * The general problem is NP-hard, and its solution is therefore believed to require more than polynomial time (see Chapter 34).
 * J. L. Bentley has suggested that we simplify the problem by restricting our at- tention to bitonic tours, that is, tours that start at the leftmost
 * point, go strictly rightward to the rightmost point, and then go strictly leftward back to the starting point.
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
typedef pair<int, int> point;
point parr[1000];

bool cmp(point a, point b){
    return a.first < b.first;
}

float cost(point a, point b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));    
}

float memo[1000];
float path[1000][1000];

float bitonic(int i){
    if(i <= 0)return 0;
    else if(i == 1)return cost(parr[0],parr[1]);
    else if(memo[i] != INF)return memo[i];
    else{
        forall(k, 0, i-1){
            memo[i] = miN(memo[i], cost(parr[i],parr[k]) + bitonic(k+1) + path[k+1][i-1]);
        }
    }
    return memo[i];
}

float solve(int n){
    forall(i, 0, n){
        memo[i] = INF;
    }
    forall(i, 0, n){
        path[i][i] = 0;
        forall(j, i+1, n){
            path[i][j] = path[i][j-1] + cost(parr[j],parr[j-1]);
        }
    }
    return bitonic(n-1) + cost(parr[n-1],parr[n-2]);
}

int main(){
    int n,x,y;
    fs(n);
    forall(i, 0, n){
        fs(x);fs(y);
        parr[i] = mp(x,y);
    }
    sort(parr, parr+n, cmp);
    printf("%f\n",solve(n));
    return 0;
}

/**********
 * Test case
 * 7
 * 0 6
 * 1 0
 * 2 3
 * 5 4
 * 6 1
 * 7 5
 * 8 2
 *
 * output = 25.584026
 */


