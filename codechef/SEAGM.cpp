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

//dirextion
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

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

const int MAXN = 110;
int memo[MAXN][MAXN];
float nemo[MAXN][MAXN];
int total[MAXN];
int N,T,A[MAXN];

bool opDP(int g,int taken){
    if(memo[g][taken] == 0 || memo[g][taken] == 1)return memo[g][taken];
    else if(g==1){
        return memo[g][taken] = 1;
    }else if(taken == N){
        return memo[g][taken] = 0;
    }else{
        int ans = 0;
        if(total[g] > taken){
            ans = (opDP(g, taken+1) == 0 || ans == 1)?1:0;
        }
        forall(i, 0, N){
            int f = gcd(g,A[i]);
            if(f != g){
                ans = (opDP(f,taken+1) == 0 || ans == 1)?1:0;
            }
        }
        return memo[g][taken] = ans;
    }
}

float raDP(int g, int taken){
    if(nemo[g][taken] >= 0)return nemo[g][taken];
    else if(g==1){
        return nemo[g][taken] = 1.00;
    }else if(taken == N){
        return nemo[g][taken] = 0.00;
    }else{
        float ans=0.00;
        if(total[g] > taken){
            ans += (1 - raDP(g,taken+1)) * (total[g] - taken);
        }
        forall(i, 0, N){
            int f = gcd(g,A[i]);
            if(f != g){
                ans += (1 - raDP(f, taken +1));
            }
        }
        ans /= N-taken;
        return nemo[g][taken] = ans;
    }
}

int main(){
    s(T);
    while (T--){
        s(N);
        fill(total, 0);
        forall(i, 0, N){
            s(A[i]);
            forall(j, 1, MAXN){
                if(gcd(j,A[i])==j)total[j]++;
            }
        }
        forall(i, 0, MAXN){
            forall(j, 0, MAXN){
                memo[i][j] = -1;
                nemo[i][j] = -1;
            }
        }
        printf("%d %.4f\n",opDP(0, 0), raDP(0, 0));
        
    }
    return 0;
}