#include <stdio.h>
int main(){
	int N;
	int i=0,j=0;
	scanf("%d",&N);
	int S;//ѧУ��� 
	int score;//�ɼ� 
	int max;//ѧУ�ĸ��� 
	int MAX;//�ܳɼ���ߵĳɼ� 
	//int a[N+1];//�±��ѧУ�ı�ţ��Ǵ��±�Ϊ1��ʼ�� 
	int a[100005]={0};//ѧУ��1��ʼ��ţ�����˵6����ţ���ž��Ǵ�1��6 
	/*
	��������Ҫ���������һ��Ҫ�����������ֵ����ʼ��Ϊ0 
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
