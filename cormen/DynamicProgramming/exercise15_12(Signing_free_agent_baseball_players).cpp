/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Signing free-agent basball players
 * Problem:Suppose that you are the general manager for a major-league baseball team. During the off-season, you need to sign some free-agent 
 * players for your team. The team owner has given you a budget of $X to spend on free agents. You are allowed to spend less than $X 
 * altogether, but the owner will fire you if you spend any more than $X.You are considering N different positions, and for each position, P 
 * free-agent playerswhoplaythatpositionareavailable.8 Becauseyoudonotwanttooverload your roster with too many players at any position, for 
 * each position you may sign at most one free agent who plays that position. (If you do not sign any players at a particular position, then 
 * you plan to stick with the players you already have at that position.)
 * To determine how valuable a player is going to be, you decide to use a sabermet- ric statistic9 known as “VORP,” or “value over replacement 
 * player.” A player with a higher VORP is more valuable than a player with a lower VORP. A player with a higher VORP is not necessarily more   
 * expensive to sign than a player with a lower VORP, because factors other than a player’s value determine how much it costs to sign him.
 * For each available free-agent player, you have three pieces of information:
 * the player’s position,
 * the amount of money it will cost to sign the player, and the player’s VORP.
 * Devise an algorithm that maximizes the total VORP of the players you sign while spending no more than $X altogether.
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

int memo[100][10000];
// position 100 ; total X 10000

vector<pair<int,int> > players[100];

int sol(int i, int j){
    if(i < 0 || j == 0)return 0;
    else if(memo[i][j] != -1)return memo[i][j]; 
    else{
        memo[i][j] = sol(i-1,j);
        foreach(v, players[i]){
            
            if(v->S <= j){
                memo[i][j] = maX(memo[i][j], sol(i-1, j - v->S) + v->F);
            }
        }
    }
    return memo[i][j];
}

int solve(int n, int m, int x){
    fill(memo,-1);
    return sol(n-1,x);
}

int main(){
    int n,m,u,v,w,x; // v = vorp; w = cost to sign; u = position; n = no. of positions; m = no. of players
    fs(n);fs(m);
    forall(i, 0, m){
        fs(u);fs(v);fs(w);
        players[u].pb(mp(v,w));
    }
    fs(x);
    printf("%d\n",solve(n,m,x));
    return 0;
}
/**************
 * Test Case
 * 5 20
 * 0 1 9
 * 0 4 7
 * 0 3 10
 * 0 2 1
 * 1 6 10
 * 1 2 12
 * 1 22 20
 * 1 9 1
 * 2 3 3
 * 2 8 3
 * 2 10 10
 * 2 11 4
 * 3 8 8
 * 3 1 2
 * 3 3 8
 * 3 2 4
 * 4 9 9
 * 4 2 3
 * 4 5 3 
 * 4 1 1
 * 40
 *
 *
 * output: 48
 */

