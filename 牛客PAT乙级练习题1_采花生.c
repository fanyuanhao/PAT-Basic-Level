#include <stdio.h>
#include <math.h>
int main(){
	int M,N,K;
	scanf("%d%d%d",&M,&N,&K);
	int a[M+1][N+1];//M��������Ϊ�����±��������Ӧ����Ҫ��һ�� 
	int i,j;
	//int k,w;
	int count=0;
	int temp_v,temp_k,temp_w;
	int SumStep=0,SumValue=0;
	
	/*
	int *p=NULL,*q=NULL;//����ָ�����ֲ���0���Ǹ�Ԫ�ص��к��� 
	temp1=p;
	temp2=q;
	*/
	
	struct node{
		int k;//�������治Ϊ0������ 
		int w;//�������治Ϊ0������
		int v;//�������治Ϊ0��ֵ 
	} b[M*N];
	//struct node *p=b;
	
	
	//������ֵ 
	for(i=1;i<=M;i++){//Ϊ�����±��Ӧ���� 
		for(j=1;j<=N;j++){//Ϊ�����±��Ӧ���� 
			scanf("%d",&a[i][j]);
		}
	}
	
	/*
	���Զ�����ֵ�Ƿ���ȷ 
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d",a[i][j]);
		}
	}
	*/
	//��Ϊ0�����Ĵ洢 
	for(i=1;i<=M;i++){
		for(j=1;j<=N;j++){
			if(a[i][j]!=0){
				
				b[count].k=i;
				b[count].w=j;
				//printf("%d ",a[i][j]);
				b[count].v=a[i][j]; 
				count++;//������¼��Ϊ0�ĸ��� 			
			} 
		}
	}
	
	//ð�����򷨣�����Ϊ0��ֵ����С�������� 
	for(i=0;i<count;i++){
		for(j=0;j<count-1;j++){
			if(b[j].v>b[j+1].v){
				temp_k=b[j].k;
				temp_w=b[j].w;
				temp_v=b[j].v;
				
				b[j].k=b[j+1].k;
				b[j].w=b[j+1].w;
				b[j].v=b[j+1].v;
				
				b[j+1].k=temp_k;
				b[j+1].w=temp_w;
				b[j+1].v=temp_v;
			}
		}
	}
	
	
	//�����ܲɵ����ٻ��� 
	
	for(i=count-1;i>=0;i--){
		
		if(i==count-1){
			SumStep=fabs(b[i].k-0)+1+fabs(0-b[i].k);
			if(SumStep>K){
				printf("%d",SumValue);
				break;
			}
			SumValue=b[i].v;
			continue;
		}
		SumStep=SumStep+fabs(b[i].k-b[i+1].k)+fabs(b[i].w-b[i+1].w)+fabs(0-b[i].k)-fabs(0-b[i+1].k)+1;
		if(SumStep>K){
			printf("%d",SumValue);
			break;
		}else{
			SumValue=SumValue+b[i].v;
		}
				
		
	} 
	
	 
	/*
	���Ա�����ֵ�Ƿ���ȷ 
	for(i=0;i<count;i++){
		printf("%d\n",b[i].v);
	}
	*/
	
	
	
	
	
	/* 
	֮ǰ������뷨�ýṹ��ָ��ָ�����ַ��������ʱ�򲻺��� 
	for(i=0;i<count;i++){
		for(j=0;j<(count-1);j++){
			p=temp1;
			int k=p->k;
			int w=p->w;
			struct node *temp2=p+1;
			int k1=temp2->k;
			int w1=temp2->w;
			if(a[k][w]<a[k1][w1]){
				temp=a[k1][w1]; 
				a[k1][w1]=a[k][w];
				a[k][w]=temp;
			}
			p++;
				
		}
		int k=p->k;
		int w=p->w;
		printf("%d",a[k][w]);
	}
	*/ 
	
	
	
	return 0;
} 
