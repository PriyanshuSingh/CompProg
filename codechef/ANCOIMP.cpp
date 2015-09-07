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

const int MAXN = 1e3 + 10;
bool A[MAXN][MAXN];
bool vis[MAXN]; 
bool ans[MAXN];
bool a2[MAXN];
bool one[MAXN];
int T,N;
int z,o;
int c = 0;

void vis_flush(int i){
    if(!vis[i])return;
    else{
        vis[i] = false;
        forall(j, 0, N)if(A[i][j])vis_flush(j);
    }
}
void DFS_rev(int i){
    if(vis[i])return;
    else{
        vis[i] = true;
        ans[i] = !ans[i];
        forall(j, 0, N)if(A[i][j])DFS_rev(j);
    }
}
int DFS(int i, bool expected){
    if(vis[i]){
        if(ans[i] == expected)return 0;
        else return -1;
    }
    c++;
    vis[i] = true;
    ans[i] = expected;
    int ret = (expected)?1:0;
    forall(j, 0, N){
        if(i!=j){
            if(A[i][j]){
                int t =  DFS(j,!expected);
                if(t==-1)return -1;
                else ret += t;    
            }
        }
    }
    return ret;
}

int main(){
    int aa;
    s(T);
    while(T--){
        s(N);
        fill(one,0);
        fill(vis,0);
        bool flag = true;
        forall(i, 0, N){
            forall(j, 0, N){
                s(aa);
                if(aa==1){
                    A[i][j]=true;
                    if(i==j)flag = false;
                    one[i] = one[j] = true;
                }
                else A[i][j] = false;
            }
        }
        if(flag == false)printf("-1\n");
        else{
            forall(i, 0, N){
                if(!vis[i] && one[i]){
                    z = o = 0;
                    forall(j, 0, N){
                        if(i!=j && vis[j]){
                            if(ans[j])o++;
                            else z++;
                        }
                    }
                    int t = c;
                    int f = DFS(i, false);
                    t = c - t - f;
                    if(f == -1)flag = false;
                    else{
                        if(o > z){
                            if(t < f){
                                vis_flush(i);
                                DFS_rev(i);
                            }
                        }else{
                            if(t > f){
                                vis_flush(i);
                                DFS_rev(i);
                            }
                        }
                    }
                }
            }
            if(flag == false)printf("-1\n");
            else{
                forall(i, 0, N){
                    if(!vis[i]){
                        z = o = 0;
                        forall(j, 0, N){
                            if(i!=j && vis[j]){
                                if(ans[j])o++;
                                else z++;
                            }
                        }
                        if(o > z)ans[i] = false;
                        else ans[i] = true;
                        vis[i] = true;
                    }
                }
                forall(i,0,N){
                    printf("%d ",(ans[i])?1:0); 
                }
                printf("\n");
            }
        }
    }    
    return 0;
}