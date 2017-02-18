#include <stdio.h>
#include <math.h>
//方法就是用数字取余，把数变成个位数，然后找某个相同的数纪录次数 
int find(int A,int DA);

int main(){
	
	int A,B,DA,DB,PA,PB;
	
	
	scanf("%d%d%d%d",&A,&DA,&B,&DB);
	PA=find(A,DA);
	PB=find(B,DB);
	printf("%d",PA+PB);
	return 0;
} 
int find(int A,int DA){
	//在其他函数也要的时候才需要定义全局变量，否则的多次调用该函数不归零 
	int count=0;
	int i;
	int sum=0;
	int a=0;//存放AB取余的值
	for(i=0;A!=0;i++){
		a=A%10; 
		if(a==DA){
			count++;
		}
		A=A/10;
		
	}	
	
	for(--count;count!=-1;count--){
		sum+=pow(10,count)*DA;
		//printf("%d\n",sum);测试用的 
	}
	return sum;
}
