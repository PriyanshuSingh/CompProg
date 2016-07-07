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

#define ll long long 
#define forall(i, a, b)     for(int (i) = (a); (i) < (b); (i)++)
#define pb     push_back
typedef vector<int> vi;

#include <ctime>
double tick() 
{
    static clock_t oldtick; clock_t newtick = clock();
    double diff = 1.0*(newtick - oldtick) / CLOCKS_PER_SEC;
    oldtick = newtick;
    return diff;
}

#define hash sldfijsdlknf
unsigned long long sum = 0;
int ind;
unsigned int s,q,x,a,b;
const int MAXN = 1<<22;
vi hash[MAXN];
int main(){
        cin>>q>>s>>a>>b;while(q--){
        x = s>>1;
        ind = x & (MAXN-1);
        
        if(s & 1){hash[ind].pb(x);sum+=x;}
        else if(hash[ind].size()!=0){
//            if(hash[ind].size() > 10)cerr<<hash[ind].size()<<endl;
            forall(i, 0, hash[ind].size())if(x==hash[ind][i]){
                swap(hash[ind][i],hash[ind][hash[ind].size()-1]);hash[ind].pop_back();
                sum-=x;break;
            }
        }
        s = a * s + b;
    }
    cout<<sum<<endl;
//    cout<<tick();
}