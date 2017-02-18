#include <stdio.h>
#include <math.h>
int main(){
	int N;
	int i=0;
	int A1=0,A2=0,A3=0,A5=0;
	double A4=0.0;
	
	int k=0;
	int j=0;
	double w=0.0;
	double sum=0.0;
	int max=0;
	
	scanf("%d",&N);
	int a[N];
	for(;i<N;i++){
		scanf("%d",&a[i]);
		if((a[i]%5==0) && (a[i]%2==0)){
			A1+=a[i];
		}
		if(a[i]%5==1){
			A2+=pow(-1,k)*a[i];//+=，指数求法 
			k++;
		}
		if(a[i]%5==2){
			j++;
		}
		if(a[i]%5==3){
			w++;
			sum+=a[i];
		}
		if(a[i]%5==4){
			if(a[i]>max){
				max=a[i];
			}
		}
	}
	

	A3=j;
	if(w!=0){//无论在什么地方使用除法的时候，都要考虑到除数不能等于0 
		A4=(sum/w);//sum和w都是整型的话，A4得到的结果去掉余数得到一个整数 
	}
	
	A5=max;
	if(A1==0){
		printf("N ");
	}else{
		printf("%d ",A1);
	}
	if(A2==0&&k==0){//题目中没有说不可以是相同数字，所以当对5取余，余数为1的值可能相同，可能A2等于0，所以还要确保k==0 
		printf("N ");
	}else{
		printf("%d ",A2);
	}
	if(A3==0){
		printf("N ");
	}else{
		printf("%d ",A3);
	}
	if(A4>0.000000001){
		printf("%.1lf ",A4);
	}else{
		printf("N ");
	}
	if(A5==0){
		printf("N");//注意最后要求没有空格 
	}else{
		printf("%d",A5);
	}
	
	return 0;
} 
