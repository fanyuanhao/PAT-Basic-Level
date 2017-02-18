#include <stdio.h>
#include <math.h>
int main(){
	double R1,P1,R2,P2,A1,B1,A2,B2,A3,B3;
	scanf("%lf%lf%lf%lf",&R1,&P1,&R2,&P2);
	
	A1=R1*cos(P1);
	B1=R1*sin(P1);
	A2=R2*cos(P2);
	B2=R2*sin(P2);
	
	A3=A1*A2-B1*B2;
	B3=A1*B2+A2*B1;
	if(fabs(A3)<0.01){
		A3=0;
	}
	if(fabs(B3)<0.01){
		B3=0;
	}
	
	if(B3>=0&&A3!=0){
		printf("%.2lf+%.2lfi",A3,B3);	
	}
	if(B3<0){
		printf("%.2lf%.2lfi",A3,B3);
	}
	if(B3==0&&A3==0){
		printf("0");
	} 
	return 0;
}
