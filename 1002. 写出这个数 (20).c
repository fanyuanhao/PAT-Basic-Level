//������������⡣���ַֽ�sumλ���ķ������ã������100�Ļ�������������0 
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	char a[100];
	scanf("%s",a);
	int len;
	len=strlen(a);
	int sum=0,i=0;
	char *b[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int quotient,divisor;
	for(i=0;i<len;i++){
		sum+=(a[i]-'0');
	}
	if(sum==0){
		printf("ling");
	}
	
	//���ַֽ�sumλ���ķ������ã������100�Ļ�������������0 
	for(i=3;i>0;i--){//i��ʾλ�� 
		divisor=pow(10,i-1);
		quotient=sum/divisor;
		if(quotient!=0){
			if(i==1){
				printf("%s",b[quotient]);
				sum=sum%divisor;
			}else{
				printf("%s ",b[quotient]);
				sum=sum%divisor;
			}
		}
	}
	
	 
	return 0;
} 
