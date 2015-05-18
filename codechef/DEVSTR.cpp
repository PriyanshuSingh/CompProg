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

const int MAXN = 1e5 + 10;

int T,n,k,flip;
char str[MAXN];

int main(){
    s(T);
    while(T--){
        s(n);s(k);
        ss(str);
        int temp;
        if(k==1){
            temp = 1;
            flip = 0;
            forall(i, 0, n){
                if(temp + '0' != str[i]){
                    flip++;
                }
                temp = !temp;
            }
            int flip1=0;
            temp=0;
            forall(i,0,n){
                if(temp + '0' != str[i]){
                    flip1++;
                }
                temp = !temp;
            }
            if(flip1 > flip){
                printf("%d\n",flip);
                temp = 1;
                forall(i, 0, n){
                    printf("%d",temp);
                    temp = !temp;
                }
                printf("\n");
            }
            else{
                printf("%d\n",flip1);
                temp = 0;
                forall(i, 0, n){
                    printf("%d",temp);
                    temp = !temp;
                }
                printf("\n");
            }
        }else{
            int count = 1;
            flip = 0;
            temp = str[0];
            forall(i, 1, n){
                if(temp == str[i]){
                    count++;
                    if(count > k){
                        if(i != n-1){
                            if(str[i+1] == temp){
                                str[i] = (str[i] - '0' + 1)%2 + '0';
                            }else{
                                str[i-1] = (str[i-1] - '0' + 1)%2 + '0';
                            }
                            flip++;
                        }else{
                            str[i] = (str[i] - '0' + 1)%2 + '0';
                            flip++;
                        }
                        count = 1;
                    }
                }else{
                    count = 1;
                }
                temp = str[i];
            }
            printf("%d\n",flip);
            printf("%s\n",str);
        }
    }
    return 0;
}