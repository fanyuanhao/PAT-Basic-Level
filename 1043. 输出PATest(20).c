#include <stdio.h>
#include <string.h>
int main(){
	char a[10000];
	scanf("%s",a);
	int len=strlen(a);
	int i=0;
	int b[6]={0};
	for(i=0;i<len;i++){
		if(a[i]=='P'){
			b[0]++;
		}
		if(a[i]=='A'){
			b[1]++;
		}
		if(a[i]=='T'){
			b[2]++;
		}
		if(a[i]=='e'){
			b[3]++;
		}
		if(a[i]=='s'){
			b[4]++;
		}
		if(a[i]=='t'){
			b[5]++;
		}
	}
	while(1){
		if(b[0]!=0){
			printf("P");
			b[0]--;
		}
		if(b[1]!=0){
			printf("A");
			b[1]--;
		}
		if(b[2]!=0){
			printf("T");
			b[2]--;
		}
		if(b[3]!=0){
			printf("e");
			b[3]--;
		}
		if(b[4]!=0){
			printf("s");
			b[4]--;
		}
		if(b[5]!=0){
			printf("t");
			b[5]--;
		}
		if(b[0]==0&&b[1]==0&&b[2]==0&&b[3]==0&&b[4]==0&&b[5]==0){
			break;
		}
	}
	return 0;
} 
