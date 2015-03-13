/*********************************************************
 * Planning company party
 * Professor Stewart is consulting for the president of a corporation that is planning a company party. The company has a hierarchical structure; 
 * that is, the supervisor relation forms a tree rooted at the president. The personnel office has ranked each employee with a conviviality rating, 
 * which is a real number. In order to make the party fun for all attendees, the president does not want both an employee and his or her immediate 
 * supervisor to attend. Each node of the tree holds, in addition to the pointers, the name of an employee and that employee’s conviviality ranking. 
 * Describe an algorithm to make up a guest list that maximizes the sum of the conviviality ratings of the guests.
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



vector<int> dag[10000];
int memo[10000];
int rate[10000];

int sol(int root){
    if(memo[root] != -INF)return memo[root];
    else if(dag[root].size() == 0)return rate[root];
    else {
        int case1,case2 = 0;
        case1 = rate[root];
        foreach(v, dag[root]){
            case2 += sol(*v);
            foreach(gv, dag[*v]){
                case1 += sol(*gv);
            }
        }
        memo[root] = maX(case1, case2);
    }
    return memo[root];
}



int solve(int root, int edges){
    forall(i, 0, edges){
        memo[i] = -INF;
    }
    
    return sol(root);
}

int main(){
    int m,n,u,v;
    fs(n);
    forall(i, 0, n){
        fs(rate[i]);
    }
    fs(m);
    forall(i, 0, m){
        fs(u);fs(v);
        dag[u].pb(v);
    }
    fs(u); //root
    printf("%d\n",solve(u,n));
    return 0;    
}
/************
 * Test case
 * 15
 * 5 5 3 4 11 4 5 8 8 5 6 1 5 7 6
 * 14
 * 0 1
 * 0 2
 * 1 3
 * 1 4
 * 2 5
 * 2 6
 * 3 7
 * 3 8
 * 4 9
 * 4 10
 * 5 11
 * 5 12
 * 6 13
 * 6 14
 * 0
 * 
 * output = 54
 */

