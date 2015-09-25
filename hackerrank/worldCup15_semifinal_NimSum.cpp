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
#define _FLINE_                        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__)
#define trace1(x)                    _FLINE_;cerr << #x << "=" << x << endl;
#define trace2(x, y)                 _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << endl;
#define trace3(x, y, z)              _FLINE_;cerr << #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << endl;
#define trace4(a, b, c, d)           _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << endl;
#define trace5(a, b, c, d, e)        _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << endl;
#define trace6(a, b, c, d, e, f)     _FLINE_;cerr << #a << "=" << a << " | " << #b << "=" << b << " | " << #c << "=" << c << " | " << #d << "=" << d << " | " << #e << "=" << e << " | " << #f << "=" << f << endl;
#else
#define _FLINE_
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

template<typename T> 
inline T gcD(T a,T b){
    if(a < b)swap(a,b);
    while(b){  a = a % b;b ^= a;a ^= b;b ^= a; };
    return a;
}
int N;
int A[40];
vi l,r;
int trie[1234567][2];
int data[1234567][2];
int t=1;
void addTrie(int a){
    trie[t][0]=-1;trie[t][1]=-1;
    int j=0;
    int b=0;
    int pr = 0;
    forall(i, 0, 32){
        b=checkbit(a, i);
        pr = j;
        if(trie[j][b]!=-1)j=trie[j][b];
        else{
            trie[t][0]=trie[t][1]=-1;
            trie[j][b]=t++;
            data[j][b]=0;
            j=trie[j][b];
        }
    }
    data[pr][b]++;
}

int findTrie(int a){
    int j=0;
    int b=0;
    int pr=0;
    forall(i, 0, 32){
        pr = j;
        b=checkbit(a, i);
        //trace3(a, i, data[j][b]);
        if(trie[j][b]!=-1)j=trie[j][b];
        else return 0;
    }
    return data[pr][b];
}


int brute(int st, int en, bool add, ll &ans, int offs){
    int c=0;
    if(en < st)return 0;
    int p = (1<<(en-st));
    forall(i, 0, p){
        int a=offs;
        int t=A[st];
        for(int j=0; j<en-st;j++){
            if(checkbit(i, j))t+=A[j+st+1];
            else {
                a ^= t;
                t = A[j+st+1];
            }
        }
        a ^= t;
        if(add)addTrie(a);
        else{
            ans += findTrie(a);
        }
        if(a==0)c++;
    }
    return c;
}
void initTrie(){
    t=1;
    trie[0][0]=trie[0][1]=-1;
}
int main(){
    s(N);
    forall(i, 0, N)s(A[i]);
    ll ans=0;
    if(N<=0)printf("%d",brute(0, N-1, true, ans, 0));
    else{
        int st=0,m=N/2,en=N-1;
        ans = 0;
        initTrie();
        brute(st, m, true, ans, 0);
        brute(m+1, en, false, ans, 0);
        int sm=0;
        for(int i=m; i>=0; i--){
            sm += A[i];
            int rsm=0;
            for(int j=m+1; j<N; j++){
                rsm+=A[j];
                initTrie();
                if(i==0)addTrie(sm+rsm);
                brute(st, i-1, true, ans, sm+rsm);
                brute(j+1, en, false, ans, 0);
                if(j==N-1)ans+=findTrie(0);
            }
        }
        printf("%lld",ans);
    }
}