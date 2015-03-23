/******************************************************
 * Longest palindrome subsequence
 * A palindrome is a nonempty string over some alphabet that reads the same forward and backward. 
 * Examples of palindromes are all strings of length 1, civic, racecar, and aibohphobia (fear of palindromes).
 * Give an efficient algorithm to find the longest palindrome that is a subsequence of a given input string. 
 * For example, given the input character, your algorithm should return carac.
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

char str[1000];
int memo[1000][1000];

int solve(int i, int j){
    if(i > j)return 0;
    else if(i == j)return 1;
    else if(memo[i][j] != -1)return memo[i][j];
    else if(str[i] == str[j]){
        memo[i][j] = solve(i+1, j-1) + 2;
    }
    else{
        memo[i][j] = maX(memo[i][j], solve(i+1,j));
        memo[i][j] = maX(memo[i][j], solve(i,j-1));
    }
    return memo[i][j];
}

int main(){
    int len;
    ss(str);
    len = strlen(str);
    fill(memo,-1);
    printf("%d\n",solve(0,len-1));
    return 0;        
}



