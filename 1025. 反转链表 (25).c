#include <stdio.h>
int main(){
	int head,N,K,i;
	scanf("%d%d%d",&head,&N,&K);
	int temp;//地址
	int data[100005];
	int next[100005];
	//读入值 
	for(i=0;i<N;i++){
		scanf("%d",&temp);
		scanf("%d",&data[temp]);
		scanf("%d",&next[temp]);
	}
	//转成一维数组，下标是计数，值为地址 
	int list[100005];
	int sum=0;
	while(head!=-1){
		list[sum]=head;
		head=next[head];
		sum++;
	}
	//建一个相同的一维数组 
	int result[100005];
	for(i=0;i<sum;i++){
		result[i]=list[i];
	}
	//进行转换
	for(i=0;i<(sum/K*K);i++){
		result[i]=list[i/K*K+K-1-i%K];//i/K*K+K-1要反转的最后一个位置i%K相等于每次减1 
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
