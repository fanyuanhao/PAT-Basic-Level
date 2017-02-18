#include <stdio.h>
int main(){
	int K,r,i=0;
	scanf("%d",&K);
	int a[10];//´æÊý×Ö
	char b[20];//´æ×Ö·û
	int count_A=0,count_B=0; 
	r=K%10;
	K=K/10;

	if((r==0)&&(K==0)){
		return 0;
	}

	if(r>0){
		while(r>0){
			a[i]=r;
			i++;
			r--;
			count_A++;
		}
	}

		
	r=K%10;	
	K=K/10;
	if((r==0)&&(K==0)){
		for(i=count_A-1;i>=0;i--){
			printf("%d",a[i]);
		}
		return 0;
	}
	
	if(r>0){	
		i=0;
		while(r>0){
			b[i]='S';
			i++;
			r--;
			count_B++; 
		}
	}

	
	r=K%10;	
	K=K/10;
	if((r==0)&&(K==0)){
		for(i=count_B-1;i>=0;i--){
			printf("%c",b[i]);
		}
		for(i=count_A-1;i>=0;i--){
			printf("%d",a[i]);
		}
		return 0;
	}
	if(r>0){	
		i=count_B;
		while(r>0){
			b[i]='B';
			i++;
			r--;
			count_B++;
		}
		for(i=count_B-1;i>=0;i--){
			printf("%c",b[i]);
		}
		for(i=count_A-1;i>=0;i--){
			printf("%d",a[i]);
		}
	}

	
	
	return 0;
} 
