#include <stdio.h>
#include <string.h>
/*
测试点3说出现了段错误。 
我知道什么地方错了，我用二维数组来存，其中有很多空间是存的没有意义的0
这样浪费了大量的空间，当N很大的时候，内存不够用
之前之所以选择二维数组不选择结构体，是因为结构体不好找相同学校的编号 
*/
int main(){
	int N;
	int i=0,j=0;
	scanf("%d",&N);
	int S;
	int max;//学校的个数 
	int MAX;//总成绩最高的成绩 
	int a[N][N];//第二个下标存学校的编号，是从下标为1开始存 
	//memset(a,0,sizeof(int)*(N*(N+1)));
	
	for(i=0;i<N;i++){
		for(j=0;j<N+1;j++){
			a[i][j]=0;
		}
	}
	
	for(i=0;i<N;i++){
		scanf("%d",&S);
		if(i==0){
			max=S;
		}
		if(S>max){
			max=S;
		}
		scanf("%d",&a[i][S]);	
	}
	int sum[max];
	for(i=0;i<=max;i++){
		sum[i]=0;
	}
	
	//memset(sum,0,sizeof(int)*max);
	for(j=1;j<=max;j++){
		for(i=0;i<N;i++){
			//printf("%d ",a[i][j]);
			sum[j]+=a[i][j];
		}
		//printf("\n");
	}
	
	for(i=1;i<=max;i++){
		if(i==1){
			MAX=sum[i];
			S=i;
		}
		if(sum[i]>MAX){
			MAX=sum[i];
			S=i;
		}
	} 
	printf("%d %d",S,MAX);
	return 0;
} 
