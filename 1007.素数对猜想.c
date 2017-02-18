#include <stdio.h>
#include <math.h>
int main(){
	int N;
	scanf("%d",&N);
	int i=0,j=0,w=0,count=0;
	int gen;
	int a[N]; 
	a[w]=2;
	w++;
	a[w]=3;
	w++;
	//判断是不是素数 
	for(i=5;i<=N;i+=2){//i要判断的这个数 
		gen=sqrt(i);
		for(j=2;j<=gen;j++){
			if(i%j==0){
				break;
			}
			if(j==gen){
				a[w]=i;
				w++;
			}
		}
		
	}
	//判断相邻的两个素数是不是相差2 
	for(i=1;i<w;i++){
		if(a[i]-a[i-1]==2){
			count++;
		}
	}
	printf("%d",count);
	
	return 0;
} 
