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
#ifdef LOCAL
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

int MOD = 1e9 + 7;
const int MAXN = 1e5+10;


int st[4*MAXN];
int add[4*MAXN];
int mul[4*MAXN];
int paste[4*MAXN];
int qt[4*MAXN];
int A[MAXN];
int N,Q,type,v;

inline int modd(int a){
    return (a >= MOD)?a-MOD:a;
}

void make_st(int curr, int start, int end){
    add[curr] = mul[curr] = paste[curr] = 0;
    if(start == end){
        st[curr] = A[start];
        return;
    }
    int mid = (start + end) >> 1;
    int c1 = curr << 1, c2 = c1 | 1;
    make_st(c1, start, mid);
    make_st(c2, mid+1, end);
    st[curr] = modd(st[c1] + st[c2]);
}

inline void lazy(int curr, int s, int e){
    int len = e - s + 1;
    int c1 = curr << 1, c2 = c1 | 1;
    // LAZY UPDATE START
    if(paste[curr] != 0){
        st[curr] = (1LL*len*paste[curr]) % MOD;
        if(s != e){
            add[c1] = add[c2] = 0;
            mul[c1] = mul[c2] = 0;
            paste[c1] = paste[c2] = paste[curr];
        }
    }
    if(mul[curr] != 0){
        st[curr] = (1LL*mul[curr]*st[curr]) % MOD;
        if(s != e){
            mul[c1] = (mul[c1]!=0)?(1LL*mul[c1]*mul[curr])%MOD:mul[curr];
            mul[c2] = (mul[c2]!=0)?(1LL*mul[c2]*mul[curr])%MOD:mul[curr];
            add[c1] = (1LL*mul[curr]*add[c1])%MOD;
            add[c2] = (1LL*mul[curr]*add[c2])%MOD;
        }
    }
    if(add[curr] != 0){
        st[curr] = modd(((1LL*len*add[curr]) % MOD) + st[curr]);
        if(s != e){
            add[c1] = modd(add[c1] + add[curr]);
            add[c2] = modd(add[c2] + add[curr]);
        }
    }
    add[curr] = mul[curr] = paste[curr] = 0;
    // LAZY UPDATE END
}

void update_st(int curr, int s, int e, int St, int En){
    //trace2("UPDATE", curr);
    lazy(curr,s,e);
    if(En < s || St > e){
        return;
    }
    else if(St <= s && e <= En){
        if(type == 1){
            add[curr] = v;
        }else if(type == 2){
            mul[curr] = v;
        }else if(type == 3){
            paste[curr] = v;
        }
        lazy(curr,s,e);
    }else{
        int mid = (s+e)>>1;
        int c1 = curr << 1, c2 = c1 | 1;
        update_st(c1, s, mid, St, En);
        update_st(c2, mid+1, e, St, En);
        st[curr] = modd(st[c1] + st[c2]);
    }
    return;
}

void query(int curr, int s, int e, int St, int En){
    lazy(curr, s, e);
    //trace2("QUERY", curr);
    if(En < s || e < St)qt[curr] = 0;
    else if(St <= s && e <= En){
        qt[curr] = st[curr];
        if(qt[curr] < 0)trace1(curr)
    }else{
        int mid = (s+e)>>1;
        int c1 = curr << 1, c2 = c1 | 1;
        query(c1, s, mid, St, En);
        query(c2, mid+1, e, St, En);
        qt[curr] = modd(qt[c1] + qt[c2]);
    }
    
}

int main(){
    s(N);s(Q);
    forall(i, 0, N){
        s(A[i]);
    }
    make_st(1, 0, N-1);
    while(Q--){
        int x,y;
        s(type);s(x);s(y);
        x--;y--;
        //trace3(type, x, y)
        if(type == 4){
            query(1, 0, N-1, x, y);
            printf("%d\n",qt[1]);
        }else{
            s(v);
            //trace1(v)
            update_st(1, 0, N-1, x, y);
        }
    }
}

//int main(){
//    srand(time(NULL));
//    trace1("TEST");
//    int a[10000];
//    int n = 1e4;
//    int q = 10;
//    printf("%d %d\n",n,q);
//    forall(i, 0, n){
//        a[i] = rand()%5 + 1;
//        A[i] = a[i];
//    }
//    make_st(1, 0, n-1);
//    printf("\n");
//    while(q--){
//        int x,y;
//        type = rand()%4 + 1;
//        x = rand()%1000 + 1;
//        y = rand()%5000 + 3000;
//        v = rand()%MOD;
//        if(type == 4){
//            printf("%d %d %d\n",type,x,y);
//            x--;y--;
//            int sum = 0;
//            forall(i, x, y+1){
//                sum = modd(sum + a[i]);
//            }
//            query(1, 0, n-1, x, y);
//            if(sum == qt[1]){
//                trace1("TEST PASSED");
//            }
//            else{
//                trace1("TEST FAILED");
//               trace2(sum,qt[1])
//               exit(0);
//            }
//        }else{
//            printf("%d %d %d %d\n",type,x,y,v);
//            x--;y--;
//            if(type == 1){
//                forall(i, x, y+1){
//                    a[i] = modd(a[i] + v);
//                }
//            }else if(type == 2){
//                forall(i, x, y+1){
//                    a[i] = (1LL*a[i]*v)%MOD;
//                }
//            }else if(type == 3){
//                forall(i, x, y+1){
//                    a[i] = v;
//                }
//            }
//            update_st(1, 0, n-1, x, y);
//        }
//    }
//    return 0;
//}