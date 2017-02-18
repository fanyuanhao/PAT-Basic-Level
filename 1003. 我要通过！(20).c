#include <stdio.h>
#include <string.h>
int main(){
	int N,i=0,j=0,cntp=0,cntt=0,cnt_other=0,lp,lt,len;
	scanf("%d",&N);
	char a[10][100];
	for(i=0;i<N;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<N;i++){
		len=strlen(a[i]);
		cntt=0,cntp=0,cnt_other=0;
		for(j=0;a[i][j]!='\0';j++){
			if(a[i][j]=='P'){
				cntp++;
				lp=j;//¼ÍÂ¼PµÄÎ»ÖÃ 
			}else if(a[i][j]=='T'){
				cntt++;
				lt=j;
			}else if(a[i][j]!='A'){
				cnt_other++;
			}
		}
		if(cntp>1||cntt>1||cnt_other!=0||lt-lp<2){
				printf("NO\n");
			}else if(lp*(lt-lp-1)!=(len-lt-1)){
				printf("NO\n");
			}else{
				printf("YES\n");
		}
	}	
	return 0;
} 
