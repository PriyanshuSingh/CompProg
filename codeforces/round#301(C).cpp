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

const int MAXN = 510;
int gm[MAXN][MAXN];
bool vis[MAXN][MAXN];
char A[MAXN];
queue< pii > Q;
int main(){
    int n,m,r1,c1,r2,c2;
    fill(gm,0);
    fill(vis,0);
    s(n);s(m);
    forall(i, 1, n+1){
        ss(A);
        forall(j, 0, m){
            if(A[j] == '.'){
                gm[i][j+1] = 1;            
            }
        }
    }
    s(r1);s(c1);s(r2);s(c2);
    if(r1 == r2 && c1 == c2){
        int count = 0;
        forall(i, 0, 4){
            int xx = r1 + fx[i][0];
            int yy = c1 + fx[i][1];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m){
                if(gm[xx][yy] == 1)count++;
            }
        }
        if(count > 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        return 0;
    }else{
        forall(i, 0, 4){
            int xx = r1 + fx[i][0];
            int yy = c1 + fx[i][1];
            if(xx == r2  && yy == c2){
                if(gm[xx][yy] == 0){
                    printf("YES\n");
                    return 0;
                }else{
                    forall(i, 0, 4){
                        int x = xx + fx[i][0];
                        int y = yy + fx[i][1];
                        if(gm[x][y] == 1){
                            printf("YES\n");
                            return 0;
                        }
                    }
                }
                printf("NO\n");
                return 0;
            }
        }
    }
    Q.push(mp(r1,c1));
    while(!Q.empty()){
        pii top = Q.front();
        Q.pop();
        if(vis[top.F][top.S] == false){
            vis[top.F][top.S] = true;
            if((top.F != r1 || top.S != c1) && gm[top.F][top.S] == 0)continue;
            forall(i, 0, 4){
                int xx = top.F + fx[i][0];
                int yy = top.S + fx[i][1];
                if(xx >= 1 && xx <= n && yy>=1 && yy <= m){
                    if(vis[xx][yy] == false)Q.push(mp(xx,yy));
                }
            }
       }
    }
    if(vis[r2][c2] && gm[r2][c2] == 1){
        int count = 0;
        forall(i, 0, 4){
            int xx = r2 + fx[i][0];
            int yy = c2 + fx[i][1];
            if(xx>=1 && xx <= n && yy >= 1 && yy <= m){
                if(gm[xx][yy] == 1){
                    count++;
                }
            }
        }
        if(count > 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }else if(vis[r2][c2]){
        printf("YES\n");
    }else{
        printf("No\n");
    }
//    forall(i, 1, n+1){
//        forall(j, 1, m+1){
//            printf("%d ",gm[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//    forall(i, 1, n+1){
//        forall(j, 1, m+1){
//            printf("%d ",vis[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}