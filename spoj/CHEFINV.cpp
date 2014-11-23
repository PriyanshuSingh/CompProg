#include <iostream>
#include <cstdio>
#include <cstdlib>

struct k{
    int a;
    int b;
};
k A[200001];
k spare[200001];
int memo[200001]={0};
k A2[200001];
int N;
int value[800001];

long int inv(int left,int right){
    int middle = (left+right)/2;
    if(left == right){
	return 0;
    }
    else{
	long int count=0;
	long int g = inv(left,middle);
	long int h = inv(middle+1,right);
	int i = left,j=middle+1,k=left;
	for(; i<=middle && j <=right; ){
	    if(A2[i].a > A2[j].a){
	      // printf("%d %d (inc A2[j].b = %d) inc with = %d\n",A2[i].a,A2[j].a,A2[j].b,middle-i+1);
		spare[k++] = A2[j++];
		count += middle - i + 1;
		memo[A2[j-1].b] += middle-i+1;
	    }
	    else{
		// printf("%d %d \n",A2[i].a,A2[j].a);
		spare[k++] = A2[i++];
	    }
	   
	}
	// printf("-----\n\n");
	while(i<=middle){
	    spare[k++] = A2[i++];
	}
	while(j<=right){
	    spare[k++] = A2[j++];
	}
	for(int i=left; i<=right; i++){
	    A2[i] = spare[i];
	}
	return g+h+count;
    }
}

void init(int root,int left,int right){
    if(left == right){
	value[root] = A[left].a;
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
      // printf("returning from %d to %d %d %d having root value %d\n",left,right,a,b,value[root]);
	return -1;
    }
    else if(left == right){
	// printf("%d got value======\n",left);
	return left;
    }
    else{
	int c = query(k,a,b,root*2+1,(left+right)/2+1,right);
	// printf("%d <==>  %d\n",(left+right)/2+1,right);
	if(c != -1)
	    return c;
	else
	    return query(k,a,b,root*2,left,(left+right)/2);
    }
}

int main(){
    int M,temp;
    int x,y;
    long int inversion;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){
	scanf("%d",&temp);
	A[i].a = temp;
	A[i].b = i;
    }
    init(0,N-1);
    inversion = inv(0,N-1);

    while(M--){
	scanf("%d",&x);
	scanf("%d",&y);
	if(x<y){


}
