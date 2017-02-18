//这个代码就差一个测试点过不去，说是段错误，不知道问题在什么地方？ 
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int K;
	scanf("%d",&K);
	int a[K];//存放读进来的数字
	
	int i=0,j=0,w=0,temp=0;
	for(i=0;i<K;i++){
		scanf("%d",&a[i]);
	}
	int b[100][100];//用来存放被覆盖的值，第一个下标为要判断的数
	
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			b[i][j]=0;
		}
	}
	
	//把被覆盖的值存到二维数组中 
	for(i=0;i<K;i++){
		j=0;
		temp=a[i];
		while(temp>1){
			if(temp%2==0){
				temp/=2;
				if(temp<=100){
					b[a[i]][j]=temp;
					j++;
				}
			}else{
				temp=(3*temp+1)/2;
				if(temp<=100){
					b[a[i]][j]=temp;
					j++;
				}
			}
		}
	}
	//扫描输入的值和被覆盖的值将数列中被其他数覆盖的数换成0 
	for(i=0;i<K;i++){
		if(a[i]==0){
			continue;
		}
		for(w=0;w<K;w++){
			for(j=0;j<100;j++){
		
				if(a[i]==b[a[w]][j]){
					a[i]=0;
				}
			}
		}
	}
	
	int c[100];//将关键数存到数组中
	j=0;
	for(i=0;i<K;i++){	
		if(a[i]!=0){
			c[j]=a[i];
			j++;
		}
	}
	
	qsort(c,j,sizeof(c[0]),cmp);
	for(i=0;i<j;i++){
		if(i==j-1){
			printf("%d",c[i]);
		}else{
			printf("%d ",c[i]);
		}
		
	}
	
	return 0;
} 
