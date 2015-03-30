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

/*
#define gc  getchar_unlocked

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

*/
const int maxn = 200001;
int BT[maxn][3]; // 3 fenwick trees
int fac_ans[maxn];
int a[maxn][2];

int n;

void update(int tno, int val, int index){ // tno = tree no.; val = value; index = index;
    while(index <= n){
        BT[index][tno] += val;
        index += index & -index;
        //printf("%d (%d)++\n",index,tno);
    }  
}

int get_less(int tno, int index){ // get total of no.'s less than the index
    int ret = 0;
    while(index){
        ret += BT[index][tno];
        index -= index & -index;
    }
    return ret;
}

int main(){
    int x,y,carry=0;
    s(n);
    //printf("--");
    forall(i, 1, n+1)s(a[i][0]);
    forall(i, 1, n+1)s(a[i][1]);
    fill(BT,0);
    fill(fac_ans,0);
    forall(i, 1, n+1){
        x = get_less(0, a[n-i+1][0]+1);// here this no. is never inserted so no need to do -1;
        y = get_less(1, a[n-i+1][1]+1);// same here
        fac_ans[n-i+1] = (carry + x + y) % i;
        carry = (carry + x + y >= i);
        update(0, 1, a[n-i+1][0]+1);
        update(1, 1, a[n-i+1][1]+1);
        update(2, 1, i);
    }
    forall(i, 1, n+1){
        int l = 1;
        int r = n, as = 0;
        // binary search    
        while(l <= r){
            int mid = (l+r) >> 1;
            int x = get_less(2,mid-1); // here we want to find no. less than mid 
                                       // and get_less gives no less than and equal to mid
                                       // therefore mid - 1
            if(x <= fac_ans[i]){
                as = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        printf("%d ",as-1);
        update(2, -1, as);
    }
    return 0;
}










