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

//#ifdef __MINGW32__
//#define printf __mingw_printf   /* codeforces long double problem with printf */
//#endif

//#if __cplusplus > 199711L
//#define typeof decltype
//#endif

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
#define foreach(v, c)               for( __typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
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
#define sqr(a)                      (a) * (a)


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
// can print whole array (arr should not contain any pointer airthmetics)
#define traceArr(arr,size)           do{ vi __ARRAY_NAME__##arr((arr), (arr)+(size)); trace1(__ARRAY_NAME__##arr);}while(0)
#else
#define METHOD_NAME
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define traceArr(arr,size)
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

struct Point{
    ll x,y;
    const Point operator+ (const Point& other) const {Point out; out.x = x + other.x; out.y = y + other.y; return out;}
    const Point operator- (const Point& other) const {Point out; out.x = x - other.x; out.y = y - other.y; return out;}
    Point& operator+= (const Point& other) {x += other.x; y += other.y; return *this;}
    Point& operator-= (const Point& other) {x -= other.x; y -= other.y; return *this;}
    bool operator== (const Point& other) const {return x==other.x && y == other.y;}
    bool operator< (const Point& other) const {return (y == other.y)?x < other.x: y < other.y;}
};

inline ll cross(Point a, Point b){return a.y*b.x - a.x*b.y;}
inline ll sqrDist(Point a, Point b){return sqr(a.x - b.x) + sqr(a.y - b.y);}

const int MAXN = 1e5+10;
#include <set>
set<Point> outer;
vector<Point> points;
vector<Point> points2;
vector<Point> outerHull,innerHull;
void convexHull(vector<Point> &pts, vector<Point> &out){
    int mini=0;forall(i, 1, pts.size()){
        if(pts[mini].y > pts[i].y || (pts[mini].y == pts[i].y && pts[mini].x > pts[i].x))mini = i;
    }
    swap(pts[mini], pts[0]);
    auto it = pts.begin();it++;
    Point x = pts[0];
    sort(it, pts.end(), [&x](Point a, Point b) -> bool{
        return cross(a - x, b - x) > 0;
    });
    for(int i=0; i<3 && i<pts.size(); i++)out.pb(pts[i]);
    int i = 3;
    while(i < pts.size()){
        Point l = out[out.size()-1], nl = out[out.size()-2];
        while(cross(l - nl, pts[i] - l) < 0){out.pop_back(); assert(out.size() >= 2); l = out[out.size() - 1]; nl = out[out.size()-2];}
        out.pb(pts[i]);i++;
    }
}

ll area(vector<Point> poly){
    if(poly.size() < 3)return 0;
    else{
        ll ret = 0;
        Point a = poly[0];forall(i, 1, poly.size()-1)ret += cross(poly[i]-a,poly[i+1]-a);
        return abs(ret);
    }
}

ll area(Point a, Point b, Point c){return abs(cross(b-a,c-a));}

inline int modd(int a, int M){return (a>=M)?a-M:a;}

int main(){
    ios_base::sync_with_stdio(false);
    points.reserve(MAXN);
    points2.reserve(MAXN);
    outerHull.reserve(MAXN);
    innerHull.reserve(MAXN);
    int T;cin>>T;while(T--){
        points.clear();points2.clear();outer.clear();outerHull.clear();innerHull.clear();
        int N;cin>>N;forall(i, 0, N){int x,y; cin>>x>>y; points.pb({x,y});}
        if(points.size() == 3)cout<<"-1\n";
        else{
            convexHull(points, outerHull);
            if(outerHull.size() == points.size()){cout<<"-1\n";continue;}
            foreach(v, outerHull)outer.insert(*v);
            foreach(v, points)if(outer.count(*v) == 0)points2.pb(*v);
            convexHull(points2, innerHull);
            ll minarea = 1e18;
            int j = 0;
            const int osize = outerHull.size(),isize = innerHull.size();
            for(int i = 0; i < osize; i++){
                ll curarea = area(outerHull[i], outerHull[modd(i+1,osize)], innerHull[j]);
                while(true){
                    ll newarea = area(outerHull[i],outerHull[modd(i+1,osize)],innerHull[modd(j+1,isize)]);
                    if(newarea < curarea){curarea = newarea; j = modd(j+1,isize);}
                    else break;
                }
                minarea = min(minarea, curarea);
            }
            cout<< area(outerHull) - minarea<<endl;
        }
    }
    return 0;
}
