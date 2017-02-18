#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	double a[N];
	int i;
	double sum=0.0;
	for(i=0;i<N;i++){
		scanf("%lf",&a[i]);
	}
	for(i=0;N>0;i++,N--){
		sum+=a[i]*N*(i+1);
	}
	printf("%.2lf",sum);
	return 0;
} 
