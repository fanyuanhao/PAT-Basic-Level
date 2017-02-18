#include <stdio.h>
int main(){
	int N,i;
	int a[4];
	int cnt_a=0,cnt_b=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
		if(a[1]==a[3]){
			continue;
		} 
		if(a[1]==a[0]+a[2]){
			cnt_b++;//¼×ÊäÒÒÓ® 
		}
		if(a[3]==a[0]+a[2]){
			cnt_a++;
		}
	}
	printf("%d %d",cnt_a,cnt_b);
	
	return 0;
} 
