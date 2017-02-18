#include <stdio.h>
#include <string.h>
int main(){
	char a[85];
	gets(a);
	int i=0,N,j=0;
	N=strlen(a);
	int end=N;
	int begin;
	for(i=N-1;i>=0;i--){
		if((a[i]==' ')||(i==0)){
			begin=i;
			if(i==0){
				for(j=0;j<end;j++){
					printf("%c",a[j]);
				}
			}else{
				for(j=begin+1;j<end;j++){
					printf("%c",a[j]);
					if(j==end-1){
						printf(" ");
					}
				}
			}
			
			end=begin;
		}
		
	}
	
	return 0;
} 
