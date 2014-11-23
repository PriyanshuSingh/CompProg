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

vector<int> grph[256];

int ans[256][256];

void BFS(int a){
    queue<int> Q;
    bool vis[256];
    fill(vis,0);
    Q.push(a);
    vis[a] = true;
    int top;
    ans[a][a] = 1;
    while(!Q.empty()){
	top=Q.front();
	Q.pop();
	for(vector<int>::iterator it = grph[top].begin(); it != grph[top].end(); ++it ){
	    if(!vis[*it]){
		Q.push(*it);
		vis[*it] = true;
		ans[a][*it] = true;
	    }
	}
    }
    for(int i=0;i<256;i++){
	if(ans[a][i] != 1)ans[a][i] = 0;
    }
}

int main(){
    int P,M;
    char S[1010],T[1010],buff[101];
    int Slen,Tlen;
    s(P);
    while(P--){
	for(int i=0;i<256;i++){
	    for(int j=0; j<256;j++){
		ans[i][j] = -1;
	    }
	}
	ss(S);
	bool flag = true;
	Slen = strlen(S);
	ss(T);
	Tlen = strlen(T);
	s(M);
	while(M--){
	    ss(buff);
	    grph[buff[0]].pb(buff[3]);
	}
	if(Slen != Tlen){
	    printf("NO\n");
	}
	else{
	    for(int i=0; i< Slen;i++){
		if(S[i] == T[i])continue;
		else if(ans[S[i]][T[i]] == 0){
		    flag = false;
		    break;
		}
		else if(ans[S[i]][T[i]] == 1)continue;
		else{
		    BFS(S[i]);
		    //		    printf("%c\n",S[i]);
		    if(ans[S[i]][T[i]] == 1)continue;
		    else{
			flag = false;
			break;
		    }
		}
	    }
	    if(flag)printf("YES\n");
	    else
		printf("NO\n");
	    for(int i=0; i<256;i++){
	      grph[i].erase(all(grph[i]));
	    }
	}
    }
}
