#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	int i=0,j=0;
	char test[100];
	char TEST[100];
	float a,sum=0.0;
	int len,flag,cnt=0;
	for(i=0;i<N;i++){
		scanf("%s",test);
		len=strlen(test);
		flag=0;
		sscanf(test,"%f",&a);
		sprintf(TEST,"%.2f",a);
		for(j=0;j<len;j++){
			if(test[j]!=TEST[j]){
				flag=1;
				break;
			}
		}
		if(flag==1||a>1000||a<-1000){
			printf("ERROR: %s is not a legal number\n",test);
		}else{
			cnt++;
			sum+=a;
		}
	}
	if(cnt==0){
		printf("The average of %d numbers is Undefined",cnt);
	}else if(cnt==1){
		printf("The average of %d number is %.2f",cnt,sum);
	}else{
		printf("The average of %d numbers is %.2f",cnt,sum/cnt);
	}
	
	
	return 0;
} 
