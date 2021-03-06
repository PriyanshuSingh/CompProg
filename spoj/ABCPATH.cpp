#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct p{
    int x;
    int y;
};

char grid[50][50];
char row[55];
int dist[50][50];
vector<p> start;

int DFS(p s,int rw,int clm){

    if(dist[s.x][s.y] != -1)
	return dist[s.x][s.y];
    int max=0,d;
    for(int i=s.x-1; i<s.x+2;i++){
	for(int j=s.y-1;j<s.y+2;j++){
	    if(i>=0 && i<rw && j>=0 && j<clm){
		if(i==s.x && j==s.y)
		    continue;
		else{
		    if(grid[i][j] == grid[s.x][s.y]+1){
		      d = DFS((p){i,j},rw,clm);
			if(max < d)max=d;
		    }
		}
	    }
	}
    }
    dist[s.x][s.y] = max+1;
    return max+1;
}


int main(){
    int rw,clm,d,max=0;
    scanf("%d",&rw);
    scanf("%d",&clm);
    int count=0;
    while(rw && clm){
	count++;
	for(int i=0;i<rw;i++){
	    scanf("%s",row);
	    for(int j=0;j<clm;j++){
		grid[i][j] = row[j];
		dist[i][j] = -1;
		if(grid[i][j] == 'A')
		    start.push_back((p){i,j});
	    }
	}
	for(int i=0; i<start.size();i++){
	    d=DFS(start[i],rw,clm);
	    if(max<d)max=d;
	}
	// for(int i=0;i<rw;i++){
	//     for(int j=0;j<clm;j++){
	// 	printf("%d ",dist[i][j]);
	//     }
	//     printf("\n");
	// }
	printf("Case %d: %d\n",count,max);
	max =0;
	start.clear();
	scanf("%d",&rw);
	scanf("%d",&clm);
    }
    return 0;
}
