#include <stdio.h>
#include <string.h>
int main(){
	char a[50];
	char b[100000];
	//scanf("%s",a);��һ���ַ�������Ϊ�գ���û�л��� 
	int i=0,j=0;
	int NA=0;
	int NB=0;
	for(i=0;i<50;i++){
		scanf("%c",&a[i]);
		if(a[i]==10){//10�ǻ��е�asciiֵ 
			break;
		}
		NA++;
	}
	
	for(j=0;j<100000;j++){
		scanf("%c",&b[j]);
		if(b[j]==10){//10�ǻ��е�asciiֵ 
			break;
		}
		NB++;
	}
	
	if((i==1)&&(a[i-1]==10)){
		printf("%s",b);
		return 0;
	}
	
	for(j=0;j<NA;j++){
		if(a[j]=='+'){
			for(i=0;i<NB;i++){
				if(b[i]>='A'&&b[i]<='Z'){
					b[i]='&';
				}		
			}
		}else{
			for(i=0;i<NB;i++){
				//��δ��벻��if((b[i]==a[j])||(b[i]==(a[j]+32))){//ע����������b[i]==a[j]+32 
				if(b[i]==a[j]) 
					b[i]='&';
			
				if(b[i]>='a'&&b[i]<='z'){
					if(b[i]==(a[j]+32)){
						b[i]='&';
					}
				}
			}
			
		}
	}
	
	for(i=0;i<NB;i++){
		if(b[i]!='&'){
			printf("%c",b[i]);
		}	
	}
		
	return 0;
}
