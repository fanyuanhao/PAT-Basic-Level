#include <stdio.h>
#include <string.h>
int main(){
	int i=0;
	int B;
	char a[1000];
	char b[1000];
	scanf("%s",a);
	
	int len=strlen(a);//�������ַ��ĳ��ȣ������� 
	scanf("%d",&B);
	int q=0,r=0;//ģ��������̺�����
	int a1=0;//ģ������ı����� 
	//ģ���������
	
	for(i=0;i<len;i++){
		a[i]=a[i]-'0';//�������ַ�ת�������� 
		a1=r*10+a[i];//���챻���� 
			if(B>a1){//���������ڱ�������ʱ�� 
				q=0;
				r=a1;
				//������ˣ���A��һλ����ʱ���̿���Ϊ0//if(i!=0){//��һλ�������ڱ��������̲���Ϊ0
				if((i!=0)||(len==1)){
					printf("%d",q);
				}
			}else{
				q=a1/B;
				r=a1%B;
				printf("%d",q);
			}		
	} 
	printf(" %d",r);
	
	return 0;
} 
