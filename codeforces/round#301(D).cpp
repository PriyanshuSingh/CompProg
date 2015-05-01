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

const int MAXN = 101;
const int ROCK = 1, PAPER = 2, SCISSOR = 3;
double memo[MAXN][MAXN][MAXN];
int RK,SC,PP;
void flush(){
    forall(i, 0, MAXN){
        forall(j, 0, MAXN){
            forall(k, 0, MAXN){
                memo[i][j][k] = -1;
            }
        }
    }
}
double prb(int rk, int sr, int pp,const int A, const int B){
    double n = rk + sr + pp, k;
    n = (n * (n-1))/2;
    if(A == ROCK && B == SCISSOR){
        k = rk * sr; 
    }else if(A == PAPER && B == ROCK){
        k = pp * rk;
    }else if(A == SCISSOR && B == PAPER){
        k = sr * pp;
    }
    return k/n;
}
double DP(int rock, int papr, int scis, const int A){
    if(memo[rock][papr][scis] >= 0)return memo[rock][papr][scis];
    else if(A == ROCK){
        if(rock == 0)return memo[rock][papr][scis] = 0;
        else if(papr == 0)return memo[rock][papr][scis] = 1.0; 
    }else if(A == PAPER){
        if(papr == 0)return memo[rock][papr][scis] = 0;
        else if(scis == 0)return memo[rock][papr][scis] = 1.0;
    }else if(A == SCISSOR){
        if(scis == 0)return memo[rock][papr][scis] = 0;
        else if(rock == 0)return memo[rock][papr][scis] = 1.0;
    }
    /*
     * NOTE: In cases below(where either rock or papr or scissor is zero) both side same probability is multiplied
     *       hence, no prb is multiplied either side
     */
    if(rock == 0){
        memo[rock][papr][scis] = DP(rock,papr-1,scis,A);
    }else if(scis == 0){
        memo[rock][papr][scis] = DP(rock-1,papr,scis,A);
    }else if(papr == 0){
        memo[rock][papr][scis] = DP(rock,papr,scis-1,A);
    }else{
        /* DP[r][p][s] = prb(papr,rock) * DP[r-1][p][s] + prb(rock,scis) * DP[r][p][s-1] 
         *               + prb(scis,papr) * DP[r][p][s-1] + prb(2 selected people belong to same group) * DP[r][p][s];
         * therefore we have equation->
         * (1 - prb(2 people frm same grp)) * DP[r][p][s] = prb(papr,rock) * DP[r-1][p][s] + prb(rock,scis) * DP[r][p][s-1]
         *                                                  + prb(scis,papr) * DP[r][p][s-1];
         */ 
        memo[rock][papr][scis] = (prb(rock,scis,papr,PAPER,ROCK) * DP(rock-1,papr,scis,A) + prb(rock,scis,papr,SCISSOR,PAPER) * DP(rock,papr-1,scis,A) + prb(rock,scis,papr,ROCK,SCISSOR) * DP(rock,papr,scis-1,A)) / (prb(rock,scis,papr,PAPER,ROCK) + prb(rock,scis,papr,SCISSOR,PAPER) +  prb(rock,scis,papr,ROCK,SCISSOR));
    }
    return memo[rock][papr][scis];
}

int main(){
    s(RK);s(SC);s(PP);
    double rock,scis,papr;
    flush();
    rock = DP(RK,PP,SC,ROCK);
    flush();
    papr = DP(RK,PP,SC,PAPER);
    flush();
    scis = DP(RK,PP,SC,SCISSOR);
    printf("%.12g %.12g %.12g",rock,scis,papr);
    return 0;
}

