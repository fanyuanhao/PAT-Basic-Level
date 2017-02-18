//测试点0、1、2能通过，测试点3、5答案错误，测试点4运行超时
//将自己写的选择排序改成快速排序 
#include <stdio.h>
void Selection_Sort(int *a,int N);
void Swap(int *a,int *b);
int main(){
	int N,p;
	scanf("%d",&N);
	scanf("%d",&p);
	int a[N];
	int m,M,V,i,j;//最小值、最大值、m*p的值
	int result=0;
	int cnt[100000]={0}; 
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	//对数组从小到大排序
	Selection_Sort(a,N); 
	
	//从最小值*p找里面的个数
	for(i=0;i<N;i++){
		m=a[i];
		V=m*p;
		for(j=i;j<N;j++){
			if(a[j]<=V){
				cnt[i]++;
			}else{
				break;
			}
		}
		if(i!=0){
			if(cnt[i-1]>=cnt[i]){
				result=cnt[i-1];
				break;
			}
		}
		
	} 
	printf("%d",result);
	
	return 0;
}
void Selection_Sort(int *a,int N){
	int i=0,j=0;
	int max;
	for(i=N-1;i>=0;i--){
		max=i;
		for(j=0;j<i;j++){
			if(a[j]>a[max]){
				max=j;
			}
		}
		if(max!=i){
			Swap(&a[i],&a[max]);
		}
	}
	
}
void Swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
