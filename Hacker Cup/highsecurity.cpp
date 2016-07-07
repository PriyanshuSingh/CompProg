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
#define pi(a)                       printf("%d", a)
#define pl(a)                       printf("%lld", a)
#define pn                          printf("\n")

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
#define checkbit(n,b)                ( ((n) >> (b)) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define DEBUG

// debugging

#ifdef DEBUG
#define METHOD_NAME                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);
#define trace1(x)                    cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << endl;
#define trace2(x, y)                 cerr<<"(" << __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              cerr<<"("<< __LINE__ <<"): "<< #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     cerr<<"(" << __LINE__ <<"): "<< #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define METHOD_NAME
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

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){s<<"[";forall(i,0,sz(t)-1)s<<t[i]<<", ";s<<t[sz(t)-1]<<"]";return s; }

const int MOD = 1e9+7;

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}

template<typename T>
inline T pow_mod(T a, T b) {
    T res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

char pttn[2][1010];
int ps(pii a){
    return a.S-a.F+1;
}
vpii path[2];
int main(){
    int T;s(T);
    forall(t, 1, T+1){
        int N;s(N);
        ss(pttn[0]);ss(pttn[1]);
        
        forall(k, 0, 2){
            path[k].clear();
            int l=-1,r=-1;
            forall(i, 0, N){
                if(l==-1 && pttn[k][i] == '.'){
                    l=i;r=i;
                }
                if(l!=-1){
                    if(pttn[k][i] == '.'){
                        r=i;
                    }else{
                        path[k].pb(mp(l,r));
                        l=-1;
                        r=-1;
                    }
                }
            }
            if(l!=-1){
                path[k].pb(mp(l,r));
                l=-1;
                r=-1;
            }
        }
        int ans=0;
        int i0,i1;
        for(i0 = 0,i1=0; i0<path[0].size() && i1<path[1].size() ;){
            //both starting position is same
            if(path[0][i0].F == path[1][i1].F){
                // if both have same size
                if(ps(path[0][i0]) == ps(path[1][i1])){
                    if(ps(path[0][i0]) == 1)ans+=1;
                    else ans+=2;
                    i0++;i1++;
                }
                //if 0th have more size than 1th. (iterate on 1th)
                // see how many more than two and one.
                // one - 1
                else if(ps(path[0][i0]) > ps(path[1][i1])){
                    int twm = 0, one=0;
                    while(i1 < path[1].size() && path[1][i1].S <= path[0][i0].S){
                        if(ps(path[1][i1]) == 1)one++;
                        else twm++;
                        i1++;
                    }
                    if(one == 0)ans++;
                    ans+=twm+one;
                    i0++;
                }
                // if 1th have more size than 0th. iterate on 0th.
                else{
                    int twm = 0, one = 0;
                    while(i0 < path[0].size() && path[0][i0].S <= path[1][i1].S){
                        if(ps(path[0][i0]) == 1)one++;
                        else twm++;
                        i0++;
                    }
                    if(one == 0)ans++;
                    ans+=twm+one;
                    i1++;
                }
            // if 0th is before 1th    
            }else if(path[0][i0].F < path[1][i1].F){
                int twm = 0, one=0;
                while(i1 < path[1].size() && path[1][i1].S <= path[0][i0].S){
                    if(ps(path[1][i1]) == 1)one++;
                    else twm++;
                    i1++;
                }
                if(one == 0)ans++;
                ans+=twm+one;
                i0++;
            }
            //if 1th is before 0th.
            else{
                int twm = 0, one = 0;
                while(i0 < path[0].size() && path[0][i0].S <= path[1][i1].S){
                    if(ps(path[0][i0]) == 1)one++;
                    else twm++;
                    i0++;
                }
                if(one == 0)ans++;
                ans+=twm+one;
                i1++;
            }
        }
        while(i0 < path[0].size()){ans++;i0++;}
        while(i1 < path[1].size()){ans++;i1++;}
        printf("Case #%d: %d\n",t,ans);
    }

}