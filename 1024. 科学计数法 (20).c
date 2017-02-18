#include <stdio.h>
#include <string.h>
int main(){
	char A[10000];
	char d[10000];
	int exp=0;
	scanf("%s",A);
	int len=strlen(A);
	int i=0,j=0,k=0;
	int flag=1;
	char a,b,c;
	for(i=0;i<len;i++){
				
		if(A[i]=='E'){
			flag=0;
		}
		
		c=A[i];
		
		if(i==0&&(c=='+'||c=='-')){
			a=c;//a存的是第一个正负号 
			if(a=='-'){
				printf("%c",a);
			}
		}
		
		if(i!=0&&(c=='+'||c=='-')){
			b=c;//b存的是第二个正负号 
		}
		
		if(flag&&(c>='0'&&c<='9')){
			d[j]=c;
			j++;
		}
				
		if((flag==0)&&(c>='0'&&c<='9')){
			exp=exp*10+(c-'0');
		}
	}
	
	if(b=='-'){
		printf("0.");
		while(exp-1){
			printf("0");
			exp--;
		}
		for(i=0;i<j;i++){
			printf("%c",d[i]);
		}
	}
	if(b=='+'){
		if(j-1<=exp){
			for(i=0;i<j;i++){
				printf("%c",d[i]);
			}
			while(exp-j+1){
				printf("0");
				exp--;
			}
		}else{
			for(i=0;i<=exp;i++){
				printf("%c",d[i]);
			}
			printf(".");
			for(i=exp+1;i<j;i++){
				printf("%c",d[i]);
			}
		}
	}
	
	return 0;
} 
