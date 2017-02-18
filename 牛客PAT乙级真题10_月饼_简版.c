#include <stdio.h>
#include <stdlib.h>
int N,D;
typedef struct node{
	double store;//库存可能不是整数可能不够需求 
	double Tprice;
	double Uprice;
} Good;
Good a[1005];
/*	
int cmp(const void *a,const void *b){
	Good i=*(Good*)a;
	Good j=*(Good*)b;
	return i.Uprice-j.Uprice;
}
*/ 
int main(){
	
	scanf("%d%d",&N,&D);
	int temp1;
	double temp2,temp3;
	int i=0,j=0;

	int last=0;
	double profit=0;
	
	for(i=0;i<N;i++){
		scanf("%lf",&a[i].store);
	}
	for(i=0;i<N;i++){
		scanf("%lf",&a[i].Tprice);
	}
	for(i=0;i<N;i++){
		a[i].Uprice=a[i].Tprice/a[i].store;
	}

	//qsort(a,N,sizeof(a[0]),cmp); 
	for(i=0;i<N-1;i++){
		for(j=i;j<N;j++){
			if(a[i].Uprice<a[j].Uprice){//当i=0时，只要是比i=0位置上大的值，换给它，直到换到最大的。从始至终倒在i=0这个位置 
				temp1=a[i].store;
				temp2=a[i].Tprice;
				temp3=a[i].Uprice;
				
				a[i].store=a[j].store;
				a[i].Tprice=a[j].Tprice;
				a[i].Uprice=a[j].Uprice;
				
				a[j].store=temp1;
				a[j].Tprice=temp2;
				a[j].Uprice=temp3;
			}
		}
	}
	last=D;
	for(i=0;last>0&&i<N;i++){
		if(a[i].store>last){
			profit+=last*a[i].Uprice;
		}else{
			profit+=a[i].Tprice;
		}
		last=last-a[i].store;
	}
	printf("%.2lf",profit);
	
	return 0;
} 
