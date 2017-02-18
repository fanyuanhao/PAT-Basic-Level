#include <stdio.h>
#include <string.h>
typedef struct node{
	char a[5];
	int year;
	int month;
	int day;
}BirthIn;


int main(){
	int N,i=0,cnt=0;
	//读入相应信息 
	scanf("%d",&N);
	BirthIn A[N];	
	for(i=0;i<N;i++){
		scanf("%s",A[i].a);
		scanf("%d/%d/%d",&A[i].year,&A[i].month,&A[i].day);
	}
	//过滤无效生日
	for(i=0;i<N;i++){
		if((A[i].year<1814)||((A[i].year==1814)&&(A[i].month<9))||(((A[i].year==1814)&&(A[i].month==9))&&(A[i].day<6))){
			A[i].year=0;
			cnt++;
		}
		if((A[i].year>2014)||((A[i].year==2014)&&(A[i].month>9))||(((A[i].year==2014)&&(A[i].month==9))&&(A[i].day>6))){
			A[i].year=0;
			cnt++;
		}
	} 
	//寻找最年长，最年轻
	//int max=0,min=0;//max最年轻的下标，不能直接用下标0作为最大或最小，0这个位置上可能是过滤掉的 
	int max=-1,min=-1;
	 
	for(i=0;i<N;i++){
		if(A[i].year!=0){
			max=i;
			min=i;
		}
	} 
	for(i=0;i<N;i++){
		if(A[i].year!=0){
			if((A[i].year>A[max].year)||((A[i].year==A[max].year)&&(A[i].month>A[max].month))||(((A[i].year==A[max].year)&&(A[i].month==A[max].month))&&(A[i].day>A[max].day ))){
				max=i;
			}
			/*错误出在这里有一个符号写反了。写代码的时候复制粘贴有风险，不是完全相同的少改一个条件找找好长时间 
			if((A[i].year<A[min].year)||((A[i].year==A[min].year)&&(A[i].month<A[min].month))||(((A[i].year==A[min].year)&&(A[i].month==A[min].month))&&(A[i].day>A[min].day ))){
				min=i;
			}
			*/
			if((A[i].year<A[min].year)||((A[i].year==A[min].year)&&(A[i].month<A[min].month))||(((A[i].year==A[min].year)&&(A[i].month==A[min].month))&&(A[i].day<A[min].day ))){
				min=i;
			}		
		}		
	}
	/*
	另一种寻找最大值最小值的方法 
	BirthIn Max,Min;
	Max.year=1814;Max.month=9;Max.day=5;
	Min.year=2014;Min.month=9;Min.day=7;
	int max=-1,min=-1;  
	for(i=0;i<N;i++){
		if(A[i].year!=0){
			if((A[i].year>Max.year)||((A[i].year==Max.year)&&(A[i].month>Max.month))||(((A[i].year==Max.year)&&(A[i].month==Max.month))&&(A[i].day>Max.day ))){
				Max.year=A[i].year;Max.month=A[i].month;Max.day=A[i].day;
				max=i;
			}
			if((A[i].year<Min.year)||((A[i].year==Min.year)&&(A[i].month<Min.month))||(((A[i].year==Min.year)&&(A[i].month==Min.month))&&(A[i].day<Min.day ))){
				Min.year=A[i].year;Min.month=A[i].month;Min.day=A[i].day;
				min=i;
			}		
		}		
	}
	*/
	if((max==-1)&&(min==-1)){
		printf("0");
	}else{
	 	printf("%d ",N-cnt);
		printf("%s ",A[min].a);
		printf("%s",A[max].a);
	}
	

	return 0;
}
