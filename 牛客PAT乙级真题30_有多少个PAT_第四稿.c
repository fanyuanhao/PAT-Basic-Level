#include <stdio.h>
#include <string.h> 
int main(){
	char a[100000];
	int i=0;
	scanf("%s",a);
	int N=strlen(a);
	int num_T=0,num_AT=0,num_PAT=0;
	for(i=N-1;i>=0;i--){
		if(a[i]=='T'){
			num_T++;
		}else if(a[i]=='A'){
			num_AT=(num_AT+num_T)%1000000007;
		}else if(a[i]=='P'){
			num_PAT=(num_PAT+num_AT)%1000000007;
		}
		
	}
	printf("%d",num_PAT%1000000007);
	return 0;
} 
