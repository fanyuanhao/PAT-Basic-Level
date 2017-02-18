#include <stdio.h>
#include <math.h>
int main(){
	int N,n,i,j,an;
	char c;
	scanf("%d",&N);
	getchar();
	scanf("%c",&c);
	n=sqrt((N+1)/2);
	an=2*n-1;
	int wide=an;
	 
	for(i=0;i<n;i++){
		int k=0;
		for(j=0;j<wide;j++){
		
			if(j<i){
				printf(" ");
			}else if(k<an){
				printf("%c",c);
				k++;
			}
			if(j==wide-1){
				printf("\n");
			}
		}
		an-=2;
	}
	an+=4;
	for(i=n-2;i>=0;i--){
		int k=0;
		for(j=0;j<wide;j++){
		
			if(j<i){
				printf(" ");
			}else if(k<an){
				printf("%c",c);
				k++;
			}
			if(j==wide-1){
				printf("\n");
			}
		}
			an+=2;
	
		
	}
	int w=pow(n,2);
	printf("%d",N-(2*w-1));
	
	return 0;
}
