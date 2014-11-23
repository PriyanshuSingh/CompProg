#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<int> graph[10001];
int level[10001];
int le[10001];
bool vis[10001];
queue<int> q;

void levelSetter(int k,int lev){
    int i;
    vis[k] = true;
    for(typeof(graph[k].begin()) i = graph[k].begin(); i!=graph[k].end(); ++i){
        if(vis[*i] == false){
	    level[*i] = lev+1;
	    le[lev+1]++;
	    levelSetter(*i,lev+1);
        }
    }
}


int main(){
    int tcase;
    int n,i,t1,t2;
    scanf("%d",&tcase);
    while(tcase--){
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
	    scanf("%d",&t1);
	    scanf("%d",&t2);
	    graph[t1].push_back(t2);
	    graph[t2].push_back(t1);
	    levelSetter(1,1);
	    for(i=0;i<n+1;i++){
		printf("%d ",level[i]);
	    }
	    printf("\n");
	    for(i=0;i<n+1;i++){
		printf("%d ",le[i]);
	    }
	}
    }
}
