#include <stdio.h>
int main(){
	int head,N,K,i;
	scanf("%d%d%d",&head,&N,&K);
	int temp;//��ַ
	int data[100005];
	int next[100005];
	//����ֵ 
	for(i=0;i<N;i++){
		scanf("%d",&temp);
		scanf("%d",&data[temp]);
		scanf("%d",&next[temp]);
	}
	//ת��һά���飬�±��Ǽ�����ֵΪ��ַ 
	int list[100005];
	int sum=0;
	while(head!=-1){
		list[sum]=head;
		head=next[head];
		sum++;
	}
	//��һ����ͬ��һά���� 
	int result[100005];
	for(i=0;i<sum;i++){
		result[i]=list[i];
	}
	//����ת��
	for(i=0;i<(sum/K*K);i++){
		result[i]=list[i/K*K+K-1-i%K];//i/K*K+K-1Ҫ��ת�����һ��λ��i%K�����ÿ�μ�1 
	}
	for(i=0;i<sum;i++){
		if(i!=sum-1){
			printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
		}else{
			printf("%05d %d -1",result[i],data[result[i]],result[i+1]);
		}
	} 
	return 0;
}
