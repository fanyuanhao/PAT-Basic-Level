#include <stdio.h>
#include <string.h>
int main(){
	char a[1000];//������ַ��� 
	gets(a);
	int len=strlen(a);
	int i,j=0;
	int b[26]={0};//�����ÿ����ĸ��Ӧ�ĸ��� 
	int c[26]={26};//������������ͬ����ĸ�±� 
	for(i=0;i<len;i++){
		if((a[i]>='A')&&(a[i]<='Z')){
			a[i]+=32;
		}
		if((a[i]>='a')&&(a[i]<='z')){
			b[a[i]-'a']++;
		}
	}
	int max=0;
	for(i=0;i<26;i++){
		if(b[i]>max){
			max=b[i];
		}
	}
	
	for(i=0;i<26;i++){
		if(b[i]==max){
			c[j]=i;
			j++;
		}
	}
	int min=26;
	for(i=0;i<j;i++){
		if(c[i]<min){
			min=c[i];
		}
	}
	printf("%c %d",min+'a',max);
	return 0;
} 
