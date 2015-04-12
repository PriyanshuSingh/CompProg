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

// _X = -x
const int _K = 0, _J = 1, _I = 2, _ONE = 3, ONE = 4, I = 5, J = 6, K = 7;

char A[10001];
int pref[10001];
int suff[10001];
int base[10001];

// mat[a][b] = quaternion product of a*b
int mat[8][8] = {
    {_ONE, _I, J, K, _K, _J, I, ONE},
    {I, _ONE, _K, J, _J, K, ONE, _I},
    {_J, K, _ONE, I, _I, ONE, _K, J},
    {K, J, I, ONE, _ONE, _I, _J, _K},
    {_K, _J, _I, _ONE, ONE, I, J, K},
    {J, _K, ONE, _I, I, _ONE, K, _J},
    {_I, ONE, K, _J, J, _K, _ONE, I},
    {ONE, I, _J, _K, K, J, _I, _ONE}
};

//pow method return a^b where b {1,2,3,4}
int qpow(int a, int b){
    if(b == 1)return a;
    else if(b == 2){
        return mat[a][a];
    }else if(b == 3){
        return mat[mat[a][a]][a];
    }else if(b == 4){
        return mat[mat[a][a]][mat[a][a]];
    }
    printf("ERROR: not suppose to come here");
    exit(1);
}

int main(){
    int t,l,tot;
    ll x;
    ll imin,kmax;
    s(t);
    forall(i, 1, t+1){
        s(l);sl(x);
        ss(A);
        int pro = ONE;
        forall(j, 0, l){
            if(A[j] == 'i')base[j] = I;
            else if(A[j] == 'j')base[j] = J;
            else if(A[j] == 'k')base[j] = K;
            pro = mat[pro][base[j]];
            pref[j] = pro;
        }
        // as we know string should be partitioned in three parts so that it parts
        // into i j k, that means the ans string should have total product equal to -1 (ijk = -1)
        // x % 4 == 0 any quaternion with power a multiple of 4 will become unity hence NO
        if(x % 4 == 0 || qpow(pro, x % 4) != _ONE){
            printf("Case #%d: NO\n",i);
            //trace1(i)
            continue;
        }
        tot = pro;
        pro = ONE;
        for(int j = l-1; j>=0; --j){
            pro = mat[base[j]][pro];
            suff[j] = pro;
        }
        imin = __LONG_LONG_MAX__;
        // here imin represent min prefix length such that it's total product equal to quaternion "i"
        forall(j, 0, l){
            if(pref[j] == I){
                imin = j+1;
                break;
            }else{
                if(mat[tot][pref[j]] == I){
                    if(imin > l + j + 1)imin = l + j + 1;
                }else if(mat[qpow(tot, 2)][pref[j]] == I){
                    if(imin > 2*l + j + 1)imin = 2*l + j + 1;
                }else if(mat[qpow(tot,3)][pref[j]] == I){
                    if(imin > 3*l + j + 1)imin = 3*l + j + 1;
                }
            }
        }
        
        if(imin == __LONG_LONG_MAX__ || imin > x*l){
            printf("Case #%d: NO\n",i);
            continue;
        }
        kmax = LONG_MIN;
        // here kmax represent maximum prefix length such that it's total product equal to quaternion "k"
        for(int j = l-1; j>=0; --j){
            if(suff[j] == K){
                kmax = (x-1)*l + j;
                break;
            }else{
                if(mat[suff[j]][tot] == K){
                    if(kmax < (x-2)*l + j)kmax = (x-2)*l + j;
                }else if(mat[suff[j]][qpow(tot, 2)] == K){
                    if(kmax < (x-3)*l + j)kmax = (x-3)*l + j;
                }else if(mat[suff[j]][qpow(tot, 3)] == K){
                    if(kmax < (x-4)*l + j)kmax = (x-4)*l + j;
                }
            }
        }
        
        if(kmax == LONG_MIN || kmax <= 0){
            printf("Case #%d: NO\n",i);
            continue;
        }
        // if this condition voilates then we will end up in k -j i
        if(imin < kmax){
            printf("Case #%d: YES\n",i);
            //trace2(imin, kmax)
        }else{
            printf("Case #%d: NO\n",i);
        }
    }
    return 0;
}
