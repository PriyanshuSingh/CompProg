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

int B[19][19];
int N;
const int MAXN = 2e6;
int trie[MAXN][2];
int word[MAXN];
vi a[19];
vi b[19];
int main(){
    s(N);
    forall(i, 0, N)forall(j, 0, N)s(B[i][j]);
    int powerset = 1<<(N-1);
    forall(i, 0, powerset){
        int x=0,y=0,xr=B[0][0];
        forall(j, 0, N-1){
            if(checkbit(i, j)){
                x++;
            }else{
                y++;
            }
            xr ^= B[x][y];
        }
        a[x].pb(xr);
    }
    forall(i, 0, powerset){
        int x=N-1,y=N-1,xr=B[N-1][N-1];
        forall(j, 0, N-1){
            if(checkbit(i, j)){
                x--;
            }else{
                y--;
            }
            xr ^= B[x][y];
        }
        b[x].pb(xr^B[x][y]);
    }
    int ans = 0;
    forall(i, 0, N){
        int as = a[i].size();
        int bs = b[i].size();
        trie[0][0]=trie[0][1]=-1;
        int c = 0;
        forall(j, 0, as){
            int ptr = 0;
            for(int k = 30; k>=0; k--){
                int bit = checkbit(a[i][j], k);
                if(trie[ptr][bit] == -1){
                    c++;
                    trie[ptr][bit] = c;
                    trie[c][0] = trie[c][1] = -1;
                }
                ptr = trie[ptr][bit];
            }
            word[ptr] = a[i][j];
        }
        forall(j, 0, bs){
            int ptr = 0;
            for(int k=30;k>=0;k--){
                int bit = (checkbit(b[i][j], k))?0:1;
                if(trie[ptr][bit]==-1)bit ^= 1;
                ptr = trie[ptr][bit];
            }
            int l = word[ptr]^b[i][j];
            if(ans<l)ans=l;
        }
    }
    printf("%d\n",ans);
}