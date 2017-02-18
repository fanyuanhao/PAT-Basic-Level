#include <stdio.h>
void simplify(int *a,int *b);
int max(int *a);
int main(){
	int a1,b1,a2,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	simplify(&a1,&b1);
	simplify(&a2,&b2);
	printf("%d/%d %d/%d",a1,b1,a2,b2);
	
	return 0;
}

void simplify(int *a,int *b){
	int i=0,m=0,k=0,j=0,w=0;
	//找a的因子
	int A[*a];
	int B[*b];
	
	int C[100]={0};
	for(i=0;i<(*a);i++){
		if((*a)%i==0){
			A[k]==i;
			k++;
		}
	}
	//找b的因子 
	for(i=0;i<(*b);i++){
		if((*b)%i==0){
			B[j]==i;
			j++;
		} 
	}
	//找a,b的公因子 
	for(i=0;i<k;i++){
		for(m=0;m<j;m++){
			if(A[i]==B[m]){
				C[w]=A[i];
				w++;
			}
		} 
	}
	if(w==0){
	}else{
		*a=*a/max(C);
		*b=*b/max(C);
	}
	
}
int max(int *a){
	int *p=a;
	int MAX=*p;
	for(p=a;*p!='\0';p++){
		if(*p>MAX){
			MAX=*p;
		}
	}
	return MAX;
}
