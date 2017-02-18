#include <stdio.h>
#include <stdlib.h> 
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int N,p;
	scanf("%d",&N);
	scanf("%d",&p);
	int a[N];
	int m,M,V,i,j;//最小值、最大值、m*p的值
	int cnt=1;
	
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	//对数组从小到大排序
	qsort(a,N,sizeof(a[0]),cmp); 
	
	for(i=0;i<N;i++){
		m=a[i];
		V=m*p;//因为m和p都可能是10的9次方，所以如果V用int类型就表示不了了 
		for(j=i+cnt;j<N;j++){
			if(a[j]>V){
				break;
			}
			cnt++;
		}
	}

	printf("%d",cnt);
	
	return 0;
}
