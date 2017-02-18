#include <stdio.h>
int main(){
	long A;
	long B,E[30];
	long C=0;
	int i=0;
	int D;
	int count=0;
	scanf("%ld%ld",&A,&B);
	scanf("%d",&D);
	C=A+B;
	if(C==0){
		printf("%ld",C);
	} 
	for(i=0;C!=0;i++){	
		E[i]=C%D;
		C=C/D;
		count++;
	}
	for(i=count-1;i>=0;i--){
		printf("%d",E[i]);
	}
	return 0;
} 
