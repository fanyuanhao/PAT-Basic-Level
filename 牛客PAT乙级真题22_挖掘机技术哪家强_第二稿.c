#include <stdio.h>
int main(){
	int N;
	int i=0,j=0;
	scanf("%d",&N);
	int S;//学校编号 
	int score;//成绩 
	int max;//学校的个数 
	int MAX;//总成绩最高的成绩 
	//int a[N+1];//下标存学校的编号，是从下标为1开始存 
	int a[100005]={0};//学校从1开始编号，不是说6个编号，编号就是从1到6 
	/*
	对于数组要参与运算的一定要把数组里面的值都初始化为0 
	for(i=0;i<=N;i++){
		a[i]=0;
	}
	*/
	for(i=0;i<N;i++){
		scanf("%d",&S);
		if(i==0){
			max=S;
		}
		if(S>max){
			max=S;
		}
		scanf("%d",&score);
		a[S]+=score; 
	}
	
	for(i=1;i<=max;i++){
		if(i==1){
			MAX=a[i];
			S=i;
		}
		if(a[i]>MAX){
			MAX=a[i];
			S=i;
		}
	} 
	printf("%d %d",S,MAX);
	return 0;
} 
