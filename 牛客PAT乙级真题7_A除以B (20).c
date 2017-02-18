#include <stdio.h>
#include <string.h>
int main(){
	int i=0;
	int B;
	char a[1000];
	char b[1000];
	scanf("%s",a);
	
	int len=strlen(a);//求数字字符的长度（个数） 
	scanf("%d",&B);
	int q=0,r=0;//模拟运算的商和余数
	int a1=0;//模拟运算的被除数 
	//模拟除法运算
	
	for(i=0;i<len;i++){
		a[i]=a[i]-'0';//将数字字符转换成数字 
		a1=r*10+a[i];//构造被除数 
			if(B>a1){//当除数大于被除数的时候 
				q=0;
				r=a1;
				//这里错了，当A是一位数的时候，商可以为0//if(i!=0){//第一位除数大于被除数，商不能为0
				if((i!=0)||(len==1)){
					printf("%d",q);
				}
			}else{
				q=a1/B;
				r=a1%B;
				printf("%d",q);
			}		
	} 
	printf(" %d",r);
	
	return 0;
} 
