#include <stdio.h>
#include <stdlib.h> 
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int N,p;
	scanf("%d",&N);
	scanf("%d",&p);
	int a[N];
	int m,M,V,i,j;//��Сֵ�����ֵ��m*p��ֵ
	int cnt=1;
	
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	//�������С��������
	qsort(a,N,sizeof(a[0]),cmp); 
	
	for(i=0;i<N;i++){
		m=a[i];
		V=m*p;//��Ϊm��p��������10��9�η����������V��int���;ͱ�ʾ������ 
		for(j=i+cnt;j<N;j++){
			if(a[j]>V){
				break;
			}
			cnt++;
		}
	}

	printf("%d",cnt);
	
	return 0;
}
