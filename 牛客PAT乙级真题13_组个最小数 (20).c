#include <stdio.h>
int main(){
	int a[10];
	int i=0;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	//����С���� 
	/*
	for(i=1;a[i]!=0;i++){//���ѭ���������õĲ��ã����a[1]=0�Ļ�ѭ���Ͳ����� 
		printf("%d",i);//Ҫ������ѭ���������������ѭ����ֹ������ 
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
	 
	//���������С�������
	for(i=0;i<10;i++){
		while(a[i]!=0){
			printf("%d",i);
			a[i]--;
		}		
	}
	
	return 0;
}
