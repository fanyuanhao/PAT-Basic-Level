#include <stdio.h>
int main(){
	int a[2050];
	char c;
	int i=0,j=0;
	do{
		scanf("%d",&a[i]);
		scanf("%c",&c);
		i++;
		j++;
	}while(c!='\n');
	
	int end=a[i-1];
	int num=i;
	
	if((end==0)&&(i>2)){
		end=a[i-3];
	}
	
	for(i=0;i<num;i+=2){
		if(end!=0){
			if(a[i+1]==end){
				printf("%d %d",a[i]*a[i+1],a[i+1]-1);
				break;
			}else{
				printf("%d %d ",a[i]*a[i+1],a[i+1]-1);
			}
		}
		if((i==0)&&(a[i+1]==0)){
			printf("0 0");
		}
	}
	return 0;
}
