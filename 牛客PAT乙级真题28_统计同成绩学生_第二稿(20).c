#include <stdio.h>
int main(){
	int a[101]={0};//�ٷ�����0��100��101���ɼ�
	int i,N,x,K,y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&x);
		a[x]++;//����ĳ���ɼ�ĳ���ɼ�����++ 
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
