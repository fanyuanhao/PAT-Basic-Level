#include <stdio.h>
#include <math.h>
int cmp(const void *a,const void *b){
	return *(int *)b-*(int *)a;
}
int main(){
	int N,i,j,t=0,m,n,k,circle;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,N,sizeof(a[0]),cmp);
	n=sqrt(N);
	while(N%n!=0){
		n--;
	}
	m=N/n;
	int b[m][n];
	circle=n/2+n%2;
	for(k=0;k<circle;i++){//k代表第几圈,之前写的是用i表示第几圈，后来换了，但是后面的i忘了改，就是一个死循环 
		for(i=k,j=k;j<n-k&&t<N;j++){
			b[i][j]=a[t];
			t++;
		}
		for(i=k+1,j=n-k-1;i<m-k&&t<N;i++){
			b[i][j]=a[t];
			t++;
		}
		for(i=m-k-1,j=n-k-2;j>=k&&t<N;j--){
			b[i][j]=a[t];
			t++;
		}
		for(i=m-k-2,j=k;i>k&&t<N;i--){
			b[i][j]=a[t];
			t++;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(j!=n-1){
				printf("%d ",b[i][j]);
			}else{
				printf("%d\n",b[i][j]);
			}
		}
	}
	return 0;
}
