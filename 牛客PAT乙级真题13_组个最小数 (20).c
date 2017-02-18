#include <stdio.h>
int main(){
	int a[10];
	int i=0;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	//找最小的数 
	/*
	for(i=1;a[i]!=0;i++){//这个循环条件设置的不好，如果a[1]=0的话循环就不进入 
		printf("%d",i);//要区分清循环进入的条件，和循环终止的条件 
		a[i]=a[i]-1;
		break;
	}
	*/
	for(i=1;i<10;i++){
		if(a[i]!=0){
			printf("%d",i); 
			a[i]=a[i]-1;
			break;
		}
	} 
	 
	//依次输出从小到大的数
	for(i=0;i<10;i++){
		while(a[i]!=0){
			printf("%d",i);
			a[i]--;
		}		
	}
	
	return 0;
}
