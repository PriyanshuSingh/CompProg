//#pragma comment(linker, "/STACK:60777216")  
 
#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include <bitset>
#include <fstream>
#include <queue>
#include <stack>
 
using namespace std;
 
typedef long double ld;
 
typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;
 
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back
 
const ll TO = 55;
 
ll st[TO];
int B = 15;
 
struct BI{
    int a[TO+1];
    BI(){CL(a,0);}
    bool null(){REP(i,TO+1)if(a[i])return 0;return 1;}
    void shift(){
        REP(i,TO)a[i]=a[i+1];
    }
    bool isdiv(int x){
        ll r = 0;
        REP(i,TO+1)r=(r*B+a[i])%x;
        return r==0;
    }
};
 
int main(){	
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
    for(B=2;B<=16;B++){
        st[0]=1;
        FOR(i,1,TO)st[i]=st[i-1]*B;
 
        vector<BI> prev;
        prev.pb(BI());
        for(int len=1;len<TO;len++){
            //cout<<"len " <<len<<endl;
            vector<BI> nn;
            REP(i,prev.size())REP(nd,B){
                BI number = prev[i];
                number.shift();
                number.a[TO] = nd;
                if(number.null())continue;
 
                if(number.isdiv(len)){
                    nn.pb(number);
                    //REP(j,len)printf("%d",number.a[TO-len+1+j]);
                    //puts("");
                }
            }
            if(nn.size()){
                printf("else if (b==%d && d==%d) puts(\"%d\");",B,len,nn.size());
                cout<<endl;
            }
            prev=nn;
        }
    }
    
#ifdef LocalHost
    printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
    return 0;
} 