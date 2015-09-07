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
const int MOD = 1e9+7;
const int MAXN = 5100;
long long fac[MAXN];
long long inv_fac[MAXN];
long long cnt[MAXN];
int suffarr[MAXN];
char str[MAXN];
int ans[MAXN];
int N,Q,K;

inline int modd(int a){
    return (a >= MOD) ? a - MOD:a;
}
bool cmp(int a,int b){
     return (strcmp(str + a, str + b) < 0) ? true : false;
}
int powMOD(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return (int)x;
}

int mod_inv(int a){
    return powMOD(a, MOD-2, MOD);
}

void fill_facs(){
    fac[0] = 1;
    forall(i, 1, MAXN)fac[i] = (1LL*fac[i-1]*i)%MOD;
    forall(i, 0, MAXN)inv_fac[i] = mod_inv(fac[i]);
}

int ncr(int n, int r){
    return ((1LL*fac[n]*inv_fac[n-r])%MOD*1LL*inv_fac[r])%MOD;
}


void lcp(){
    forall(i, 0, N)suffarr[i] = i;
    sort(suffarr, suffarr+N, cmp);
    //forall(i, 0, N)trace1(str+suffarr[i]);
    char *x,*y;
    int p[MAXN],i;
    fill(p,0);
    x = y = str;
    x = str + suffarr[0];
    for(i=0; *x; i++,x++){
        p[i] = 1;
    }
    while(i!=MAXN){
        p[i] = 0;
        i++;
    }
    //trace1(str + suffarr[0]);
    for(i = 1; i < N; i++){
        x = str + suffarr[i-1];
        y = str + suffarr[i];
        //trace1(y)
        int j = 0;
        while(*x == *y){
            p[j++]++;
            x++;y++;
        }
        while(*x && *y){
            cnt[p[j]]++;
            p[j] = 1;
            j++;x++;y++;
        }
        while(*y){
            cnt[p[j]]++;
            p[j] = 1;
            j++;y++;
        }
        while(*x){
            cnt[p[j]]++;
            p[j] = 0;
            j++;x++;
        }
    }
    x = str + suffarr[N-1];
    i = 0;
    while (*x) {
        x++;
        cnt[p[i++]]++;
    }
}

void init(){
    s(N);s(Q);
    ss(str);
    str[N]='\0';
    fill(cnt,0);
    lcp();
    fill(ans, -1);
}

int main(){
    int T;
    s(T);
    fill_facs();
    while (T--) {
        init();
        while (Q--) {
            s(K);
            if(K > N)printf("0\n");
            else if(ans[K] != -1)printf("%d\n",ans[K]);
            else if(K == 1)printf("%d\n",ans[K] = (N*(N+1) / 2));
            else{
                ans[K] = 0;
                forall(i, K, N+1){
                    ans[K] = modd(ans[K] + (ncr(i,K)*cnt[i])%MOD);
                    //trace1(ans[K])
                }
                printf("%d\n",ans[K]);
            }
        }
    }
    return 0;
}