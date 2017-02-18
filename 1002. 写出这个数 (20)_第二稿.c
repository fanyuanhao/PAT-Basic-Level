#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	char a[100];
	scanf("%s",a);
	int len;
	len=strlen(a);
	int sum=0,i=0,j=0;
	char *b[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int c[3]={10,10,10};
	for(i=0;i<len;i++){
		sum+=(a[i]-'0');
	}
	if(sum==0){
		printf("ling");
		return 0;
	}
	for(i=0;sum>0;i++){
		c[i]=sum%10;
		sum=sum/10;
	}
	
	for(j=i-1;j>=0;j--){
		if(c[j]!=10){
			if(j==0){
				printf("%s",b[c[j]]);
			}else{
				printf("%s ",b[c[j]]);
			}
			
		}
	}
	
	return 0;
} 
