#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	char a[7];//������ͳ�Ա��� 
	int len;//�����Ա����ַ��ĳ��� 
	int b[1000]={0};//��ÿ��������ܳɼ� 
	int i,j;
	int num=0;//��ʱ�����������
	int score;//���ɼ�
	int cnt;//��¼-���±� 
	for(i=0;i<N;i++){
		scanf("%s%d",a,&score);
		len=strlen(a);
		
		for(j=0;j<len;j++){
			if(a[j]=='-'){
				cnt=j;
			}
		}
		num=0;
		for(j=0;j<cnt;j++){
			num=num*10+a[j]-'0';
		}
		b[num]+=score;
	}
	int max=0;
	int MAX=0;//��¼���ֵ���±� 
	for(i=0;i<1000;i++){
		if(b[i]>max){
			max=b[i];
			MAX=i; 
		}
	}
	printf("%d %d",MAX,max);
	
	return 0;
} 
