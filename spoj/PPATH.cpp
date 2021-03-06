#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define isInVector(vec,item) find(vec.begin(), vec.end(), item)

const int MAX = 10001;
vector<int> graph[MAX];
bool isPrime[MAX];

void sievePrime(){
    for(int i=0; i<MAX; i++)isPrime[i] = true;
    for(int i=2; i<= MAX/2; i++){
	if(isPrime[i]){
	    // printf("%d ",i);
	    for(int j = 2*i; j < MAX; j += i){
		isPrime[j] = false;
	    }
	}
    }
}



void makeGraph(){
    for(int i = 1000; i<MAX; i++){
	if(isPrime[i]){
	    int x1 = i%10;
	    int x2 = (i/10)%10;
	    int x3 = (i/100)%10;
	    int x4 = (i/1000)%10;
	    for(int j=0; j<10; j++){
		if(j != x1){
		    int p1 = j + x2*10 + x3*100 + x4*1000;
		    if(isPrime[p1]){
			if( isInVector(graph[p1],i) == graph[p1].end()){
			    graph[p1].push_back(i);
			}
			if( isInVector(graph[i],p1) == graph[i].end()){
			    graph[i].push_back(p1);
			}
			
		    }
		}
		if(j != x2){
		     int p2 = x1+ j*10 + x3*100 + x4*1000;
		     if(isPrime[p2]){
			 if( isInVector(graph[p2],i) == graph[p2].end()){
			     graph[p2].push_back(i);
			 }
			 if( isInVector(graph[i],p2) == graph[i].end()){
			     graph[i].push_back(p2);
			 }
		     }
		}
		if(j != x3){
		     int p3 = x1 + x2*10 + j*100 + x4*1000;
		     if(isPrime[p3]){
			 if( isInVector(graph[p3],i) == graph[p3].end()){
			     graph[p3].push_back(i);
			 }
			 if( isInVector(graph[i],p3) == graph[i].end()){
			     graph[i].push_back(p3);
			 }
		     }
		}
		if(j != x4 && j != 0){
		     int p4 = x1 + x2*10 + x3*100 + j*1000;
		     if(isPrime[p4]){
			 if( isInVector(graph[p4],i) == graph[p4].end()){
			     graph[p4].push_back(i);
			 }
			 if( isInVector(graph[i],p4) == graph[i].end()){
			     graph[i].push_back(p4);
			 }
		     }
		}
	    }
	}
    }
}

int bfs(int start,int end){
    queue<int> Q;
    int dis[MAX];
    bool vis[MAX];
    bool inQueue[MAX];
    for(int i=0; i<MAX; i++){
	vis[i] = false;
	dis[i] = -1;
	inQueue[i] = false;
    }
    Q.push(start);
    dis[start] = 0;
    if(start == end)
	return dis[end];
    while(!Q.empty()){
	int t = Q.front();
	Q.pop();
	if(t == end){
	    return dis[end];
	}
	vis[t] = true;
	for(vector<int> :: iterator it=graph[t].begin(); it != graph[t].end(); ++it){
    
	    if(!vis[*it]&&!inQueue[*it] ){
		// printf("%d ",*it);
		dis[*it] = dis[t]+1;
		Q.push(*it);
		inQueue[*it] = true;
	    }

	}
	// printf("\t\t%d\n",t);
    }
    return dis[end];
}

int main(){
    sievePrime();
    makeGraph();
    // for(int i=1000; i<MAX; i++){
    // 	printf("%d\t",i);
    // 	for(vector<int> :: iterator it = graph[i].begin(); it != graph[i].end(); ++it){
    // 	    printf(" %d",*it);
    // 	}
    // 	printf("\n");
    // }
    int n,f1,f2;
    scanf("%d",&n);
    while(n--){
	scanf("%d",&f1);
	scanf("%d",&f2);
	printf("%d\n",bfs(f1,f2));
    }

    return 0;
}
