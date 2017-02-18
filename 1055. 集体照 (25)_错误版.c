//这个方案，题目要求是结尾按名字排序，之前的数组高度相同按名字排序，结尾再按名字排序的话就很乱。 
#include <stdio.h>
#include <string.h>
struct node{
	char name[8];
	int height;
};
int cmp(const void *a,const void *b){
	struct node *aa=(struct node *)a;
	struct node *bb=(struct node*)b;
	
	if(aa->height!=bb->height){
		return aa->height-bb->height;
	}else{
		return strcmp(aa->name,bb->name);
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
	for(i=0;i<N;i++){
		printf("%s %d\n",people[i].name,people[i].height);
	}
	struct node person[K-1][m]; 
	struct node Person[m+rest];//the last line
	//先不考虑最后一行 
	for(i=0;i<K-1;i++){
		cnt=m-1;
		for(j=m/2;cnt>=0;j--){
			//先把中间值放上 
			if(cnt==m-1){
				person[i][j].height=people[i*m+cnt].height;
				strcpy(person[i][j].name,people[i*m+cnt].name);
				cnt--;
				continue;
			}
			//右面放一个 
			if(cnt>=0&&m-j>0){
				person[i][m-j].height=people[i*m+cnt].height;
				strcpy(person[i][m-j].name,people[i*m+cnt].name);
				cnt--;
			}
			//左面放一个 
			if(cnt>=0){
				person[i][j].height=people[i*m+cnt].height;
				strcpy(person[i][j].name,people[i*m+cnt].name);
				cnt--;
			}
		}
	}
	//最后一行
	int temp=N-1;
	for(j=(m+rest)/2;temp>=(K-1)*m;j--){
		//先把中间值放上
		if(temp==N-1){
			Person[j].height=people[temp].height;
			strcpy(Person[j].name,people[temp].name);
			temp--;
			continue;
		}
		//右面放一个 
		if(temp>=0&&m-j>0){
			Person[m-j].height=people[temp].height;
			strcpy(Person[m-j].name,people[temp].name);
			temp--;
		}
		//左面放一个 
		if(temp>=0){
			Person[j].height=people[temp].height;
			strcpy(Person[j].name,people[temp].name);
			temp--;
		}
	}
	for(i=m+rest-1;i>=0;i--){
		if(i==0){
			printf("%s",Person[i].name);
			printf("\n");
		}else{
			printf("%s ",Person[i].name);
		}
	}
	
	for(i=K-1;i>=0;i--){
		for(j=m-1;j>=0;j--){
			if(j==0){
				printf("%s\n",person[i][j].name,person[i][j].height);
			}else{
				printf("%s ",person[i][j].name,person[i][j].height);
			}
		}
	}
	
	
	return 0;
}
