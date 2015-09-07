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

pii slope[2010][2010];
pii pt[2010];
int g[2010][2010];
int N;
int m[2010];

inline int eql(pii a,pii b){
    return (a.F == b.F && a.S == b.S);
}

inline ll nc3(int n){
    ll ans = n;
    ans *=n-1;
    ans /=2;
    ans *= n-2;
    ans /= 3;
    return ans;
}
int main(){
    //printf("%d",gcd(0,2));
    //printf("%lld\n",nc3(2000));
    s(N);
    fill(m,0);
    forall(i, 0, N){
        int x,y;
        s(x);s(y);
        pt[i] = mp(x,y);
    }
    forall(i, 0, N){
        forall(j, i+1, N){
            int xx = pt[i].F - pt[j].F;
            int yy = pt[i].S - pt[j].S;
            if(yy == 0)swap(yy, xx);
            int g = gcd(xx,yy);
            slope[i][j] = mp(xx/g,yy/g);
            slope[j][i] = mp(xx/g,yy/g);
        }
        slope[i][i] = mp(0,0);
        
    }
    forall(i, 0, N){
        sort(slope[i], slope[i]+N);
        int c=1;
        pii prev = slope[i][0];
        forall(j, 1, N){
            if(eql(prev, slope[i][j]))c++;
            else{
                m[c]++;
                c=1;
                prev = slope[i][j];
            }
        }
        m[c]++;
    }
    ll ans = nc3(N);
    forall(i, 2, 2001){
        trace2(m[i],i);
        m[i]/=(i+1);
        trace2(m[i],nc3(i+1)*m[i]);
        ans -= nc3(i+1)*m[i];
    }
    printf("%lld",ans);
}