#include <stdio.h>
#include <string.h>
/*
���Ե�3˵�����˶δ��� 
��֪��ʲô�ط����ˣ����ö�ά�������棬�����кܶ�ռ��Ǵ��û�������0
�����˷��˴����Ŀռ䣬��N�ܴ��ʱ���ڴ治����
֮ǰ֮����ѡ���ά���鲻ѡ��ṹ�壬����Ϊ�ṹ�岻������ͬѧУ�ı�� 
*/
int main(){
	int N;
	int i=0,j=0;
	scanf("%d",&N);
	int S;
	int max;//ѧУ�ĸ��� 
	int MAX;//�ܳɼ���ߵĳɼ� 
	int a[N][N];//�ڶ����±��ѧУ�ı�ţ��Ǵ��±�Ϊ1��ʼ�� 
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
