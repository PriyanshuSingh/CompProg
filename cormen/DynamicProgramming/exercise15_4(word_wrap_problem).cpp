/************************************************************
 * Word Wrap
 * Consider the problem of neatly printing a paragraph with a monospaced font (all characters having the same width) on a printer. 
 * The input text is a sequence of n words of lengths l1,l2..ln , measured in characters. 
 * We want to print this para- graph neatly on a number of lines that hold a maximum of M characters each. Our criterion of “neatness” is as follows. 
 * If a given line contains words i through j , where i 􏰔 j , and we leave exactly one space between words, 
 * the number of extra space characters at the end of the line is M 􏰖- j + i 􏰖sum(li..lj), which must be nonnegative so that the words fit on the line.
 * We wish to minimize the sum, over all lines except the last, of the cubes of the numbers of extra space characters at the ends of lines.
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


int memo[1000];
int word[1000];
int len[1000][1000];
int line_len;

int cost(int space){return space*space*space;}

int sol(int i){
    if(i < 0)return 0;
    else if(memo[i] != -1)return memo[i];
    else{
        memo[i] = INF;
        for(int k = i; line_len - len[k][i] - i + k >= 0; k--){
            memo[i] = miN(memo[i], sol(k-1) + cost(line_len - len[k][i] - i + k));
        }
    }
    return memo[i];
}

int solve(int n){
    fill(memo,-1);
    forall(i, 0, n){
        len[i][i] = word[i];
        forall(j, i+1, n){
            len[i][j] = len[i][j-1] + word[j];
        }
    }
    return sol(n-1);
}


int main(){
    int n,m;
    fs(n);
    forall(i, 0, n){
        fs(word[i]);
    }
    fs(line_len);
    printf("%d\n",solve(n));
}
/*******
 * Test case
 * 10
 * 3 3 4 2 5 6 3 2 3 4
 * 6
 *
 * output = 143
 */




