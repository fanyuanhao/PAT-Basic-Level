#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)a - *(int *)b;
}
int main(){
	int N;
	scanf("%d",&N);
	int primitive[N];
	int process[N];
	int i=0,temp,flag=1,k=1;
	for(i=0;i<N;i++){
		scanf("%d",&primitive[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&process[i]);
	}
	for(i=0;i<N-1&&process[i]<=process[i+1];i++);
	temp=i;
	for(i=temp+1;process[i]==primitive[i];i++);
	if(i==N){
		printf("Insertion Sort\n");
		qsort(process,temp+2,sizeof(process[0]),cmp);
		for(i=0;i<N;i++){
			if(i!=N-1){
				printf("%d ",process[i]);
			}else{
				printf("%d",process[i]);
			}
		}
	}else{
		printf("Merge Sort\n");
		while(flag){
			flag=0;
			for(i=0;i<N;i++){
				if(primitive[i]!=process[i]){
					flag=1;
				}
			}
			k*=2;
			//用qsort模拟归并排序 
			for(i=0;i<N/k;i++){//i表示次数 
				qsort(&primitive[i*k],k,sizeof(primitive[i*k]),cmp);
			}
			for(i=N/k*k;i<N;i+=k){//i是数组下标 
				qsort(&primitive[i],N-i,sizeof(primitive[i]),cmp); 
			}
		}
		for(i=0;i<N;i++){
			if(i!=N-1){
				printf("%d ",primitive[i]);
			}else{
				printf("%d",primitive[i]);
			}
		}
	}

	return 0;
}
