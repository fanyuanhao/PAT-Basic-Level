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
	if(i.Uprice>j.Uprice){
		return 1;
	}esle{
		return -1;
	}
	
}
*/
int main(){
	
	scanf("%d%d",&N,&D);
	
	int i=0,j=0;
	int temp1;
	double temp2,temp3;
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
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
	}
	*/
	
	//调用快速排序函数，目前还是不太懂 
	//qsort(a,N,sizeof(a[0]),cmp); 
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n"); 
	}
	*/ 
	/* 
	//按单价从大到小排序冒泡排序 
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(a[j].Uprice<a[j+1].Uprice){
				temp1=a[j].store;
				temp2=a[j].Tprice;
				temp3=a[j].Uprice;
				
				a[j].store=a[j+1].store;
				a[j].Tprice=a[j+1].Tprice;
				a[j].Uprice=a[j+1].Uprice;
				
				a[j+1].store=temp1;
				a[j+1].Tprice=temp2;
				a[j+1].Uprice=temp3;
			}
		}
	}
	
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n"); 
	}
	*/
	/*
	选择排序法1 
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
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n");
	}
	*/
	//选择排序法2 
	int max=0;
	for(i=0;i<N-1;i++){
		max=i;
		for(j=i;j<N;j++){
			if(a[max].Uprice<a[j].Uprice){// 
				max=j;
			}
		}
		if(max!=i){
			temp1=a[max].store;
			temp2=a[max].Tprice;
			temp3=a[max].Uprice;
				
			a[max].store=a[i].store;
			a[max].Tprice=a[i].Tprice;
			a[max].Uprice=a[i].Uprice;
				
			a[i].store=temp1;
			a[i].Tprice=temp2;
			a[i].Uprice=temp3;	
		}
	}
	 
	/*
	for(i=0;i<N;i++){
		printf("%lf\n",a[i].store);
		printf("%lf\n",a[i].Tprice);
		printf("%lf\n",a[i].Uprice);
		printf("\n");
	}
	*/ 
	
	
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
	
	
	
	/* 
	for(i=0;i<N;i++){//找到哪种品种>D 
		sum+=a[i].store;//较贵的东西的库存
		
		if(sum<=D){//如果较贵的库存不足需求时
			profit+=a[i].Tprice;//利润
			surplus=D-sum;//距离需求的差值
		}
        if(sum>D&&(i==0)){//如果i=0时的库存大于总需求
			printf("%.2lf",a[i].Uprice*D);
            break;
		}
        if(sum>D&&(i!=0)){//到某个值时较贵的库存已满足需求
			printf("%.2lf",profit+a[i].Uprice*surplus);
			break;
		}
	}//如果所有库存始终不满足需求
	if(sum<=D){
		printf("%.2lf",profit);
	}
	*/ 
	return 0;
} 
