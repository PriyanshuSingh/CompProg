/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Breaking a string
 * Problem: A certain string-processing language allows a programmer to break a string into two pieces. 
 * Because this operation copies the string, it costs n time units to break a string of n characters into two pieces. 
 * Suppose a programmer wants to break a string into many pieces. The order in which the breaks occur can affect the total amount of time used. 
 * For example, suppose that the programmer wants to break a 20-character string after characters 2, 8, and 10 
 * (numbering the characters in ascending order from the left-hand end, starting from 1). If she programs the breaks to occur in left-to-right order, 
 * then the first break costs 20 time units, the second break costs 18 time units (breaking the string from characters 3 to 20 at character 8), 
 * and the third break costs 12 time units, totaling 50 time units. If she programs the breaks to occur in right-to-left order, however, 
 * then the first break costs 20 time units, the second break costs 10 time units, and the third break costs 8 time units, totaling 38 time units. 
 * In yet another order, she could break first at 8 (costing 20), then break the left piece at 2 (costing 8), and finally the right piece at 10 (costing 12), 
 * for a total cost of 40.
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
int L[1000];

int sol(int i, int j, int start, int end){
    if(i == j)return end - start + 1;
    else if(memo[i][j] != -1)return memo[i][j];
    else{
        memo[i][j] = miN(sol(i+1,j,L[i]+1,end) + end - start + 1, sol(i,j-1,start,L[j]) +  end - start + 1); // if we break the string from start or end
        forall(k, i+1, j){
            memo[i][j] = miN(memo[i][j], sol(i, k-1, start, L[k]) + sol(k+1, j, L[k]+1, end) + end - start + 1); /* if we break in the form str[start ... L[k]],
                                                                                                                  * str[L[k]+1 ... end] breaking at 'k' */
        }
    }
    return memo[i][j];
}

int solve(int n, int m){
    fill(memo,-1);
    return sol(0,m-1,0,n-1);
}

int main(){
    int n,m;
    fs(n);fs(m);
    forall(i, 0, m){
        fs(L[i]);
    }
    sort(L, L+m);
    printf("min cost : %d\n", solve(n,m));
//    forall(i, 0, m){
//        forall(j, 0, m){
//            trace3(memo[i][j], i, j)
//        }
//    }
    return 0;
}
/********************************************
 * Test case
 * 20 3 
 * 1 7 9
 *
 * min cost: 38
 */

