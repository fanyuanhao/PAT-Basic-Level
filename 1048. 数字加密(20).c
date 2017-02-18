#include <stdio.h>
#include <string.h>
int main(){
	char a[101];
	char b[101];
	scanf("%s %s",a,b);
	int len_a;
	int len_b;
	len_a=strlen(a);
	len_b=strlen(b);
	//char A[len_a+1];len_a<len_b，不够的话还要补0，数组不能知道len_a 
	//char B[len_b+1];
	//char C[len_b+1];
	char A[101];
	char B[101];
	char C[101];
	int c;//每一位的结果
	char d[13]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'}; 
	int i,j;
	for(i=1,j=len_a-1;i<=len_a;i++,j--){
		A[i]=a[j];
	}
	for(i=1,j=len_b-1;i<=len_b;i++,j--){
		B[i]=b[j];
	}
	int max=len_a;
	if(len_b>len_a){
		max=len_b;
	}
	if(len_a<len_b){
		for(i=len_a+1;i<=len_b;i++){
			A[i]='0';
		}
	}else{
		for(i=len_b+1;i<=len_a;i++){
			B[i]='0';
		}
	}
	for(i=1;i<=max;i++){
		if(i%2!=0){
			c=(A[i]-'0'+(B[i]-'0'))%13;
			C[i]=d[c];
		}else{
			c=B[i]-'0'-(A[i]-'0');
			if(c<0){
				c=c+10;
			}
			C[i]=d[c];
		}
	}
	for(i=max;i>=1;i--){
		printf("%c",C[i]); 
	}
	return 0;
}
