/************************************************************
 * Author: Priyanshu Singh
 * Handle: tgamerz
 *
 * Planning an investment strategy
 * Problem: Your knowledge of algorithms helps you obtain an exciting job with the Acme Computer Company, along with a $10,000 signing bonus. 
 * You decide to invest this money with the goal of maximizing your return at the end of 10 years. 
 * You decide to use the Amalgamated Investment Company to manage your investments. Amalgamated Investments requires you to observe the following rules. 
 * It offers n different investments, numbered 1 through n. In each year j , investment i provides a return rate of rij . In other words, 
 * if you invest d dollars in investment i in year j , then at the end of year j, you have drij dollars. The return rates are guaranteed, that is, 
 * you are given all the return rates for the next 10 years for each investment. You make investment decisions only once per year. At the end of each year, 
 * you can leave the money made in the previous year in the same investments, or you can shift money to other investments, by either shifting money between 
 * existing investments or moving money to a new investement. If you do not move your money between two consecutive years, you pay a fee of f1 dollars, whereas 
 * if you switch your money, you pay a fee of f2 dollars, where f2 > f1.
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

float rate[1000][1000];
float memo[1000][1000];

float solve(int n, int m, float f1, float f2, float amt){
    float max_return;
    forall(i, 0, n){
        forall(j, 0, m){
            memo[i][j] = -INF;
        }
    }
    forall(i, 0, n){
        memo[i][0] = amt * rate[i][0];
    }
    forall(j, 0, m-1){
        forall(i, 0, n){
            forall(k, 0, n){
                if(k == i){
                    memo[k][j+1] = maX(memo[k][j+1], memo[i][j] * rate[k][j+1] - f1);
                }else{
                    memo[k][j+1] = maX(memo[k][j+1], memo[i][j] * rate[k][j+1] - f2);
                }
            }
        }
    } 
    max_return = -INF;
    forall(i, 0, n){
        max_return = maX(max_return, memo[i][m-1]);
    }
    return max_return;
}

int main(){
    int n,m;
    float f1,f2,amt;
    fs(n);fs(m);
    // n rates m years
    forall(i, 0, n){
        forall(j, 0, m){
            sf(rate[i][j]);
        }
    }
    sf(f1);sf(f2);sf(amt);
    printf("max return: %f\n",solve(n,m,f1,f2,amt));
//    forall(i, 0, n){
//        forall(j, 0, m){
//            printf("(%d,%d) %f ",i,j,memo[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
/****************
 * Test case
 * 3 5
 * 1.2 1.1 1.3 1.5 1.2
 * 1.9 1.01 1.1 1.3 1.1
 * 1.1 1.3 1.9 1.1 1.2
 * 10.0 20.0 1000
 * 
 * max return: 8327.000000
 *
 * memo table->
 * (0,0) 1200.000000 (0,1) 2070.000000 (0,2) 3165.000000 (0,3) 6947.500000 (0,4) 8327.000000 
 * (1,0) 1900.000000 (1,1) 1909.000000 (1,2) 2675.000000 (1,3) 6018.500000 (1,4) 7622.250000 
 * (2,0) 1100.000000 (2,1) 2450.000000 (2,2) 4645.000000 (2,3) 5099.500000 (2,4) 8317.000000  
 */