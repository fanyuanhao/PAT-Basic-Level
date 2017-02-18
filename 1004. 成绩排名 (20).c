#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	struct node{
		char name[11];
		char num[11];
		int score;
	};
	struct node a[N];
	int i=0,max=0,min=0;
	for(i=0;i<N;i++){		
		scanf("%s%s%d",a[i].name,a[i].num,&a[i].score);
	}
	
	for(i=0;i<N;i++){
		if(a[i].score>a[max].score){
			max=i;
		}
		if(a[i].score<a[min].score){
			min=i;
		}
	}
	
	printf("%s %s\n",a[max].name,a[max].num);
	printf("%s %s",a[min].name,a[min].num);
	
	return 0;
} 
