#include <stdio.h>
#include <string.h>
int main(){
	char a[1000];
	char *str;
	str=a;
	int i=0;
	int b;
	scanf("%s",a);
	int count[10]={0,0,0,0,0,0,0,0,0,0}; 
	int len=strlen(a);
	for(i=0;i<len;i++){
		b=*str-'0';
		if(b==0) count[0]++;
		if(b==1) count[1]++;
		if(b==2) count[2]++;
		if(b==3) count[3]++;
		if(b==4) count[4]++;
		if(b==5) count[5]++;
		if(b==6) count[6]++;
		if(b==7) count[7]++;
		if(b==8) count[8]++;
		if(b==9) count[9]++;
		str++;
	}
	for(i=0;i<10;i++){
		if(count[i]!=0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	
	
	return 0;
} 
