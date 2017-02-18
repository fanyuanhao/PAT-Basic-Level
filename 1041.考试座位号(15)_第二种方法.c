#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	struct node {
		char num[14];
		int exam;
	};
	struct node a[N+1];
	int i;
	int Try,Exam;
	char Num[14];
	
	for(i=1;i<=N;i++){
		scanf("%s%d%d",Num,&Try,&Exam);
		strcpy(a[Try].num,Num);
		a[Try].exam=Exam;
	}
	
	int M;
	scanf("%d",&M);
	
	int c;
	for(i=0;i<M;i++){
		scanf("%d",&c);
		if(i==M-1){
			printf("%s %d",a[c].num,a[c].exam);
		}else{
			printf("%s %d\n",a[c].num,a[c].exam);
		}
	}
	return 0;
}
