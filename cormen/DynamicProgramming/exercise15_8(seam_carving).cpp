/*******************************************************
 * Author: Priyanshu Singh
 * Alias: tgamerz
 *
 * Problem: Seam Carving
 * We are given a color picture consisting of an mx􏰘n array A[1..m][1..n]􏰆 of pixels, where each pixel specifies a triple of red, green, and blue (RGB) intensities. 
 * Suppose that we wish to compress this picture slightly. Specifically, we wish to remove one pixel from each of the m rows, 
 * so that the whole picture becomes one pixel narrower. To avoid disturbing visual effects, however, 
 * we require that the pixels removed in two adjacent rows be in the same or adjacent columns; 
 * the pixels re- moved form a “seam” from the top row to the bottom row where successive pixels in the seam are adjacent vertically or diagonally.
 * Suppose now that along with each pixel A[i,j]􏰆, we have calculated a real- valued disruption measure d[i,j]􏰆,
 * indicating how disruptive it would be to remove pixel A[i,j]􏰆. Intuitively, the lower a pixel’s disruption measure, 
 * the more similar the pixel is to its neighbors. Suppose further that we define the disruption measure of a seam to be the sum of the disruption measures of its pixels.
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

int memo[1000][1000];
int dis[1000][1000];

int solve(int n, int m){
    int min_seam=INF;
    forall(i, 0, m){
        memo[0][i] = dis[0][i];
    }
    forall(i, 0, n-1){
        forall(j, 0, m){
            if(j-1 >= 0)memo[i+1][j-1] = miN(memo[i+1][j-1], memo[i][j] + dis[i+1][j-1]);
            if(j+1 < m)memo[i+1][j+1] = miN(memo[i+1][j+1], memo[i][j] + dis[i+1][j+1]);
            memo[i+1][j] = miN(memo[i+1][j], memo[i][j] + dis[i+1][j]);
//            forall(i, 0, n){
//                trace5(memo[i][0], memo[i][1], memo[i][2], memo[i][3], memo[i][4]);
//            }
        }
    }
    forall(i, 0, m){
        min_seam = miN(min_seam, memo[n-1][i]);
    }
    return min_seam;
}

int main(){
    int n,m;
    fs(n);fs(m);    // removing from m (nXm -> nXm-1 )
    forall(i, 0, n){
        forall(j, 0, m){
            fs(dis[i][j]);
            memo[i][j] = INF;
        }
    }
    printf("min disruption: %d\n", solve(n,m));

}
/**********
 * Test case
 * 3 5
 * 2 5 3 4 6
 * 5 2 4 5 0
 * 6 4 9 3 8
 *
 *
 * min disruption: 7
 */


