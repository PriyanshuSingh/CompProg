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

int cost[51][51];
bool vis[51][51];

int N;
ll myScore,Gscore;
int main(){
    s(N);
    srand(time(NULL));
    int a,b,mx=-1;
    forall(i, 0, N){
        forall(j, 0, N){
            s(cost[i][j]);
            vis[i][j] = false;
            if(i==j)vis[i][j] = true;
//            if(mx < cost[i][j] && i != j){
//                mx = cost[i][j];
//                a = i;
//                b = j;
//            }
        }
    }
    a = N-2;b=4;
//    a = rand()%N;
//    b = rand()%N;
//    while(a == b){
//        b = rand()%N;
//    }
    myScore = Gscore = 0;
    while(true){
        printf("%d %d\n",a+1,b+1);
        vis[a][b] = true;
        myScore += cost[a][b];
        fflush(stdout);
        
        s(a);s(b);
        a--;b--;
        Gscore += cost[a][b];
        vis[a][b] = true;
        mx=-1;
        int x=-1,y=-1;
        int kk = -INF;
        forall(i, 0, N){
            if(!vis[b][i]){
                int s = cost[b][i];
                int t1,t2;
                mx = -1;
                forall(j, 0, N){
                    if(!vis[i][j] && mx < cost[i][j]){
                        mx = cost[i][j];
                        t1 = i;
                        t2 = j;
                    }
                }
                if(mx == -1 && myScore > Gscore && kk < 0){
                    x = b;
                    y = i;
                    break;
                }
                if(kk < cost[b][i] - cost[t1][t2]){
                    kk = cost[b][i] - cost[t1][t2];
                    x = b;
                    y = i;
                }
            }
        }
        if(x == -1 || y == -1){
            break;
        }else{
            a = x;
            b = y;
        }
    }
    return 0;
}