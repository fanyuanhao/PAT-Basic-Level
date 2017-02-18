#include <stdio.h>
#include <string.h>
int main(){
	char str[100005];
	int i,sum=0,cnt0=0,cnt1=0;
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]>='a'&&str[i]<='z'){
			sum+=str[i]-'a'+1;
		}
		if(str[i]>='A'&&str[i]<='Z'){
			sum+=str[i]-'A'+1;
		}
	}
	//printf("%d ",sum);
	while(sum!=0){
		if(sum%2==0){
			cnt0++;
		}else{
			cnt1++;
		}
		sum/=2;
	}
	printf("%d %d",cnt0,cnt1);
	return 0;
}
