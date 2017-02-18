/*
这个程序运行超时，算法不好 
*/
#include <stdio.h>
int main(){
	int N,i,K,j,cnt;
	scanf("%d",&N);
	int A[N];

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&K);
	int B[K];
	for(i=0;i<K;i++){
		scanf("%d",&B[i]);
	}
	for(i=0;i<K;i++){
		cnt=0;
		for(j=0;j<N;j++){
			if(B[i]==A[j]){
				cnt++;
			}
		}
		if(i!=K-1){
			printf("%d ",cnt);			
		}else{
			printf("%d",cnt);
		}	
	}
	
	return 0;
} 
