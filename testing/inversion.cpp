#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct k{
    int a;
    int b;
};
k A[200001];
k spare[200001];
int memo[200001]={0};
k A2[200001];

int N;
int inv(int left,int right){
    int middle = (left+right)/2;
    if(left == right){
	return 0;
    }
    else{
	int count=0;
	int g = inv(left,middle);
	int h = inv(middle+1,right);
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

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
	A[i].a = rand()%90 + 8;
	A[i].b = i;
	A2[i] = A[i];
    }
    // for(int i=0; i<N; i++){
    //   printf("%.2d ",memo[i]);
    // }
    // printf("\n");

    int inversion = inv(0,N-1);
    // for(int i=0; i<N; i++){
    //   printf("%.2d ",A[i].a);
    // }
    // printf("\n");
    // for(int i=0; i<N; i++){
    //   printf("%.2d ",memo[i]);
    // }
    return 0;
}
