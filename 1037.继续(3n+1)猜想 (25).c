//�������Ͳ�һ�����Ե����ȥ��˵�Ƕδ��󣬲�֪��������ʲô�ط��� 
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int K;
	scanf("%d",&K);
	int a[K];//��Ŷ�����������
	
	int i=0,j=0,w=0,temp=0;
	for(i=0;i<K;i++){
		scanf("%d",&a[i]);
	}
	int b[100][100];//������ű����ǵ�ֵ����һ���±�ΪҪ�жϵ���
	
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			b[i][j]=0;
		}
	}
	
	//�ѱ����ǵ�ֵ�浽��ά������ 
	for(i=0;i<K;i++){
		j=0;
		temp=a[i];
		while(temp>1){
			if(temp%2==0){
				temp/=2;
				if(temp<=100){
					b[a[i]][j]=temp;
					j++;
				}
			}else{
				temp=(3*temp+1)/2;
				if(temp<=100){
					b[a[i]][j]=temp;
					j++;
				}
			}
		}
	}
	//ɨ�������ֵ�ͱ����ǵ�ֵ�������б����������ǵ�������0 
	for(i=0;i<K;i++){
		if(a[i]==0){
			continue;
		}
		for(w=0;w<K;w++){
			for(j=0;j<100;j++){
		
				if(a[i]==b[a[w]][j]){
					a[i]=0;
				}
			}
		}
	}
	
	int c[100];//���ؼ����浽������
	j=0;
	for(i=0;i<K;i++){	
		if(a[i]!=0){
			c[j]=a[i];
			j++;
		}
	}
	
	qsort(c,j,sizeof(c[0]),cmp);
	for(i=0;i<j;i++){
		if(i==j-1){
			printf("%d",c[i]);
		}else{
			printf("%d ",c[i]);
		}
		
	}
	
	return 0;
} 
