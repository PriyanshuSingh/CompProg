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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define ll long long
typedef long double ld;

const int MOD = 1e9+7;

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
typedef long double ld;

const int MAXN = 1e5+10;
const int SQRTN = 320;
ld lF[MAXN];
ll F[MAXN];
ld lans[SQRTN];
ll ans[SQRTN];
int N,Q;

void init(){
    forall(i, 1, N+1){
        lF[i] = log10(F[i]);
    }if(N > SQRTN){
        forall(R, 1, SQRTN){
            lans[R] = 0;ans[R]=1;
            for(int i=1; i<=N; i+=R){
                lans[R] += lF[i];
                ans[R] *= F[i];ans[R] %= MOD;
            }
        }
    }
}
void modifyF(int p, ll f){
    ld f_log = log10(f);
    if(N > SQRTN){
        ll diviNmul = pow_mod(F[p], (ll)(MOD-2));
        diviNmul *= f;diviNmul %= MOD;
        forall(R, 1, SQRTN){
            if((p-1)%R == 0){
                ans[R] *= diviNmul;ans[R] %= MOD;
                lans[R] -= lF[p];
                lans[R] += f_log;
            }
        }
    }
    F[p] = f;
    lF[p] = f_log;
}
void solve(){
    init();
    while(Q--){
        int t;cin>>t;if(t==1){
            int p,f;cin>>p>>f;modifyF(p, f);
        }else{
            int r;cin>>r;
            if(N > SQRTN && r < SQRTN){
                ld frac = lans[r] - ((ll)lans[r]);
                ll fir = pow((long double)10.0, frac);
                cout<<fir<<' '<<ans[r]<<endl;
            }else{
                ll ians = 1;
                ld ilog = 0;
                for(int i=1; i<=N; i+=r){
                    ilog += lF[i];
                    ians *= F[i];
                    ians %= MOD;
                }
                ld frac = ilog - ((ll)ilog);
                ll fir = pow((long double)10.0, frac);
                cout<<fir<<' '<<ians<<endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N;bool les=true;
    forall(i, 1, N+1){cin>>F[i];if(F[i] > 10)les=false;}
    cin>>Q;
    if(les && N <= 10){
        while(Q--){
            int t;cin>>t;if(t==1){int p,f;cin>>p>>f;F[p]=f;}
            else {int r;cin>>r;ll ans=1; for(int i=1; i<=N; i+=r)ans *= F[i];
            ll fir = ans;while(fir >= 10)fir /= 10;cout<<fir<<' '<<ans%MOD<<endl;
            }
        }
    }else{
        solve();
    }
}
