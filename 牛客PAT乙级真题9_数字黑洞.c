#include <stdio.h>
const int Kaprekar=6174;
int i=0,j=0;
int temp=0;
int a,b;//被减数和减数 
void sort(int *n);
void assign(int *n,int N); 
int N;
int main(){
	
	scanf("%d",&N);
	int n[4];
	assign(n,N);
	if(N==Kaprekar){
		sort(n);
	}
	
	if(((n[0]==n[1])&&(n[1]==n[2]))&&(n[2]==n[3])){
		printf("%04d - %04d = %04d",N,N,N-N);
	}else{
		while(N!=Kaprekar){
			
			sort(n);
			if(N!=Kaprekar){
				//printf("%d%d%d%d - %d%d%d%d = %d\n",n[3],n[2],n[1],n[0],n[0],n[1],n[2],n[3],N);
				printf("%04d - %04d = %04d\n",a,b,N);
				//printf("%04d - %04d = %04d",a,b,N);
			}
			assign(n,N);
		}
	} 
	return 0;
} 

void sort(int *n){
	
	
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(n[j]>n[j+1]){
			temp=n[j];
			n[j]=n[j+1];
			n[j+1]=temp;
			}
		}
	}
	a=1000*n[3]+100*n[2]+10*n[1]+n[0];
	b=1000*n[0]+100*n[1]+10*n[2]+n[3];
	N=a-b;
	if(N==Kaprekar){
		printf("%04d - %04d = %04d",a,b,N);
	}	
} 
void assign(int *n,int N1){
	int i;
	for(i=0;i<4;i++){
		n[i]=N1%10;
		N1=N1/10;
	}
}
