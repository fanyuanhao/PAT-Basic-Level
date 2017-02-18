#include <stdio.h>
int main(){
	int N,i,j;
	int hang,lie;
	char c;
	scanf("%d",&N);
	getchar();
	scanf("%c",&c);
	lie=N;
	if((10*N/2%10)>=5){
		hang=N/2+1;
	}else{
		hang=N/2;
	}
	for(i=0;i<hang;i++){
		if(i==0||i==hang-1){
			for(j=0;j<lie;j++){
				printf("%c",c);
				if(j==lie-1){
					printf("\n",c);
				}
			}
		}else{
			for(j=0;j<lie;j++){
				if(j==0){
					printf("%c",c);
				}else if((j==lie-1)&&(i!=hang-1)){
					printf("%c\n",c);
				}else{
					printf(" ");
				}
			}
		}	
	}
	return 0;
}
