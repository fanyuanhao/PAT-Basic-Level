#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,j;
	int *a;
	int sum=0;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j!=i){
				sum+=a[i]*10+a[j];
			}
		}
	}
	printf("%d",sum);
	return 0;
} 
