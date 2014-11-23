#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

struct state{
    int vertex;
    int height;
    int diameter;
}
vector<state> graph[100001];
int vis[100001];
void DFS(int ver,int N){
    memset(vis,0,sizeof(int)*N);
    dfs(ver);
}



int main(){
    int N,U,V,R,Q,S;
    scanf("%d",&N);
    for(i=0; i<N-1; i++){
	scanf("%d", &U);
	scanf("%d", &V);
	graph[(state){U,-1,-1}].push_back((state){V,-1,-1});
	graph[(state){V,-1,-1}].push_back((state){U,-1,-1});
    }



    return 0;
}

