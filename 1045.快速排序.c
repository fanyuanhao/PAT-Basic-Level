#include <stdio.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int N;
	scanf("%d",&N);
	int i=0,cnt=0,temp,max=0;
	int a[N],b[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	qsort(b,N,sizeof(b[0]),cmp);
	
	for(i=0;i<N;i++){
		if(a[i]!=b[i]||a[i]<max){
			b[i]=0;
			cnt++;
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	
	printf("%d\n",N-cnt);
	
	temp=N-cnt;
	cnt=0;
	for(i=0;i<N;i++){
		if(b[i]!=0){
			cnt++;
			if(cnt!=temp){
				printf("%d ",b[i]);
			}else{
				printf("%d",b[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
