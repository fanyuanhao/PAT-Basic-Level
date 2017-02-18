#include <stdio.h>
#include <string.h>
struct node{
	char name[9];//不超过8个英文字母，要留一个放结束符的位置 
	int height;
};
void nameprint(struct node *p,int m);
int cmp(const void *a,const void *b){
	struct node *aa=(struct node *)a;
	struct node *bb=(struct node*)b;
	
	if(aa->height!=bb->height){
		return bb->height-aa->height;//height按降序 
	}else{
		return strcmp(aa->name,bb->name);//name按升序 
	}
}
int main(){
	int N,K,m,rest;
	scanf("%d%d",&N,&K);
	m=N/K;
	rest=N%K;
	struct node people[N];
	int i=0,j=0,cnt=0,M;
	for(i=0;i<N;i++){
		scanf("%s%d",people[i].name,&people[i].height);
	}
	qsort(people,N,sizeof(people[0]),cmp);
	
	if(rest==0){
		for(i=0;i<N;i+=m){//i是数组的下标，每次走一行 
			nameprint(people+i,m);//people+i是每行的头指针 
		}
	}else{
		nameprint(people,rest+m);
		for(i=rest+m;i<N;i+=m){
			nameprint(people+i,m);
		}
	}
	
	return 0;
}
void nameprint(struct node *p,int m){
	int i;
	int start=(m%2==0)?(m-1):(m-2);
	
	for(i=start;i>0;i-=2){//i不能等于0 
		printf("%s ",p[i].name);
	}
	
	for(i=0;i<m;i+=2){
		printf("%s",p[i].name);
		if(i==m-1||i==m-2){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}
