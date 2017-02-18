#include <stdio.h>
int main(){
	int hh,mm,ss,t;
	int C1,C2,TC;
	scanf("%d%d",&C1,&C2);
	TC=C2-C1;
	if((TC%100)>=50){
		t=TC/100+1;
	}else{
		t=TC/100;
	}
	printf("%02d:%02d:%02d",t/3600,t%3600/60,t%3600%60);
	return 0;
} 
