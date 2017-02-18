//两层循环还是运行超时 
#include <stdio.h>
#include <string.h>
int main(){
	char a[100000];
	int i=0,j=0,k=0;
	scanf("%s",a);
	int N=strlen(a);
	int P=0,A=0,T=0;//纪录PAT的数组下标
	int cnt_P=0,cnt_T=0;
	int sum=0;//PAT的个数 
	//寻找A 
	for(i=0;i<N;i++){
		if(a[i]=='A'){
			A=i;
		
			cnt_P=0;
			cnt_T=0;
			for(j=0;j<A;j++){
				if(a[j]=='P'){
					cnt_P++;
				}
			}
			for(k=N-1;k>A;k--){
				if(a[k]=='T'){
					cnt_T++;
				}
			}
			sum+=(cnt_P*cnt_T); 
		}
	}
	printf("%d",sum%1000000007);
	return 0;
}
