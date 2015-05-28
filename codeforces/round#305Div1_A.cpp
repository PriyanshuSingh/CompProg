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

int H1,A1,X1,Y1,H2,A2,X2,Y2,M;
int pos1,rep1,pos2;
bool flag;
ll ans;
int ex(){
    printf("-1\n");
    return 0;
}
int main(){
    s(M);
    s(H1);s(A1);s(X1);s(Y1);
    s(H2);s(A2);s(X2);s(Y2);
    pos1 = 0;
    while(pos1<=M && H1 != A1){
        H1 = (1LL*H1*X1+Y1)%M;
        //trace1(H1)
        pos1++;
    }
    if(pos1 == M+1)return ex();
    int t = pos1;
    while(t--){
        H2=(1LL*H2*X2+Y2)%M;
        //trace1(H2)
    }
    if(H2==A2){
        ans=pos1;
        printf("%lld\n",ans);
        return 0;
    }
    rep1=1;
    H1 = (1LL*H1*X1+Y1)%M;
    while(H1 != A1 && rep1 <= M){
        H1=(1LL*H1*X1+Y1)%M;
        rep1++;
        //trace1(H1)
    }
    if(rep1 == M+1)return ex();
    int c=1,d=0;
    forall(i, 1, rep1+1){
        c = (1LL*c*X2)%M;
        d = (1LL*d*X2+Y2)%M;
    }
    int pos2 = 0;
    while(pos2<=M && H2 != A2){
        H2 = (1LL*H2*c + d)%M;
        //trace1(H2)
        pos2++;
    }
    //trace1(H2)
    if(pos2 == M+1)return ex();
    else{
        ans = 1LL*rep1*pos2 + pos1;
        printf("%lld\n",ans);
        return 0;
    }
    return 0;
}