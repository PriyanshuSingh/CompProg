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

#define gc getchar_unlocked

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair< pii, int> piii;
typedef vector< piii > vpiii;
typedef pair<int, bool> pib;
typedef vector< pii > vpii;
typedef vector< pib > vpib;


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

const int MAXN = 1e5+10;
int const MAXK = 510;
//int st[4*MAXN];
int A[MAXN];
int w[MAXN];
ll memo[MAXN][MAXK];
int N,M,K;

//void update(int cur, int s, int e, int St, int En, int val){
//    if(En < s || e < St)return;
//    else if(St<=s && e<=En){
//        st[cur] = miN(st[cur], val);
//    }else{
//        update(cur<<1, s, (s+e)>>1, St, En, val);
//        update((cur<<1)+1, ((s+e)>>1)+1, e, St, En, val);
//    }
//}
//
//void push_st(int cur, int s, int e){
//    if(s==e){
//        w[s] = st[cur];
//        st[cur] = INF;
//    }else{
//        int c1 = cur<<1,c2 = c1 | 1;
//        int mid = (s+e)>>1;
//        st[c1] = miN(st[c1], st[cur]);
//        st[c2] = miN(st[c2], st[cur]);
//        st[cur] = INF;
//        push_st(c1, s, mid);
//        push_st(c2, mid+1, e);
//    }
//}
//
//ll DP(int i, int j){
//    //trace3(i, j, memo[i][j])
//    if(memo[i][j] != -1)return memo[i][j];
//    else if(i == 0){
//        memo[i][j] = (w[i] <= j)?A[i]:0;
//    }else{
//        memo[i][j] = maX(memo[i][j], DP(i-1,j));
//        if(w[i] <= j)memo[i][j] = maX(memo[i][j], DP(i-1,j-w[i]) + A[i]);
//    }
//    return memo[i][j];
//}

piii CC[MAXN];
bool cmp(piii a, piii b){
    return a.S < b.S;
}


int main(){
    int T;
    ll sum=0;
    s(T);
    //forall(i, 0, 4*MAXN)st[i] = INF;
    while(T--){
        sum=0;
        fs(N);fs(K);fs(M);
        forall(i, 0, N){
            fs(A[i]);
            sum+=A[i];
        }
        forall(i, 0, M){
            int L,R,C;
            fs(L);fs(R);fs(C);
            L--;R--;
            CC[i].S = C;
            CC[i].F.F = L;
            CC[i].F.S = R;
            //update(1, 0, N-1, L, R, C);
        }
        sort(CC,CC+M,cmp);
        //forall(i, 0, M)trace2(CC[i].S, i);
        int n = 0;
        forall(i, 0, N){
            w[i] = 2222;
            if(A[i] < 0){
                forall(j, 0, M){
                    //trace1(CC[j].F.F)
                    if(CC[j].F.F <= i && i <= CC[j].F.S){
                        w[i] = CC[j].S;
                        break;
                    }
                }
                if(w[i] <= K){
                    A[n] = -A[i];
                    w[n] = w[i];
                    //trace3(A[n], w[n], n)
                    n++;
                }
            }
            //trace1(w[i])
        }
        //push_st(1, 0, N-1);
        
        forall(i, 0, N){

        }
        if(n==0)printf("%lld\n",sum);
        else{
            forall(j, 0, K+1){
                memo[0][j] = (w[0]<=j)?A[0]:0;
            }
            forall(i, 1, n){
                forall(j, 0, K+1){
                    memo[i][j] = maX(memo[i-1][j], (w[i]<=j)?memo[i-1][j-w[i]]+A[i]:0);
                }
            }
            //trace1(K)
            printf("%lld\n",sum+memo[n-1][K]);
        }
    }
}