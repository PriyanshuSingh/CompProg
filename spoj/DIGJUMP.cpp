#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
vector<int> connect[10];
int dist[100010];
int main(){
    char a[100010];
    int u,n;
    scanf("%s",a);
    n = strlen(a);
    for(int i=0; i < n; i++){
	dist[i] = -1;
	connect[a[i]-'0'].push_back(i);
    }
    queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()){
	u=Q.front();
	Q.pop();
	if(u == n - 1) break;
	for(int i=0;i<connect[a[u] - '0'].size();i++){
	    if(dist[connect[a[u] - '0'][i]] == -1){
		dist[connect[a[u] - '0'][i]] = dist[u] + 1;
		Q.push(connect[a[u] - '0'][i]);
	    }
	}
	connect[a[u] - '0'].clear();
	if(u && dist[u-1] == -1){
	    Q.push(u-1);
	    dist[u-1] = dist[u] + 1;
	}
	if(dist[u+1] == -1){
	    Q.push(u+1);
	    dist[u+1] = dist[u] + 1;
	}
    }
    printf("%d\n",dist[n-1]);
    return 0;
}
