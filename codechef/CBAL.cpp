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

const int BITMASKLEN = 1<<26;
const int MAXN = 1e5 + 10;

bool iseven[MAXN][29];

int nearest[MAXN];
ll query[MAXN][3];
ll queryAns;
//ll ansF[MAXN][3];
//ll ansR[MAXN][3];
//ll limF[MAXN][3];
//ll limR[MAXN][3];
int ju[BITMASKLEN];
int minBal;
int T,X,Y,N;
char str[MAXN];

void flushJu(){
    int x = (1<<26)-1;
    ju[x] = -1;
    forall(i, 0, N){
        x = 0;
        forall(j, 'a', 'z'+1){
            if(iseven[i][j-'a'])x += 1<<(j-'a');
            iseven[i][j-'a'] = true;
        }
        ju[x] = -1;        
    }
}

void buildReverseAns(){
    int x = 0;
    forall(j, 'a', 'z'+1){
        if(str[0] == j){
            iseven[0][j-'a'] = false;
        }
        else{
            x += 1<<(j-'a');
            iseven[0][j-'a'] = true;
        }
    }
    ju[x] = 0;
    forall(i, 1, N){
        x = 0;
        forall(j, 'a', 'z'+1){
            if(str[i] == j){
                iseven[i][j-'a'] = !iseven[i-1][j-'a'];
            }else{
                iseven[i][j-'a'] = iseven[i-1][j-'a'];
            }
            if(iseven[i][j-'a'])x+=1<<(j-'a');
        }
        if(ju[x] != -1 || x == (1<<26)-1){
            minBal = ju[x]+1;
            ju[x] = i;
        }else{
            minBal = -1;
            ju[x] = i;    
        }
        nearest[i] = minBal;
//        ansR[i][0] = ansR[i-1][0] + ans[i][0];
//        ansR[i][1] = ansR[i-1][1] + ans[i][1];
//        ansR[i][2] = ansR[i-1][2] + ans[i][2];
    }
//    limF[N-1][0] = ans[N-1][0];
//    limF[N-1][1] = ans[N-1][1];
//    limF[N-1][2] = ans[N-1][2];
//    for(int i = N-2; i>= 0; i--){
//        limF[i][0] = limF[i+1][0] + ans[i][0];
//        limF[i][1] = limF[i+1][1] + ans[i][1];
//        limF[i][2] = limF[i+1][2] + ans[i][2]; 
//    }
    flushJu();       
}

//void buildForwardAns(){
//    int x = 0;
//    int n = N;
//    forall(j, 'a', 'z'+1){
//        if(str[n-1] == j){
//            iseven[n-1][j-'a'] = false;
//        }
//        else{
//            x += 1<<(j-'a');
//            iseven[n-1][j-'a'] = true;
//        }
//    }
//    ju[x] = n-1;
//    ans[n-1][0] = 0;
//    ans[n-1][1] = 0;
//    ans[n-1][2] = 0;
//    for(int i = n-2; i >= 0; i--){
//        x = 0;
//        forall(j, 'a', 'z'+1){
//            if(str[i] == j){
//                iseven[i][j-'a'] = !iseven[i+1][j-'a'];
//            }else{
//                iseven[i][j-'a'] = iseven[i+1][j-'a'];
//            }
//            if(iseven[i][j-'a'])x+=1<<(j-'a');
//        }
//        if(ju[x] != -1){
//            minBal = ju[x]-1;
//            ju[x] = i;
//            int len = minBal - i + 1;
//            ans[i][0] = 1 + ans[minBal+1][0];
//            ans[i][1] = (ans[minBal+1][0] + 1) * len + ans[minBal+1][1];
//            ans[i][2] = ans[minBal+1][2] + len * len * ans[i][0] + 2 * ans[minBal+1][1] * len ;
//        }else if(x == (1<<26) - 1){
//            minBal = n-1;
//            int len = minBal - i + 1;
//            ans[i][0] = 1;
//            ans[i][1] = len;
//            ans[i][2] = len*len;
//            ju[x] = i;    
//        }else{
//            minBal = -1;
//            ju[x] = i;
//            ans[i][0] = 0;
//            ans[i][1] = 0;
//            ans[i][2] = 0;    
//        }
//        ansF[i][0] = ansF[i+1][0] + ans[i][0];
//        ansF[i][1] = ansF[i+1][1] + ans[i][1];
//        ansF[i][2] = ansF[i+1][2] + ans[i][2];    
//    }
//    limR[0][0] = ans[0][0];
//    limR[0][1] = ans[0][1];
//    limR[0][2] = ans[0][2];
//    for(int i = 1; i < N; i++){
//        limR[i][0] = limR[i-1][0] + ans[i][0];
//        limR[i][1] = limR[i-1][1] + ans[i][1];
//        limR[i][2] = limR[i-1][2] + ans[i][2];
//    }
//    flushJu();           
//}

int main(){
    int Q;
    ll L,R,A,B,X,Y;
    int type;
    s(T);
    fill(ju,-1);
    while(T--){
        ss(str);
        N = strlen(str);
        buildReverseAns();
        s(Q);
        A = 0;B=0;
        while(Q--){
            sl(X);sl(Y);s(type);
            L = (X + A) % N + 1;
            R = (Y + B) % N + 1;
            queryAns=0;
            query[L-1][0] = 0;
            query[L-1][1] = 0;
            query[L-1][2] = 0;
            
            //trace2(L, R)
            forall(i, L, R){
                //trace3(L-1, i,nearest[i])
                if(nearest[i] < L-1){
                    query[i][0] = 0;
                    query[i][1] = 0;
                    query[i][2] = 0;
                }else if(nearest[i] == L-1){
                    int len = i - nearest[i] + 1;
                    query[i][0] = 1;
                    query[i][1] = len;
                    query[i][2] = len*len;
                }else{
                    int len = i - nearest[i] + 1;
                    query[i][0] = 1 + query[nearest[i]-1][0];
                    query[i][1] = (query[nearest[i]-1][0] + 1) * len + query[nearest[i]-1][1];
                    query[i][2] = query[nearest[i]-1][2] + (len * len * query[i][0]) + (2 * query[nearest[i]-1][1] * len);
                    //trace5(query[nearest[i]-1][2],(len * len * query[i][0]),len,(2 * ans[nearest[i]-1][1] * len),i)
                    //trace4(query[i][0], query[i][1], query[i][2],i);
                }
                queryAns += query[i][type];
                //trace1(query[i][type])
            }
            printf("%lld\n",queryAns);
            A = B;
            B = queryAns;
        }
    }
}