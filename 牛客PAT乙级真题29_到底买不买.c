#include <stdio.h>
#include <string.h>
int main(){
	char A[1000];
	char B[1000];
	char *a=A;
	char *b=B;
	scanf("%s",a);
	scanf("%s",b);
	int i,j,flag1=0,flag2=0,cnt=0;
	for(i=0;i<strlen(B);i++){
		flag1=0;
		for(j=0;j<strlen(A);j++){
			if(b[i]==a[j]){
				a[j]='&';
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			b[i]='&';
			flag2=1;
		}
	}
	if(flag2!=0){
		printf("No ");
		for(i=0;i<strlen(B);i++){
			if(b[i]=='&'){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}else{
		printf("Yes %d",strlen(A)-strlen(B));
		
	}
	
	return 0;
} 
