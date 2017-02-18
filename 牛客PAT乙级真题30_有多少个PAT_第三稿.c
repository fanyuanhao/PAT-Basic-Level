//将A字符转存到数组中也是运行超时 
#include <stdio.h>
#include <string.h>
int main(){
	char a[100000];
	int i=0,j=0,k=0,w=0;
	scanf("%s",a);
	int N=strlen(a);
	int P=0,T=0;//纪录P、T的数组下标
	int cnt_P=0,cnt_T=0;
	int sum=0;//PAT的个数 
	//寻找A，把它的下标存在数组中 
	int b[100000]; 
	for(i=0;i<N;i++){
		if(a[i]=='A'){
			b[w]=i;
			w++;
		}
	}
	

	for(i=0;i<w;i++){
		cnt_P=0;
		cnt_T=0;
		for(j=0;j<b[i];j++){
			if(a[j]=='P'){
				cnt_P++;
			}
		}
		for(k=N-1;k>b[i];k--){
			if(a[k]=='T'){
				cnt_T++;
			}
		}
		sum+=(cnt_P*cnt_T);	
	}
	 
	printf("%d",sum%1000000007);

	return 0;
}
