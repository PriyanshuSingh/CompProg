#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int row,column;
char buffer[200];
// bool grid[200][200];
int dist[200][200];
// bool vis[200][200];
struct p{
    int x;
    int y;
};
queue<p> Q;
// DP approach was not good as it require massive computation and at times it initiate self loops

// int DP(int i,int j){
//     printf("%d %d  --",i,j);
//     int d,min=1000000;
//     if(dist[i][j] != -1)
// 	return dist[i][j];
//     if(grid[i][j]){
// 	dist[i][j] = 0;
// 	return 0;
//     }
//     vis[i][j] = true;

//     if(i-1>=0 && (dist[i-1][j] != -1 || !vis[i-1][j])){
// 	d=DP(i-1,j);
// 	if(min>d)min=d;
//     }
//     if(i+1<row && (dist[i+1][j] != -1 || !vis[i+1][j])){
// 	d = DP(i+1,j);
// 	if(min>d)min=d;
//     }
//     if(j-1>=0 && (dist[i][j-1] != -1 || !vis[i][j-1])){
// 	d = DP(i,j-1);
// 	if(min>d)min=d;
//     }
//     if(j+1<column && (dist[i][j+1] != -1 || !vis[i][j+1])){
// 	d = DP(i,j+1);
// 	if(min>d)min=d;
//     }
//     printf("\t\t%d %d\n",i,j);
//     dist[i][j] = min+1;
//     return dist[i][j];
// }

// good approach :)
// void pureBFS(int i,int j,int path){
// 	dist[i][j] = path;
// 	if(i-1>=0 && ( dist[i-1][j] == -1 || dist[i-1][j] > path+1))
// 	    pureBFS(i-1,j,path+1);
// 	if(i+1<row && ( dist[i+1][j] == -1 || dist[i+1][j] > path+1))
// 	    pureBFS(i+1,j,path+1);
// 	if(j-1>=0 && ( dist[i][j-1] == -1 || dist[i][j-1] > path+1))
// 	    pureBFS(i,j-1,path+1);
// 	if(j+1<column && ( dist[i][j+1] == -1 || dist[i][j+1] > path+1))
// 	    pureBFS(i,j+1,path+1);
// }

int mi[4] = {1,0,-1,0};
int mj[4] = {0,1,0,-1};

void BFS(){
    p a;
    int x,y,xc,yc;
    while(!Q.empty()){
	a = Q.front();
	Q.pop();
	x = a.x;
	y =a.y;
	for(int i=0; i<4; i++){
	    xc = x+mi[i];
	    yc = y+mj[i];
	    if(xc<row && yc<column && xc>=0 && yc>=0 && (dist[xc][yc] > dist[x][y] || dist[xc][yc] == -1)){
		dist[xc][yc] = dist[x][y] + 1;
		Q.push((p){xc,yc});
	    } 
	}
    }
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    vector<p> st;
    while(tcase--){
	scanf("%d",&row);
	scanf("%d",&column);
	for(int i=0; i<row; i++){
	    scanf("%s",buffer);
	    for(int j=0; j<column; j++){
		dist[i][j] = -1;
		// if(buffer[j] == '0')
		    // grid[i][j] = false;
		if(buffer[j] == '1'){
		    // grid[i][j] = true;
		    dist[i][j] = 0;
		    Q.push((p){i,j});
		}
		// vis[i][j] = false;
	    }
	}
	BFS();
	// for(vector<p>:: iterator it=st.begin(); it != st.end(); ++it){
	//     pureBFS(it->x,it->y,0);
	// // for(int i=0;i<row;i++){
	// //     for(int j=0;j<column;j++){
	// // 	printf("%d ",dist[i][j]);
	// //     }
	// //     printf("\n");
	// // }
	// }
	// st.clear(); 
	// for(int i=0;i<row; i++){
	//     for(int j=0;j<column;j++){
	// 	if(!vis[i][j])
	// 	    // DP(i,j);
	//     }
	// }
	for(int i=0;i<row;i++){
	    for(int j=0;j<column;j++){
		printf("%d ",dist[i][j]);
	    }
	    printf("\n");
	}
    }
    return 0;
}
