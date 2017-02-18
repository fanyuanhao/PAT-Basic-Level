/*
第一稿运行超时，算法不好 
*/
#include <stdio.h>
#include <string.h>
int main(){
	char a[100000];
	int i=0,j=0,k=0;
	scanf("%s",a);
	int N=strlen(a);
	int P=0,A=0,T=0;//纪录PAT的数组下标
	int cnt=0;
	for(i=0;i<N;i++){
		if(a[i]=='P'){
			P=i;
		}else{
			continue;
		}
		for(j=P;j<N;j++){
			if(a[j]=='A'){
				A=j;
			}else{
				continue;
			}
			for(k=A;k<N;k++){
				if(a[k]=='T'){
					cnt++;
				}else{
					continue;
				}
			}
		}
	}
	
	
	printf("%d",cnt%1000000007); 
	
	return 0;
} 
