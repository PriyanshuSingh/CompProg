#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int N;
int value[800000];
int A[200000];

void init(int root,int left,int right){
    if(left == right){
	value[root] = A[left];
    }
    else{
	init(root*2, left, (left+right)/2);
	init(root*2 +1, (left+right)/2 + 1, right);
	if(value[2*root] < value[2*root+1])
	    value[root] = value[2*root+1];
	else
	    value[root] = value[2*root];
    }
}

int query(int k,int a, int b, int root, int left, int right){
    if(value[root] <= k ||a > right || b < left){
      printf("returning from %d to %d %d %d having root value %d\n",left,right,a,b,value[root]);
	return -1;
    }
    else if(left == right){
	printf("%d got value======\n",left);
	return left;
    }
    else{
	int c = query(k,a,b,root*2+1,(left+right)/2+1,right);
	printf("%d <==>  %d\n",(left+right)/2+1,right);
	if(c != -1)
	    return c;
	else
	    return query(k,a,b,root*2,left,(left+right)/2);
    }
}

int main(){
    int a;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
	A[i] = rand()%60 + 1;
	printf("%.3d ",A[i]);
    }
    init(1,0,N-1);
    printf("\n");
    for(int i=0; i<N; i++){
	printf("%.3d ",i);
    }
    printf("\n");
    for(int i=0; i<N; i++){
	printf("%.3d ",value[i]);
    }

    init(1,0,N-1);
    printf("\n");
    while(1){
	scanf("%d", &a);
	printf("%d\n",query(A[a], 0, a-1, 1, 0, N-1));
    }
    return 0;
}
