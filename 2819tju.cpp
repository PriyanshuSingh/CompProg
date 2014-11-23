#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

#define INF 2139062143
using namespace std;

//#define FOR_EACH(it,x) for( typeof(x.begin()) it = x.begin(); it!=x.end(); ++it)

struct state{
    int vertex;
    int weight;
};

const int MAX = 1000;

vector<state> graph[MAX];
int dist[MAX];
int n;

class CompareState {
public:
    bool operator()(state& t1, state& t2){
	if (t1.weight > t2.weight) return true;
	return false;
    }
};

void dijkstra(int source,int dest){
    
    memset(dist,127,sizeof(dist));
    //    printf("%d",dist[0]);
    dist[source] = 0;
    priority_queue<state,vector<state>,CompareState>q;
    q.push((state){source,0});

    while(!q.empty()){
	state top = q.top(); q.pop();
	if(top.weight > dist[top.vertex]) continue;
	if(top.vertex == dest) break;
	vector<state>:: iterator it;
	for(it = graph[top.vertex].begin();it!=graph[top.vertex].end();++it){
	    
	    int alt = dist[top.vertex] + it->weight;
	    if(alt < dist[it->vertex]){
		q.push((state){it->vertex,dist[it->vertex] = alt});
	    }
	}
    }
}

void init(){
    for(int i=0;i<MAX;i++){
	graph[i].clear();
    }
}

int main(){
    int tcase;
    int N,M;
    int ver1,ver2,weight,S,T;
    scanf("%d",&tcase);
    while(tcase--){
	init();
	scanf("%d",&N);
	scanf("%d",&M);
	scanf("%d",&S);
	scanf("%d",&T);
	while(M--){
	    scanf("%d",&ver1);
	    scanf("%d",&ver2);
	    scanf("%d",&weight);
	    graph[ver1].push_back((state){ver2,weight});
	    graph[ver2].push_back((state){ver1,weight});
	}
	dijkstra(S,T);
	if(dist[T] == INF){
	    printf("-1\n");
	}
	else{
	    printf("%d\n",dist[T]);
	}
    }
}
