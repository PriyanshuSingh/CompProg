#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int N;
    int n1,n2,pos=0,npos=0,flag;
    char a[1];
    scanf("%d",&N);
    vector<int> graph[N+1];
    while(scanf("%s %d %d",a,&n1,&n2) != EOF){
	flag = 0;
	if(a[0] == 'c'){
	    graph[n1].push_back(n2);
	    graph[n2].push_back(n1);
	}
	else if(a[0] == 'q'){
	    vector<int>:: iterator it;
	    for(it = graph[n1].begin(); it!= graph[n1].end(); ++it){
		if(*it == n2)
		    flag = 1;
	    }
	    if(flag)
		pos++;
	    else
		npos++;
	}
    }
    printf("%d,%d",pos,npos);
    return 0;
}
