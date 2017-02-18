#include <stdio.h>
int main(){
	int a[101]={0};//百分制有0到100共101个成绩
	int i,N,x,K,y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&x);
		a[x]++;//读入某个成绩某个成绩个数++ 
	}
	scanf("%d",&K);
	for(i=0;i<K;i++){
		scanf("%d",&y);
		printf("%d",a[y]);
		if(i!=K-1){
			printf(" ");
		}
	}
	return 0;
} 
