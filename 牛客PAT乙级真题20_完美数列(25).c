//���Ե�0��1��2��ͨ�������Ե�3��5�𰸴��󣬲��Ե�4���г�ʱ
//���Լ�д��ѡ������ĳɿ������� 
#include <stdio.h>
void Selection_Sort(int *a,int N);
void Swap(int *a,int *b);
int main(){
	int N,p;
	scanf("%d",&N);
	scanf("%d",&p);
	int a[N];
	int m,M,V,i,j;//��Сֵ�����ֵ��m*p��ֵ
	int result=0;
	int cnt[100000]={0}; 
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	//�������С��������
	Selection_Sort(a,N); 
	
	//����Сֵ*p������ĸ���
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
