#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX (101)
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

using namespace std;

int seq[MAX][MAX];

bool check(int ind,int S){
    forall(i,1,S-ind){
	if(seq[ind][i-1] != seq[ind][i])return false;
    }
    return true;
}

inline void process(int S,int C){
  if(S == 1 || check(0,S)){
	forall(i,S,C+S)seq[0][i] = seq[0][i-1];
	return ;
    }
    int i;
    for(i = 1; S - i >= 1; i++){
	forall(j,0,S-i){
	    seq[i][j] = seq[i-1][j+1]-seq[i-1][j];
	}
	if(check(i,S))break;
    }
    forall(j,S-i,S-i+C){
	seq[i][j] = seq[i][j-1];
    }
    for(int j = i-1; j>=0;j--){
	forall(k,S-j,S-j+C){
	    seq[j][k] = seq[j][k-1] + seq[j+1][k-1];
	}
    }

}

int main(){
    int t,S,C;
    s(t);
    while(t--){
	s(S);
	s(C);
	forall(i,0,S){
	    s(seq[0][i]);
	}
        process(S,C);
	forall(i,S,S+C){
	    printf("%d ",seq[0][i]);
	}
	printf("\n");
    }
    return 0;
}
