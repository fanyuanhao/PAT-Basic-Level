#include <stdio.h>
int main(){
	int N,M;
	scanf("%d%d",&N,&M); 
	int i=0,j=0;
	int a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	M=M%N;
	int temp;
	for(i=N-1;i>=N-M;i--){
		temp=a[N-1];
		for(j=N-1;j>=1;j--){
			a[j]=a[j-1];
		}
		a[0]=temp;
	}
	for(i=0;i<N;i++){
		if(i==N-1){
			printf("%d",a[i]);
		}else{
			printf("%d ",a[i]);
		}
	}
	return 0;
}
