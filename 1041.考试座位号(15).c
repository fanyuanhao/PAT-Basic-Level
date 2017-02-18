//ÕýÈ· 
#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	struct node {
		long long num;
		int exam;
	};
	struct node a[N+1];
	int i;
	int Try,Exam;
	long long Num;
	
	for(i=1;i<=N;i++){
		scanf("%lld%d%d",&Num,&Try,&Exam);
		a[Try].num=Num;
		a[Try].exam=Exam;
	}
	
	int M;
	scanf("%d",&M);
	
	int c;
	for(i=0;i<M;i++){
		scanf("%d",&c);
		if(i==M-1){
			printf("%lld %d",a[c].num,a[c].exam);
		}else{
			printf("%lld %d\n",a[c].num,a[c].exam);
		}
	}
	return 0;
}
