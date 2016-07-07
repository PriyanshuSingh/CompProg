#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
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

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
// datatypes
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define gc  getchar_unlocked

using namespace std;

int brr[20];
int c;
pair<int, int> mi,ma;

int foo(ll a, int arr[]){

    if(a == 0) {
        arr[0] = 0;
        return 1;        
    }
    c = 0;
    while(a%10 != 0 || a/10 !=0) {
        brr[c] = a % 10;
        c++;
        a = a/10;
    }
    forall(i, 0, c) {
        arr[i] = brr[c - 1 - i];
    }
    return c;
}

ll conv(int arr[], int len) {
    ll n = 0;
    forall(i, 0, len) {
        //printf("##%d\n",arr[i]);
        n = n*10 + arr[i];        
    }
    return n;
}

void swap(int arr[], int i, int j) {
    if (i == j && i == -1) {
        return;
    }
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    ll n,a;
    int len;
    int arr[11];
    bool min_changed,max_changed;
    int s,b,sindex,bindex;
    scanf("%lld",&n);

    forall(k, 1, n+1) {
        ma.first = -1;
        ma.second = -1;
        mi.first = -1;
        mi.second = -1;

        scanf("%lld",&a);
        len = foo(a,arr);
        min_changed = false;
        max_changed = false;
        
        for(int i=0; i<len && (!max_changed || !min_changed); i++) {
            s = arr[i];
            b = arr[i];
            forall(j, i+1, len){
                if(!min_changed && arr[j] <= s && (arr[j] != 0 || i != 0) && arr[i] != arr[j]) {
                    s = arr[j];
                    sindex = j;
                }
                
                if(!max_changed && arr[j] >= b && arr[i] != arr[j]) {
                    
                    b = arr[j];
                    bindex = j;
                    
                }
            }
            if(s != arr[i] ){
                min_changed = true;
                mi.first = i;
                mi.second = sindex;
            }
            if(b != arr[i]) {
                max_changed = true;
                ma.first = i;
                ma.second = bindex;
            }

        }
        printf("Case #%d: ",k);
        swap(arr, mi.first, mi.second);
        printf("%lld ",conv(arr, len));
        swap(arr, mi.first, mi.second);
        swap(arr, ma.first, ma.second);
        
        printf("%lld\n",conv(arr, len));
    }
    return 0;
}

